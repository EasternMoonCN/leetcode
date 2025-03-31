#include "utils/common.cpp"

// 越少使用，越靠前
struct DeLinkNode {
    int key, val;
    
    // 为了快速删除节点位于中间时
    DeLinkNode* prev;
    DeLinkNode* next;

    DeLinkNode(int key, int val):key(key), val(val), prev(nullptr), next(nullptr) {};
};

class LRUCache {
public:
    int capacity;
    unordered_map<int, DeLinkNode*> linkMap;
    DeLinkNode* head;
    DeLinkNode* tail;
    DeLinkNode* dummy;
    LRUCache(int capacity) {
        this->capacity = capacity;
        // dummy节点
        dummy = new DeLinkNode(-1, -1);
        head = tail = dummy;
    }
    
    int get(int key) {
        DeLinkNode* node = linkMap[key];

        // 将node节点放到链表最后
        if (node) {
            if(node != tail) {
                // 断开node
                node->next->prev = node->prev;
                node->prev->next = node->next;
                // 将node添加到最后，更新tail
                tail->next = node;
                node->prev = tail;
                node->next = nullptr;
                tail = tail->next;
            }
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        DeLinkNode* node = linkMap[key];

        // node节点已存在
        if (node) {
            // 替换值
            node->val = value;
            // 需要将当前节点放到最后
            if(node != tail) {
                // 断开node
                node->next->prev = node->prev;
                node->prev->next = node->next;
                // 将node添加到最后，更新tail
                tail->next = node;
                node->prev = tail;
                node->next = nullptr;
                tail = tail->next;
            }

        } else {    // node节点不存在
            // 新建node节点
            node = new DeLinkNode(key, value);
            // 添加到map
            linkMap[key] = node;

            // 到达最大容量
            if (linkMap.size() > capacity) {
                // map中删除最少使用的元素
                linkMap.erase(head->key);

                // 新建节点添加到最后 
                tail->next = node;
                node->prev = tail;
                tail = tail->next;
                // 链表中删除最少使用的元素
                head = head->next;
                head->prev = dummy;
                
            } else {    // 没有达到最大容量
                // 添加链表到末尾
                tail->next = node;
                node->prev = tail;
                tail = tail->next;
                if (head == dummy) {
                    head = head->next;
                }
            }
        }
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
    // LRUCache* cache = new LRUCache(2);
    // cache->put(1, 1);
    // cache->put(2, 2);
    // cout << cache->get(1) << endl;
    // cache->put(3, 3);
    // cache->get(2);
    // cache->put(4, 4);
    // cout << cache->get(1) << endl;
    // cout << cache->get(3) << endl;
    // cout << cache->get(4) << endl;

    LRUCache* cache = new LRUCache(1);
    cache->put(2, 1);
    cout << cache->get(2) << endl;
    cache->put(3, 2);
    cout << cache->get(2) << endl;
    cout << cache->get(3) << endl;

}