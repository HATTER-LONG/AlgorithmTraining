#include <catch2/catch.hpp>
#include <glog/logging.h>

using namespace Catch;
using namespace std;

//貪心
/*
给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标。

输入：nums = [2,3,1,1,4]
输出：true
解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3
步到达最后一个下标。 贪心算法。

当前跳跃步骤能到达的最远点超过 size - 1
，即必然能到达数组末尾。因此维护一个能到达最远点的 rightpos ，当超过数组 size
时返回。
*/

bool canJump(vector<int>& nums)
{
    int size = nums.size();
    int rightpos = 0;
    for (int i = 0; i < size; i++)
    {
        if (i <= rightpos)
        {
            rightpos = max(rightpos, i + nums[i]);
            if (rightpos >= size)
                return true;
        }
    }
    return false;
}

TEST_CASE("Check Solution canJump method work successfully")
{
    vector<int> inputParm;

    bool resultParm;

    tie(inputParm, resultParm) = GENERATE(table<vector<int>, bool>({
        make_tuple(vector<int> { 2, 3, 1, 1, 4 }, true),
        make_tuple(vector<int> { 3, 2, 1, 0, 4 }, false),
    }));

    CAPTURE(inputParm, resultParm);
    REQUIRE(canJump(inputParm) == resultParm);
}
