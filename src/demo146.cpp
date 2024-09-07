//
// Created by EasternMoon on 2024/7/8.
//
#include "utils/common.h"

struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};


class LRUCache {
private:
    // 大小
    int size;
    // 容量
    int capacity;
    unordered_map<int, DLinkedNode*> data;
    // 头指针
    DLinkedNode* head;
    // 尾指针
    DLinkedNode* tail;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        // dummy节点
        head = new DLinkedNode();
        tail = new DLinkedNode();

        head->next = tail;
        tail->prev = head;
    }



    void headInsert(DLinkedNode* node) {
        node->next = head->next;
        node->prev = node->next->prev;
        node->next->prev = node;
        head->next = node;
        ++size;
    }

    void removeNode(DLinkedNode* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        node->next = nullptr;
        node->prev = nullptr;

        --size;
    }

    void moveHead(DLinkedNode* node) {
        removeNode(node);
        headInsert(node);
    }


    int get(int key) {
        if (data.count(key)) {
            auto node = data[key];
            // 移除节点，加入队头
            moveHead(node);
            return node->value;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (!data.count(key)) {
            if (size + 1 > capacity) {
                // 容量已满，移除队尾，移除hash表
                auto node = tail->prev;
                data.erase(node->key);
                removeNode(node);
                delete node;
            }
            auto newNode = new DLinkedNode(key, value);
            headInsert(newNode);
            data[key] = newNode;
        } else {
            auto node = data[key];
            node->value = value;
            moveHead(node);
        }

    }
};

int main() {
    int key1 = 1, val1 = 1;
    int key2 = 2, val2 = 2;
    int key3 = 3, val3 = 3;
    int key4 = 4, val4 = 4;
    auto* obj = new LRUCache(2);
    obj->put(key1,val1);
    obj->put(key2, val2);
    cout << obj->get(key1) << endl;
    obj->put(key3, val3);
    cout << obj->get(key2) << endl;
    obj->put(key4, val4);
    cout << obj->get(key1) << endl;
    cout << obj->get(key3) << endl;
    cout << obj->get(key4) << endl;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 /*
  struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};


class LRUCache {
private:
    // 大小
    int size;
    // 容量
    int capacity;
    unordered_map<int, DLinkedNode*> data;
    // 头指针
    DLinkedNode* head;
    // 尾指针
    DLinkedNode* tail;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        // dummy节点
        head = new DLinkedNode();
        tail = new DLinkedNode();

        head->next = tail;
        tail->prev = head;
    }

    void update(DLinkedNode* node) {
        auto prevNode = node->prev;
        // 删除节点
        node->next->prev = prevNode;
        prevNode->next = node->next;
        // 插入节点：头插法
        node->next = head->next;
        head->next = node;
        node->prev = head;
        node->next->prev = node;
    }

    void remove() {
        auto node = tail->prev;
        // 从队列中尾部删除
        auto prev = node->prev;
        prev->next = tail;
        tail->prev = prev;

        node->next = nullptr;
        node->prev = nullptr;

        // 从hash表中删除
        data.erase(node->key);
        --size;
        delete node;
    }

    void insert(int key, int val) {
        // 创建节点
        auto* node = new DLinkedNode(key, val);

        // 插入节点：头插法
        node->next = head->next;
        head->next = node;
        node->prev = head;
        node->next->prev = node;
        // 更新hash表
        data[key] = node;
        ++size;
    }

    int get(int key) {
        auto node = data[key];
        if (node) {
            // 移除节点，加入队头
            update(node);
            return node->value;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        int oldVal = get(key);
        if (oldVal == -1) {
            if (size + 1 > capacity) {
                // 容量已满，移除队尾，移除hash表
                remove();
            }
            insert(key, value);
        } else {
            auto node = data[key];
            node->value = value;
            update(node);
        }

    }
};
  */