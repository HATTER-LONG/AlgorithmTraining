#include <catch2/catch_all.hpp>
#include <unordered_map>
using namespace Catch;
using namespace std;

class Solution
{
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
    {
        unordered_map<int, int> umap;   // key: a+b 的值, value：a+b 出现的次数
        // 遍历 1 2 数组标识所有的结果放入 map
        for (auto a : nums1) {
            for (auto b : nums2) {
                umap[a + b]++;
            }
        }

        int count = 0;
        // 遍历 3 4 数组所有结果，在 map 中查找是否有相加为 0 的情况
        for (auto c : nums3) {
            for (auto d : nums4) {
                if (umap.find(0 - (c + d)) != umap.end()) {
                    count += umap[0 - (c + d)];
                }
            }
        }
        return count;
    }
};

TEST_CASE("Check Solution fourSumCount method work successfully")
{
    Solution solution;

    vector<int> param, param2, param3, param4;
    int result = 0;
    tie(param, param2, param3, param4, result) =
        GENERATE(table<vector<int>, vector<int>, vector<int>, vector<int>, int>({
            make_tuple(vector<int> { 1, 2 },
                       vector<int> { -2, -1 },
                       vector<int> { -1, 2 },
                       vector<int> { 0, 2 },
                       2),
            make_tuple(vector<int> { -1, -1 },
                       vector<int> { -1, 1 },
                       vector<int> { -1, 1 },
                       vector<int> { 1, -1 },
                       6),
        }));

    CAPTURE(param, param2, param3, param4, result);
    REQUIRE(solution.fourSumCount(param, param2, param3, param4) == result);
}
