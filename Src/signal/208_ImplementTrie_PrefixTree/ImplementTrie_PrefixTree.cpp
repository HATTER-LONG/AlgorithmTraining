#include <algorithm>
#include <catch2/catch.hpp>
#include <climits>
#include <cstddef>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace Catch;
using namespace std;

// 前缀树

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {}

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root = this;
        for(const auto& c : word) {
            if(root->next[c - 'a'] == nullptr) {
                root->next[c - 'a'] = new Trie();
            }
            root = root->next[c - 'a'];
        }
        root->is_string = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* root = this;
        for(const auto& w : word) {
            if(root->next[w - 'a'] == nullptr)
                return false;
            root = root->next[w - 'a'];
        }
        return root->is_string;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* root = this;
        for(const auto& p : prefix) {
            if(root->next[p - 'a'] == nullptr)
                return false;
            root = root->next[p - 'a'];
        }
        return true;
    }

private:
    Trie* next[26] = {nullptr};
    bool is_string = false;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
TEST_CASE("Check Trie method work successfully") {
    Trie trie;
    string insert;
    string search;
    string startsWith;
    bool result;
    tie(insert, search, startsWith, result) = GENERATE(table<string, string, string, bool>({
        make_tuple("apple", "apple", "", true),
        make_tuple("apple", "app", "", false),
        make_tuple("apple", "", "app", true),
        make_tuple("app", "app", "", true),
    }));
    trie.insert(insert);
    bool resultGet = false;
    if(search != "") {
        resultGet = trie.search(search);
    } else {
        resultGet = trie.startsWith(startsWith);
    }
    REQUIRE(resultGet == result);
}