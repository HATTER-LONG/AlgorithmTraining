#include <algorithm>
#include <catch2/catch.hpp>
#include <climits>
#include <cstddef>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace Catch;
using namespace std;

class MinStack {
    stack<int> x_stack;
    stack<int> min_stack;

public:
    MinStack() { min_stack.push(INT_MAX); }

    void push(int x) {
        x_stack.push(x);
        min_stack.push(min(min_stack.top(), x));
    }

    void pop() {
        x_stack.pop();
        min_stack.pop();
    }

    int top() { return x_stack.top(); }

    int getMin() { return min_stack.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

TEST_CASE("Check Solution maxProduct method work successfully") {
    vector<string> inputParm;
    vector<vector<int>> inputParm2;
    vector<int> result;

    tie(inputParm, inputParm2, result) =
        GENERATE(table<vector<string>, vector<vector<int>>, vector<int>>({
            make_tuple(vector<string>{"MinStack", "push", "push", "push", "getMin", "pop", "top",
                                      "getMin"},
                       vector<vector<int>>{{}, {-2}, {0}, {-3}, {}, {}, {}, {}},
                       vector<int>{INT_MAX, INT_MAX, INT_MAX, INT_MAX, -3, INT_MAX, 0, -2}),
        }));

    MinStack* obj = new MinStack();
    for(size_t i = 0; i < inputParm.size(); i++) {
        if(inputParm[i] == "MinStack") {
        } else if(inputParm[i] == "push") {
            obj->push(inputParm2[i][0]);
        } else if(inputParm[i] == "getMin") {
            REQUIRE(obj->getMin() == (result[i]));
        } else if(inputParm[i] == "pop") {
            obj->pop();
        } else if(inputParm[i] == "top") {
            REQUIRE(obj->top() == (result[i]));
        }
    }
}