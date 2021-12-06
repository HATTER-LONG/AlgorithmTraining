#include "Tools/Tools.hpp"

void mergeSort(vector<int>& nums, int l, int r, vector<int>& temp)
{
    if (l + 1 >= r)
        return;
    // divide
    int m = l + (r - l) / 2;
    mergeSort(nums, l, m, temp);
    mergeSort(nums, m, r, temp);

    // conquer
    int p = l, q = m, i = l;
    while (p < m || q < r)
    {
        if (q >= r || (p < m && nums[p] <= nums[q]))
        {
            temp[i++] = nums[p++];
        }
        else
        {
            temp[i++] = nums[q++];
        }
    }
    for (i = l; i < r; i++)
    {
        nums[i] = temp[i];
    }
}

//[0, 1, 5, 0, 0, 0]
//[1, 2, 5, 0, 0, 0]
//[1, 2, 5, 0, 3, 6]
//[1, 2, 5, 3, 4, 6]
//[1, 2, 3, 4, 5, 6]

TEST_CASE("test merge sort")
{
    VecInt input;
    int l, r;

    VecInt result;

    tie(input, l, r, result) =
        GENERATE(table<VecInt, int, int, VecInt>({ make_tuple(
            VecInt { 2, 1, 5, 4, 6, 3 }, 0, 6, VecInt { 1, 2, 3, 4, 5, 6 }) }));

    CAPTURE(input, l, r, result);
    VecInt temp(input.size());
    mergeSort(input, l, r, temp);
    REQUIRE_THAT(input, Catch::Equals(result));
}
