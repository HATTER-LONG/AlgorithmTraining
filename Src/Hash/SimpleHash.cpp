#include "Tools/Tools.hpp"

#include <list>
int myHash(const int& key, const int& tableSize) { return key % tableSize; }

template <typename T> class HashTable {
public:
    HashTable(int size = 31) {
        m_hashTable.reserve(size);
        m_hashTable.resize(size);
    }
    ~HashTable() = default;

    bool contains(const T& obj) {
        const list<T>& slot = m_hashTable[hash(obj)];
        auto it = slot.cbegin();
        for(; it != slot.cend() && *it != obj; ++it)
            ;

        return it != slot.cend();
    }
    bool insert(const T& obj) {
        if(contains(obj)) {
            return false;
        }
        m_hashTable[hash(obj)].push_front(obj);
        return true;
    }

    bool remove(const T& obj) {
        list<T>& slot = m_hashTable[hash(obj)];
        auto it = find(slot.begin(), slot.end(), obj);
        if(it == slot.end()) {
            return false;
        }
        slot.erase(it);
        return true;
    }

private:
    vector<list<T>> m_hashTable;
    int hash(const T& obj) const { return myHash(obj, m_hashTable.size()); }
};
