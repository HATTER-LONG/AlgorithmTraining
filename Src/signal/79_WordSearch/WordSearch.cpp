#include <catch2/catch.hpp>
#include <cstddef>
#include <cstdint>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace Catch;
using namespace std;

// DFS

// 高级版本 加上了记忆以访问的
class Solution {
public:
    bool check(
        vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, string& s, int k) {
        if(board[i][j] != s[k]) {
            return false;
        }
        if(k == static_cast<int>(s.length() - 1)) {
            return true;
        }
        visited[i][j] = true;
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool result = false;
        for(const auto& dir : directions) {
            int newi = i + dir.first, newj = j + dir.second;
            if(newi >= 0 && newi < static_cast<int>(board.size()) && newj >= 0 &&
               newj < static_cast<int>(board[0].size())) {
                if(!visited[newi][newj]) {
                    bool flag = check(board, visited, newi, newj, s, k + 1);
                    if(flag) {
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        vector<vector<int>> visited(h, vector<int>(w));
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                bool flag = check(board, visited, i, j, word, 0);
                if(flag) {
                    return true;
                }
            }
        }
        return false;
    }
};

// 貌似哪里 -1 越界访问了
class Solution_Mine {
    enum PREPOS { NONE = 0, TOP, RIGHT, LEFT, DOWN };

public:
    bool
    dfs(const vector<vector<char>>& board, size_t posx, size_t posy, PREPOS prepos, size_t keypos) {
        if(keypos < m_keyWord.length() && board[posy][posx] == m_keyWord[keypos]) {
            m_word += m_keyWord[keypos];
        } else {
            return false;
        }
        if(m_word == m_keyWord) {
            return true;
        }
        if(posx + 1 < m_xSize && prepos != RIGHT && dfs(board, posx + 1, posy, LEFT, keypos + 1)) {
            return true;
        }
        if(posx >= 1 && prepos != LEFT && dfs(board, posx - 1, posy, RIGHT, keypos + 1)) {
            return true;
        }
        if(posy + 1 < m_ySize && prepos != DOWN && dfs(board, posx, posy + 1, TOP, keypos + 1)) {
            return true;
        }
        if(posy >= 1 && prepos != TOP && dfs(board, posx, posy - 1, DOWN, keypos + 1)) {
            return true;
        }
        if(m_word.length() > 0)
            m_word.erase(m_word.length() - 1);
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m_keyWord = word;
        m_xSize = board[0].size();
        m_ySize = board.size();

        for(size_t i = 0; i < m_ySize; i++) {
            for(size_t j = 0; j < m_xSize; j++) {
                if(board[i][j] == word[0] && dfs(board, j, i, NONE, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    string m_word;
    string m_keyWord;
    size_t m_xSize;
    size_t m_ySize;
};

TEST_CASE("Check Solution exist method work successfully") {
    Solution solution;

    vector<vector<char>> inputParm;
    string keyword;
    bool resultParm = false;
    tie(inputParm, keyword, resultParm) = GENERATE(table<vector<vector<char>>, string, bool>({
        make_tuple(
            vector<vector<char>>{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}},
            "ABCCED", true),
        make_tuple(
            vector<vector<char>>{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}},
            "SEE", true),
    }));

    CAPTURE(inputParm, keyword, resultParm);

    REQUIRE(solution.exist(inputParm, keyword) == resultParm);
}