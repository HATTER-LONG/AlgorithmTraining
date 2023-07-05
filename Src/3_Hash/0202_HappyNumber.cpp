#include <catch2/catch_all.hpp>
#include <unordered_set>
using namespace Catch;
using namespace std;

class Solution
{
public:
    int getSum(int n)
    {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        unordered_set<int> set;
        while (1) {
            int sum = getSum(n);
            if (sum == 1)
                return true;
            if (set.find(sum) != set.end())
                return false;
            set.insert(sum);

            n = sum;
        }
    }
};

TEST_CASE("Check Solution isHappy method work successfully")
{
    Solution solution;

    int param = 0;
    bool result = false;
    tie(param, result) = GENERATE(table<int, bool>({
        make_tuple(19, true),
        make_tuple(2, false),
    }));

    CAPTURE(param, result);
    REQUIRE(solution.isHappy(param) == result);
}
