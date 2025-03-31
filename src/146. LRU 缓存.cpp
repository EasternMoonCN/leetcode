#include "utils/common.cpp"

// 越少使用，越靠后
struct DeLinkNode {
    int key, val;
    
    // 为了快速删除节点位于中间时
    DeLinkNode* prev;
    DeLinkNode* next;

    DeLinkNode(int key, int val):key(key), val(val), prev(nullptr), next(nullptr) {};
};

class LRUCache {
public:
    int size;
    int capacity;
    // 用于快速查找链表节点
    unordered_map<int, DeLinkNode*> cache;
    // 双向链表：头节点为最新使用
    DeLinkNode* head;
    DeLinkNode* tail;
    LRUCache(int capacity): capacity(capacity), size(0) {
        // dummy节点
        head = new DeLinkNode(-1, -1);
        tail = new DeLinkNode(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        DeLinkNode* node = cache[key];
        moveToHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            DeLinkNode* node = cache[key];
            node->val = value;
            moveToHead(node);
        } else {
            DeLinkNode* node = new DeLinkNode(key, value);
            cache[key] = node;
            addToHead(node);
            if (size == capacity) {
                cache.erase(tail->prev->key);
                removeTail();
            } else {
                ++size;
            }
        }
    }
    void removeTail() {
        DeLinkNode* node = tail->prev;
        removeNode(node);
        delete node;
    }

    void removeNode(DeLinkNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(DeLinkNode* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    void moveToHead(DeLinkNode* node) {
        removeNode(node);
        addToHead(node);
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 * 
 * ["LRUCache","put","put","get","put","get","put","get","get","get"]
 * [[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
 */


int main () {
    LRUCache* cache = new LRUCache(2);
    cache->put(1, 1);
    cache->put(2, 2);
    cout << cache->get(1) << endl;
    cache->put(3, 3);
    cache->get(2);
    cache->put(4, 4);
    cout << cache->get(1) << endl;
    cout << cache->get(3) << endl;
    cout << cache->get(4) << endl;

    // LRUCache* cache = new LRUCache(1);
    // cache->put(2, 1);
    // cout << cache->get(2) << endl;
    // cache->put(3, 2);
    // cout << cache->get(2) << endl;
    // cout << cache->get(3) << endl;

}