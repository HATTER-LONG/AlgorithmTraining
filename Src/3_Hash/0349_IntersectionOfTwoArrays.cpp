#include <catch2/catch_all.hpp>
#include <unordered_set>
using namespace Catch;
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;
        unordered_set<int> numb1Set(nums1.begin(), nums1.end());

        for(auto& num : nums2) {
            if(numb1Set.find(num) != numb1Set.end()) {
                result.insert(num);
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};

TEST_CASE("Check Solution intersection method work successfully") {
    Solution solution;

    vector<int> param, param2, result;
    tie(param, param2, result) = GENERATE(table<vector<int>, vector<int>, vector<int>>({
        make_tuple(vector<int>{1, 2, 2, 1}, vector<int>{2, 2}, vector<int>{2}),
    }));

    CAPTURE(param, param2, result);
    REQUIRE_THAT(solution.intersection(param, param2), Matchers::Equals(result));
}
