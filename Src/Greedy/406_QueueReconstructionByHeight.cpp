#include <catch2/catch.hpp>
#include <glog/logging.h>

using namespace std;

/*
 * 假设有打乱顺序的一群人站成一个队列，
 * 数组 people 表示队列中一些人的属性（不一定按顺序）。
 * 每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，
 * 前面正好有 ki 个身高大于或等于 hi 的人。
 *
 * 请你重新构造并返回输入数组 people 所表示的队列。
 * 返回的队列应该格式化为数组 queue ，
 * 其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性
 * （queue[0] 是排在队列前面的人）。
 *
 *  
 *
 * 示例 1：
 *
 * 输入：people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
 * 输出：[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
 * 解释：
 * 编号为 0 的人身高为 5 ，没有身高更高或者相同的人排在他前面。
 * 编号为 1 的人身高为 7 ，没有身高更高或者相同的人排在他前面。
 * 编号为 2 的人身高为 5 ，有 2 个身高更高或者相同的人排在他前面，
 * 即编号为 0 和 1 的人。
 * 编号为 3 的人身高为 6 ，有 1 个身高更高或者相同的人排在他前面，
 * 即编号为 1 的人。
 * 编号为 4 的人身高为 4 ，有 4 个身高更高或者相同的人排在他前面，
 * 即编号为 0、1、2、3 的人。
 * 编号为 5 的人身高为 7 ，有 1 个身高更高或者相同的人排在他前面，
 * 即编号为 1 的人。 因此
 * [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] 是重新构造后的队列。
 *
 */

vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
{
    int size = people.size();
    vector<vector<int>> ans;

    sort(people.begin(), people.end(),
        [](vector<int>& a, vector<int>& b)
        {
            return a[0] > b[0]
                   || (a[0] == b[0]
                       && a[1] < b[1]);   // 身高从高到低排序，相同则 K 排序
        });
    for (const vector<int>& person : people)
    {
        if (ans.size() <= static_cast<size_t>(person[1]))
        {
            ans.push_back(person);
        }
        else
        {
            ans.insert(ans.begin() + person[1], person);
        }
    }
    return ans;
}

TEST_CASE("test reconstruct queue")
{
    vector<vector<int>> people;
    vector<vector<int>> result;


    tie(people, result) =
        GENERATE(table<vector<vector<int>>, vector<vector<int>>>(
            { make_tuple(vector<vector<int>> { { 7, 0 }, { 4, 4 }, { 7, 1 },
                             { 5, 0 }, { 6, 1 }, { 5, 2 } },
                vector<vector<int>> { { 5, 0 }, { 7, 0 }, { 5, 2 }, { 6, 1 },
                    { 4, 4 }, { 7, 1 } }) }));
    REQUIRE_THAT(reconstructQueue(people), Catch::Equals(result));
}
