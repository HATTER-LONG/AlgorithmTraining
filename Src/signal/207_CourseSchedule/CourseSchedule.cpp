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

// 图-拓扑排序

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        inedeg.resize(numCourses);
        for(const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
            ++inedeg[info[0]];
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(inedeg[i] == 0) {
                q.push(i);
            }
        }

        int visited = 0;
        while(!q.empty()) {
            ++visited;
            int u = q.front();
            q.pop();
            for(int v : edges[u]) {
                --inedeg[v];
                if(inedeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        return visited == numCourses;
    }

private:
    vector<vector<int>> edges;
    vector<int> inedeg;
};

TEST_CASE("Check Solution canFinish method work successfully") {
    Solution solution;
    int numCourses = 0;
    vector<vector<int>> inputParmA;
    bool result;
    tie(numCourses, inputParmA, result) = GENERATE(table<int, vector<vector<int>>, bool>({
        make_tuple(2, vector<vector<int>>{{1, 0}}, true),
        make_tuple(2, vector<vector<int>>{{1, 0}, {0, 1}}, false),
    }));

    REQUIRE(solution.canFinish(numCourses, inputParmA) == result);
}