#include <Catch2/catch.hpp>
#include <vector>
/*
 * 题目描述
 * 有一群孩子和一堆饼干，每个孩子有一个饥饿度，每个饼干都有一个大小。
 * 每个孩子只能吃一个饼干，且只有饼干的大小不小于孩子的饥饿度时，
 * 这个孩子才能吃饱。
 * 求解最多有多少孩子 可以吃饱。
 *
 * 输入输出样例输入两个数组，分别代表孩子的饥饿度和饼干的大小。
 * 输出最多有多少孩子可以吃饱的数量。
 * Input: [1,2], [1,2,3]
 * Output: 2
 * 在这个样例中，我们可以给两个孩子喂 [1,2]、[1,3]、[2,3] 这三种组合的任意一种。
 */

int findContentChildren(std::vector<int>& children, std::vector<int>& cookies) {
    sort(children.begin(), children.end());
    sort(cookies.begin(), cookies.end());

    int child = 0, cookie = 0;
    while(child < static_cast<int>(children.size()) && cookie < static_cast<int>(cookies.size())) {
        if(children[child] <= cookies[cookie])
            ++child;
        ++cookie;
    }
    return child;
}

TEST_CASE("Test find content children") {
    std::vector<int> children{1, 2};
    std::vector<int> cookies{1, 2, 3};
    int result = 2;
    REQUIRE(findContentChildren(children, cookies) == result);
}
