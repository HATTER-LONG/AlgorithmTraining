#include <catch2/catch.hpp>
#include <glog/logging.h>
#include <map>
using namespace std;

/*
 * 题目描述
 *   在一个增序的整数数组里找到两个数，使它们的和为给定值。已知有且只有一对解。
 *
 * 输入输出样例
 *   输入是一个数组(numbers)和一个给定值(target)。
 *   输出是两个数的位置，从 1 开始计数。
 *
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 *
 * 在这个样例中，第一个数字(2)和第二个数字(7)的和等于给定值(9)。
 */


vector<int> twoSum(vector<int>& numbers, int target)
{
    int l = 0, r = numbers.size() - 1;
    while (l < r)
    {
        int sum = numbers[l] + numbers[r];
        if (sum == target)
        {
            break;
        }

        if (sum < target)
            l++;
        else
            r--;
    }
    return { l + 1, r + 1 };
}
vector<int> twoSumWithMap(vector<int>& numbers, int target)
{
    int size = numbers.size();

    vector<int> pos;
    map<int, int> alreadyGet;
    for (int i = 0; i < size; i++)
    {
        int need = target - numbers[i];
        auto iter = alreadyGet.find(need);
        if (iter == alreadyGet.end())
        {
            alreadyGet[numbers[i]] = i;
        }
        else
        {
            pos.push_back(iter->second + 1);
            pos.push_back(i + 1);
        }
    }

    return pos;
}

TEST_CASE("test two sum func")
{
    vector<int> input;
    int target;

    vector<int> result;

    tie(input, target, result) = GENERATE(table<vector<int>, int, vector<int>>(
        { make_tuple(vector<int> { 2, 7, 11, 15 }, 9, vector<int> { 1, 2 }) }));
    REQUIRE_THAT(twoSum(input, target), Catch::Equals(result));
}
