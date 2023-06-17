#include <catch2/catch.hpp>
#include <cstddef>
#include <cstdint>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

using namespace Catch;
using namespace std;

//最终优化版本
class Solution
{
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int n = heights.size();
        vector<int> left(n), right(n, n);

        stack<int> mono_stack;
        for (int i = 0; i < n; ++i)
        {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i])
            {
                right[mono_stack.top()] = i;   //通过这一个 循环更新掉 right 边界
                mono_stack.pop();
            }
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
            mono_stack.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};

// 栈队列
// 将一个柱体的数据存入栈表示当前还不能确认这个位置最大的矩形，出栈时表示能计算出这个位置最大的矩形
// 看到的元素高度严格小于栈顶元素，栈顶元素出栈
// 出栈时有三种特殊情况：
// 1. 都遍历完成后栈顶元素出栈时一定能扩散到数组末尾，因为右边肯定没有比当前栈顶小的。
// 2. 当栈顶出栈时，栈内为空那么其能扩散到数组两端，此为数组中最小的。
// 3. 栈中存在高度相等的元素。需要对其特殊处理
//
class Solution_Stack
{
public:
    int largestRectangleArea(vector<int>& heights)
    {
        size_t n = heights.size();
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return heights[0];
        }
        vector<int> left(n), right(n);
        int ans = 0;
        stack<int> lstack;
        for (int i = 0; i < static_cast<int>(n); i++)   // 计算左边
        {
            while (!lstack.empty() && heights[lstack.top()] >= heights[i])   //等于是为了避免连续高相等的柱体
            {
                lstack.pop();
            }
            left[i] = (lstack.empty() ? -1 : lstack.top());
            lstack.push(i);
        }
        lstack = stack<int>();
        for (int i = static_cast<int>(n - 1); i >= 0; i--)
        {
            while (!lstack.empty() && heights[lstack.top()] >= heights[i])
            {
                lstack.pop();
            }
            right[i] = (lstack.empty() ? n : lstack.top());
            lstack.push(i);
        }
        for (size_t i = 0; i < n; i++)
        {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};


// 暴力
class Solution_Crash
{
public:
    int findNextPos(vector<int>& heights, size_t beginPos)
    {
        int pos = beginPos;
        while (pos < static_cast<int>(heights.size()))
        {
            if (heights[pos] < heights[beginPos])
            {
                break;
            }
            pos++;
        }
        return --pos;
    }
    int findPrePos(vector<int>& heights, size_t beginPos)
    {
        int pos = beginPos;
        while (pos >= 0)
        {
            if (heights[pos] < heights[beginPos])
            {
                break;
            }
            pos--;
        }
        return ++pos;
    }
    int largestRectangleArea(vector<int>& heights)
    {
        size_t n = heights.size();
        int ans = 0;
        for (size_t i = 0; i < n; i++)
        {
            int height = heights[i];
            ans = max(ans, (findNextPos(heights, i) - findPrePos(heights, i) + 1) * height);
        }

        return ans;
    }
};

TEST_CASE("Check Solution largestRectangleArea method work successfully")
{
    Solution solution;

    vector<int> inputParm;
    int resultParm = 0;
    tie(inputParm, resultParm) = GENERATE(table<vector<int>, int>({
        make_tuple(vector<int> { 2, 1, 5, 6, 2, 3 }, 10),
    }));

    CAPTURE(inputParm, resultParm);

    REQUIRE(solution.largestRectangleArea(inputParm) == resultParm);
}