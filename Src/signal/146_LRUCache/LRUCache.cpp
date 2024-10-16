#include "Tools/ListNodeTools.h"

#include <algorithm>
#include <catch2/catch.hpp>
#include <climits>
#include <cstddef>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace Catch;
using namespace std;

// 双向链表操作

struct DLinkedNode {
    int key, value;
    DLinkedNode* pre;
    DLinkedNode* next;
    DLinkedNode() : key(0), value(0), pre(nullptr), next(nullptr) {}
    DLinkedNode(int Key, int Value) : key(Key), value(Value), pre(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> m_cache;
    DLinkedNode* m_head;
    DLinkedNode* m_tail;
    int m_capacity;
    int m_size;

public:
    LRUCache(int capacity)
        : m_capacity(capacity), m_size(0)

    {
        // 使用伪头尾节点

        m_head = new DLinkedNode();
        m_tail = new DLinkedNode();
        m_head->next = m_tail;
        m_tail->pre = m_head;
    }

    int get(int key) {
        if(!m_cache.count(key)) {
            return -1;
        }
        // 如果 key 存在，先通过哈希表定位，再移动到头部。
        DLinkedNode* node = m_cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if(!m_cache.count(key)) {
            // 如果 key 不存在，创建一个新的节点
            DLinkedNode* node = new DLinkedNode(key, value);
            // 添加进入哈希表
            m_cache[key] = node;
            // 添加至双链表头部
            addToHead(node);
            m_size++;
            if(m_size > m_capacity) {
                // 超出容量，删除双向链表的尾部节点
                DLinkedNode* removed = removeTail();
                // 删除哈希表中对应的项
                m_cache.erase(removed->key);
                // 防止内存泄漏
                delete removed;
                --m_size;
            }
        } else {
            // 如果 key 存在，想通过哈希表定位，再修改 value，并移到头部
            DLinkedNode* node = m_cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node) {
        node->pre = m_head;
        node->next = m_head->next;
        m_head->next->pre = node;
        m_head->next = node;
    }

    void removeNode(DLinkedNode* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = m_tail->pre;
        removeNode(node);
        return node;
    }
};

TEST_CASE("Check Solution LRUCache method work successfully") {
    vector<string> inputParm;
    vector<vector<int>> inputParm2;
    vector<int> result;

    tie(inputParm, inputParm2, result) =
        GENERATE(table<vector<string>, vector<vector<int>>, vector<int>>({
            make_tuple(
                vector<string>{"LRUCache", "put", "put", "get", "put", "get", "put", "get", "get",
                               "get"},
                vector<vector<int>>{{2}, {1, 1}, {2, 2}, {1}, {3, 3}, {2}, {4, 4}, {1}, {3}, {4}},
                vector<int>{INT_MAX, INT_MAX, INT_MAX, 1, INT_MAX, -1, INT_MAX, -1, 3, 4}),
        }));

    LRUCache* obj = nullptr;
    for(size_t i = 0; i < inputParm.size(); i++) {
        if(inputParm[i] == "LRUCache") {
            obj = new LRUCache(inputParm2[i][0]);
        } else if(inputParm[i] == "put") {
            obj->put(inputParm2[i][0], inputParm2[i][1]);
        } else if(inputParm[i] == "get") {
            REQUIRE(obj->get(inputParm2[i][0]) == (result[i]));
        }
    }
}