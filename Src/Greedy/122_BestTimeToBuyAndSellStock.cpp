#include "Tools/Tools.hpp"

#include <tuple>

/*
 * 给定一个数组 prices ，其中 prices[i] 是一支给定股票第 i 天的价格。
 *
 * 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
 *
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 *
 * 示例 1:
 *
 * 输入: prices = [7,1,5,3,6,4]
 * 输出: 7
 * 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 =
 * 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。 随后，在第 4 天（股票价格 =
 * 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 =
 * 6-3 = 3 。
 *
 * 示例 2:
 *
 * 输入: prices = [1,2,3,4,5]
 * 输出: 4
 * 解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 =
 * 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。 注意你不能在第 1 天和第 2
 * 天接连购买股票，之后再将它们卖出。
 * 因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
 */

int maxProfit(vector<int>& prices)
{
    int s = prices.size();
    if (s == 0)
        return 0;

    int res = 0;
    for (int i = 1; i < s; i++)
    {
        if (prices[i] > prices[i - 1])
        {
            res += prices[i] - prices[i - 1];
        }
    }
    return res;
}

TEST_CASE("test maxProfit")
{
    VecInt input;
    int res;

    tie(input, res) = GENERATE(
        table<VecInt, int>({ make_tuple(VecInt { 7, 1, 5, 3, 6, 4 }, 7),
            make_tuple(VecInt { 1, 2, 3, 4, 5 }, 4) }));

    CAPTURE(input, res);
    REQUIRE(maxProfit(input) == res);
}
