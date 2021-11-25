#include "Tools/Tools.hpp"

#include <stack>
#include <tuple>

/*
题目描述
给定每天的温度，求对于每一天需要等几天才可以等到更暖和的一天。如果该天之后不存在
更暖和的天气，则记为 0。

输入输出样例
输入是一个一维整数数组，输出是同样长度的整数数组，表示对于每天需要等待多少天。

Input: [73, 74, 75, 71, 69, 72, 76, 73]
Output: [1, 1, 4, 2, 1, 1, 0, 0]
*/


vector<int> dailyTemperatures(vector<int>& temperatures)
{
    int n = temperatures.size();
    stack<int> st;
    vector<int> result(n, 0);
    st.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && temperatures[i] > temperatures[st.top()])
        {
            result[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    return result;
}

TEST_CASE("test daily temperatures")
{
    VecInt input;
    VecInt res;

    tie(input, res) = GENERATE(table<VecInt, VecInt>(
        { make_tuple(VecInt { 73, 74, 75, 71, 69, 72, 76, 73 },
            VecInt { 1, 1, 4, 2, 1, 1, 0, 0 }) }));
    REQUIRE_THAT(dailyTemperatures(input), Catch::Equals(res));
}
