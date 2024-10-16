#include "Tools/Tools.hpp"

#include <tuple>

/*
 * 题目描述
 *   给定一个非负整数，求它的开方，向下取整。
 *
 * 输入输出样例
 *   输入一个整数，输出一个整数。
 *
 * Input: 8
 * Output: 2
 * 8 的开方结果是 2.82842...，向下取整即是 2。
 */

int mySqrt2(int a) {
    long x = a;
    while(x * x > a) {
        x = (x + a / x) / 2;
    }
    return x;
}

int mySqrt(int a) {
    if(a == 0)
        return 0;
    int l = 1, r = a, mid, sqrtl = 0;
    while(l <= r) {
        mid = l + (r - l) / 2;
        sqrtl = a / mid;
        if(sqrtl == mid)
            return mid;
        if(mid > sqrtl)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return r;
}

TEST_CASE() {
    int input;
    int result;

    tie(input, result) = GENERATE(table<int, int>({make_tuple(8, 2)}));
    CAPTURE(input, result);
    REQUIRE(mySqrt(input) == result);
}
