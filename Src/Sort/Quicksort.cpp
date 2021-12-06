#include "Tools/Tools.hpp"

void quickSort(vector<int>& nums, int l, int r)   // NOLINT
{
    if (l + 1 >= r)
    {
        return;
    }
    int first = l, last = r - 1, key = nums[first];
    while (first < last)
    {
        while (first < last && nums[last] >= key)
        {
            --last;
        }
        nums[first] = nums[last];

        while (first < last && nums[first] <= key)
        {
            ++first;
        }
        nums[last] = nums[first];
    }
    nums[first] = key;
    quickSort(nums, l, first);
    quickSort(nums, first + 1, r);
}
// [2, 1, 5, 4, 6, 3]
// [1, 2, 5, 4, 6, 3]
// [1, 2, 3, 4, 5, 6]
// [1, 2, 3, 4, 5, 6]
TEST_CASE("test quick sort")
{
    VecInt input;
    int l, r;

    VecInt result;

    tie(input, l, r, result) =
        GENERATE(table<VecInt, int, int, VecInt>({ make_tuple(
            VecInt { 2, 1, 5, 4, 6, 3 }, 0, 6, VecInt { 1, 2, 3, 4, 5, 6 }) }));

    CAPTURE(input, l, r, result);
    quickSort(input, l, r);
    REQUIRE_THAT(input, Catch::Equals(result));
}
