#include "Tools/Tools.hpp"

void insertionSort(vector<int>& nums, size_t n) {
    for(size_t i = 0; i < n; ++i) {
        for(int j = i; j > 0 && nums[j] < nums[j - 1]; --j) {
            swap(nums[j], nums[j - 1]);
            ToolBox<int> a;
            LOG(INFO) << a.transVector2String(nums);
        }
    }
}

// [1, 2, 5, 4, 6, 3]
// [1, 2, 4, 5, 6, 3]
// [1, 2, 4, 5, 3, 6]
// [1, 2, 4, 3, 5, 6]
// [1, 2, 3, 4, 5, 6]

TEST_CASE("test inser sort") {
    VecInt input;

    VecInt result;

    tie(input, result) = GENERATE(
        table<VecInt, VecInt>({make_tuple(VecInt{2, 1, 5, 4, 6, 3}, VecInt{1, 2, 3, 4, 5, 6})}));

    CAPTURE(input, result);
    insertionSort(input, input.size());
    REQUIRE_THAT(input, Catch::Equals(result));
}
