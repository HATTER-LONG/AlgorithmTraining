#include <catch2/catch.hpp>
#include <glog/logging.h>
#include <tuple>
using namespace std;
/*
在二维空间中有许多球形的气球。
对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。
由于它是水平的，所以纵坐标并不重要，因此只要知道开始和结束的横坐标就足够了。
开始坐标总是小于结束坐标。

一支弓箭可以沿着 x 轴从不同点完全垂直地射出。
在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend，
且满足 xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。
弓箭一旦被射出之后，可以无限地前进。
我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。

给你一个数组 points ，其中 points [i] = [xstart,xend]，
返回引爆所有气球所必须射出的最小弓箭数。

示例 1：

输入：points = [[10,16],[2,8],[1,6],[7,12]]
输出：2
解释：对于该样例，x = 6 可以射爆 [2,8],[1,6] 两个气球，以及 x = 11
射爆另外两个气球 示例 2：

输入：points = [[1,2],[3,4],[5,6],[7,8]]
输出：4
*/
using namespace std;
int findMinArrowShots(std::vector<std::vector<int>>& points)
{
    int s = points.size();
    if (s == 0)
    {
        return 0;
    }
    sort(points.begin(), points.end(),
        [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
    int cur = 0, count = 0;
    for (int i = 1; i < s; i++)
    {
        if (points[i][0] > points[cur][1])
        {
            count++;
            cur = i;
        }
    }
    return count;
}


TEST_CASE("test find min arrow shots func")
{
    std::vector<std::vector<int>> points {};
    vector<vector<int>> list;
    int resultParm;
    tie(list, resultParm) = GENERATE(table<vector<vector<int>>, int>(
        { make_tuple(
              vector<vector<int>> { { 10, 16 }, { 2, 8 }, { 1, 6 }, { 7, 12 } },
              2),
            make_tuple(
                vector<vector<int>> { { 1, 2 }, { 3, 4 }, { 4, 5 }, { 6, 7 } },
                3),
            make_tuple(vector<vector<int>> { { 3, 9 }, { 7, 12 }, { 3, 8 },
                           { 6, 8 }, { 9, 10 }, { 2, 9 }, { 0, 9 }, { 3, 9 },
                           { 0, 6 }, { 2, 8 } },
                2) }));


    REQUIRE(findMinArrowShots(list) == resultParm);
}
