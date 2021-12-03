# LeetCode 算法刷题

<!-- PROJECT SHIELDS -->

![Contributors][build-url]
[![Contributors][contributors-shield]][contributors-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]

<!--[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![LinkedIn][linkedin-shield]][linkedin-url]-->
<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->

[contributors-shield]: https://img.shields.io/github/contributors/HATTER-LONG/AlgorithmTraining.svg?style=flat
[contributors-url]: https://github.com/HATTER-LONG/AlgorithmTraining/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/HATTER-LONG/AlgorithmTraining.svg?style=flat
[forks-url]: https://github.com/HATTER-LONG/AlgorithmTraining/network/members
[stars-shield]: https://img.shields.io/github/stars/HATTER-LONG/AlgorithmTraining.svg?style=flat
[stars-url]: https://github.com/HATTER-LONG/AlgorithmTraining/stargazers
[issues-shield]: https://img.shields.io/github/issues/HATTER-LONG/AlgorithmTraining.svg?style=flat
[issues-url]: https://github.com/HATTER-LONG/AlgorithmTraining/issues
[license-shield]: https://img.shields.io/github/license/HATTER-LONG/AlgorithmTraining?style=flat
[license-url]: https://github.com/HATTER-LONG/AlgorithmTraining/blob/master/LICENSE
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=flat&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/othneildrew
[build-url]: https://github.com/HATTER-LONG/AlgorithmTraining/workflows/CMake/badge.svg?style=flat

- [LeetCode 算法刷题](#leetcode-算法刷题)
  - [Greedy 贪心算法](#greedy-贪心算法)
    - [455_AssignCookie](#455_assigncookie)
    - [135_Candy](#135_candy)
    - [435_Non-overlappingIntervals](#435_non-overlappingintervals)
    - [605_CanPlaceFlowers](#605_canplaceflowers)
    - [452_MinimumNumberOfArrowsToBurstBalloons](#452_minimumnumberofarrowstoburstballoons)
    - [763_PartitionLabels](#763_partitionlabels)
    - [122_BestTimeToBuyAndSellStockII](#122_besttimetobuyandsellstockii)
    - [406_QueueReconstructionByHeight](#406_queuereconstructionbyheight)
    - [665_Non-decreasingArray](#665_non-decreasingarray)
  - [DoublePointer 双指针](#doublepointer-双指针)
    - [167_TwoSumII](#167_twosumii)
    - [88_MergeSortedArray](#88_mergesortedarray)
    - [142_LinkedListCycleII](#142_linkedlistcycleii)
    - [76_MinimumWindwSubstring](#76_minimumwindwsubstring)
    - [633_SumOfSquareNumbers](#633_sumofsquarenumbers)
    - [680_ValidPalindromeII](#680_validpalindromeii)
    - [524_LongestWordInDictionaryThroughDeleting](#524_longestwordindictionarythroughdeleting)
  - [Binary search method 二分查找法](#binary-search-method-二分查找法)
    - [69_Sqrt](#69_sqrt)
    - [34_FindFirstAndLastPositionOfElementInSortedArray](#34_findfirstandlastpositionofelementinsortedarray)
    - [81_SearchInRotatedSortedArrayII](#81_searchinrotatedsortedarrayii)
    - [154_FindMinimumInRotatedSortedArrayII](#154_findminimuminrotatedsortedarrayii)
    - [540_SingleElementInASortedArray](#540_singleelementinasortedarray)

## [Greedy 贪心算法](./Src/Greedy)

- 贪心策略：保证每次操作都是局部最优解，从而使最后得出的结论使全局最优的。

### [455_AssignCookie](./Src/Greedy/455_AssignCookies.cpp)

- [leetcode](https://leetcode-cn.com/problems/assign-cookies/)

- 思路：贪心算法首先是将问题局部化并且取得局部的最优解。此问题中是需要喂给对应孩子可以喂饱的饼干，为了使得剩余的饼干可以满足饥饿度高的孩子因此优先处理饥饿度低的孩子保证数量。
  1. 优先处理饥饿度低的孩子，则可以考虑先进行排序，使得小饼干匹配饥饿度低的孩子。
  2. **因为一个孩子只能吃一个饼干**，因此遍历孩子和饼干，当饼干满足一个孩子进行记录，最终得出这些饼干可以满足多少个孩子。

- 结论：类似 1 v 1 的`连续`匹配或者分配，则采用贪心+排序为思路。

### [135_Candy](./Src/Greedy/135_Candy.cpp)

- [leetcode](https://leetcode-cn.com/problems/candy/)

- 思路：本题也是涉及分配相关，但是存在一个关键点就是，每个孩子得分高则必须比左右两边的孩子糖果要高。细分这个问题，我们可以将左右两侧先分解为左侧与右侧，通过贪心策略保证两侧都是保证最优解，因此可以先左侧遍历，只考虑每个孩子左侧是否积分更高，再进行右侧遍历保证右侧符合规则，最终得出结果。
  1. 左侧遍历：只考虑当前孩子与左侧积分高低，如果比左侧孩子积分高则 +1 保证糖果分配符合左侧标准。
  2. 右侧遍历：反向遍历，每次比对当前孩子与右侧孩子的积分高低，保证糖果分配的复合右侧标准。

- 结论：涉及当前队列位置左右关系的问题，则进行贪心遍历，如果方向是两侧则再次分解保证一侧符合，在进行另一侧遍历。

### [435_Non-overlappingIntervals](./Src/Greedy/435_Non-overlappingIntervals.cpp)

- [leetcode](https://leetcode-cn.com/problems/non-overlapping-intervals/)

- 思路：需要找到重叠的区间进行移除，本题的关键点在于如何比对两个区间是否重合，因为区间给定的包含其坐标，与给定的数组位置无关则优先考虑进行排序，这样处理到的区间符合顺序，接下来就需要考虑排序的方式（因为区间是包涵头尾坐标的），由于比对两个区间的方式是前一个区间的尾坐标与下一个区间的头坐标，因此排序按照尾坐标进行最合适，接下来便利排序后整个数组中所有的区间即可得出结果。
  1. 进行尾坐标排序：与 135 题不同的在于区间与给出的数据组位置无关优先进行排序确保贪心的步骤最优。
  2. 遍历排序后的坐标：遍历并判断相邻两个区间的 `前尾--后头` 两个是否包含。

- 结论：与 455 类似`连续的进行匹配`出所有重合的区间，现对区间进行排序在进行贪心遍历相邻两个区间，这种题需要考虑符合题意的区间排序方式。

### [605_CanPlaceFlowers](./Src/Greedy/605_CanPlaceFlowers.cpp)

- [leetcode](https://leetcode-cn.com/problems/can-place-flowers/)

- 思路：同样可以看出这道题也是个需要连续判断相邻的地块是否有花的问题。从左到右遍历每个地块找出所有连续可以种植的地块数量算出可种植的地块，即可得出结果，难点在于需要判断开始与结束两端。
  1. 三种可以种植的情况：
     1. 开头的地块空闲：计算方式则是空闲数量的一半（向下取整），即 count /2。
     2. 中间的地块空闲：计算方式则是前后有花的地块位置(中间空闲数量 count - 2（这两朵花相邻的位置不能种植）)/2。
     3. 尾部的地块空闲：计算方式是与前一个有花的位置(中间空闲的数量 count - 1（一般最后的位置都是取了数组的 size，取位置需要 - 1）)/2。
  2. 记录一个标记判断是否为开头位置的空地，进行遍历整个数组，通过贪心的策略遍历出所有连续的空闲地块，按照上面三个情况进行计算。
  3. 最后有一个特殊情况即如果开头到末尾没有一个地块被种植，则需要将计算 (size + 1（因为数组两侧种花只影响一侧的空地）)/2。

- 结论：思路都是与 435 这种区间题类似，不过由于地块与给定的位置有关不能排序外，思路都是贪心策略找出所有连续的地块么，要考虑完全所有的情况。

### [452_MinimumNumberOfArrowsToBurstBalloons](./Src/Greedy/452_MinimumNumberOfArrrowToBurstBalloons.cpp)

- [leetcode](https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/)

- 思路：与 435 题很类似的同型题，都是判断相重叠的区域，区别在于相等时也是算重合的。这样只有当两个区域完全不重合时 count++。⚠️ count 初始值就应当为 1，不要漏掉第一个气球。

- 结论：同样是连续比对所有重合的区间，通过贪心策略找出所有重合的以计算出最少的箭数。

### [763_PartitionLabels](./Greedy/../Src/Greedy/763_PartitionLabels.cpp)

- [leetcode](https://leetcode-cn.com/problems/partition-labels/)

- 思路：同样是连续比对重复字符串现的范围，切割字符串。对于字符出现位置的问题，可以使用 map 表记录所有字符最后出现的问题，实时的更新地址 end 为当前字符最后出现的位置，当遍历的位置等于 end 时则包含了所有字符可以切割。
  1. 先遍历一次字符串创建 map 表，记录每个字符最后出现的问题。
  2. 遍历字符串，实时更新当前所包含字符的最远端，当遍历的位置等于 end，则切割。

- 总结：作为贪心策略，保证每次查找的字符串总是尽量长的，对于字符串位置的问题使用此类 map 进行辅助可以优先考虑。在处理数组前，统计一遍信息（如频率、个数、第一次/最后一次出现的位置等）可以简化问题难度。

### [122_BestTimeToBuyAndSellStockII](./Src/Greedy/122_BestTimeToBuyAndSellStock.cpp)

- [leetcode](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)

- 思路：简单的贪心算法，由题意可知不能同时多次买入，并且有利润就会买入，则此题就简化为两天之间的利润值相加即可。

- 总结：股票买卖题，贪心算法进行遍历，只需要计算临近两天之间利润即可。

### [406_QueueReconstructionByHeight](./Src/Greedy/406_QueueReconstructionByHeight.cpp)

- [leetcode](https://leetcode-cn.com/problems/queue-reconstruction-by-height/)

- 思路：根据描述进行重新排序队列，涉及到重新对队列排序可以先对数组进行排序，这里身高高的往往前面比当前身高更高的人更少，因此可以针对第一个元素进行降序排序，当身高相同时则在对第二个元素进行升序。排序完成后再通过贪心的策略对数组进行遍历，将按照描述的第二个参数向结果队列中进行添加即可。

- 总结：针对这种数对还要排序的问题，往往根据第一个元素正向排序，第二个元素反向排序往往可以简化问题。

### [665_Non-decreasingArray](./Src/Greedy/665_NonDecreasingArray.cpp)

- [leetcode](https://leetcode-cn.com/problems/non-decreasing-array/)

- 思路：本题初看起来能确认的便是需要遍历数组，可以使用贪心策略。其可以改变一个数字来促使数列符合规则，那么在判断过程中完全可以尝试比对相邻两个数字(a|b)，当其不符合规则时判断是 b 过小还是 a 过大。
  1. 如果当 b 小于 b - 2 时，说明 b 过小了应该修改 b 为 a。
  2. 如果当 b 大于 b - 2 或者 a b 为数列的 1、2 位置的数字时，将 a 修改为 b 避免影响后续的数字。

- 总结：本题难在如何分解贪心策略的最小判断条件，可以发现数列顺序查找往往都是前后进行判断，而需要跳跃对称更适合栈。此题重点在于比对前一个值并更新不符合的值，使得贪心策略简化为前后两个数字对比即可。

## [DoublePointer 双指针](./Src/DoublePointer/)

- 双指针主要应用在几个方面：
  1. 遍历数组：两个指针指向不同的元素，从而协同完成任务。也可以延伸到多个数组多个指针。
  2. 区间搜索：两个指针指向同一数组，遍历方向相同切不会相交，则也称为滑动窗口。
  3. 搜索：两个指针指向同一数组，遍历方向相反，主要用于搜索且往往待搜索的数组是排好序的。

### [167_TwoSumII](./Src/DoublePointer/167_TwoSum.cpp)

- [leetcode](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/)

- 思路：题目中`已经非递减排序的数组`已经指示了通过双指针进行搜索。双指针进行方向相反的遍历，当双指针指向的数字相加结果大于目标，则 l++，反之 r--。

- 结论：对于排好序且有解的数组通过双指针搜索可以找到最优解，此题的双指针与贪心的区别在于，贪心策略往往是当前数据左右两侧进行比对寻求局部最优解，而此题的双指针则是在整个数列中寻找另一个届。

### [88_MergeSortedArray](./Src/DoublePointer/88_MergeSortedArray.cpp)

- [leetcode](https://leetcode-cn.com/problems/merge-sorted-array/)

- 思路：已经排好序的数组往往预示着需要双指针了。两个数组进行合并，可以将双指针分别放在两个数列的末尾，每次将较大的数字复制到 nums1 的后边，然后向前进位。
  1. m、n 指针指向两个数列的末尾，第三个 pos 指针起始位置为 m + n - 1。
  2. 每次向前移动 m 和 n 时，也要向前移动 pos。
  3. 如果 nums1 复制完成，需要继续将 nums2 的都复制过来；反之 nums2 先完成则直接结束。

- 结论：对于已排好序的数组合并都可以采用这种方式。

### [142_LinkedListCycleII](./Src/DoublePointer/142_LinkedListCycleII.cpp)

- [leetcode](https://leetcode-cn.com/problems/linked-list-cycle-ii/)

- 思路：对于链表找环路的问题，有一个通用的解法——快慢指针(Floyd 判圈法)。给定两个指针， 分别命名为 slow 和 fast，起始位置在链表的开头。每次 fast 前进两步，slow 前进一步。如果 fast 可以走到尽头，那么说明没有环路;如果 fast 可以无限走下去，那么说明一定有环路，且一定存 在一个时刻 slow 和 fast 相遇。当 slow 和 fast 第一次相遇时，我们将 fast 重新移动到链表开头，并让 slow 和 fast 每次都前进一步。当 slow 和 fast 第二次相遇时，相遇的节点即为环路的开始点。

- 总结：针对查找环路问题的固定套路**快慢指针**。

### [76_MinimumWindwSubstring](./Src/DoublePointer/76_MinimumWindowSubstring.cpp)

- [leetcode](https://leetcode-cn.com/problems/minimum-window-substring/)

- 思路：在一个字符串中查找包含另一个字符串所有字符的最短子串，此类往往使用滑动窗口进行求解。l、r 指针都从左开始，r 向右遍历，当包含了字符串所有字符后，移动 l 尽量缩短，直到 r 遍历完成整个字符串。这里有个技巧便是针对字符记录可以使用 128 的数组来映射字符，或者使用哈希表替代，其中 chars 表示目前每个字符缺少的数量，flag 表示每个字符是否在 T 中存在。
  1. 统计 T 字符串信息，包含的字符、数量。
  2. 先移动 r 指针扩大窗口直到包含了 T 的所有字符。
  3. 接下来移动 l 指针尽量缩小窗口。
  4. 当缩小的窗口不再包含所有的 T 字符，继续向右扩展。

- 总结：滑动窗口适合用来查找最小子范围项，需要设计好如何控制左右边的移动。

### [633_SumOfSquareNumbers](./Src/DoublePointer/633_SumOfSquareNumbers.cpp)

- [leetcode](https://leetcode-cn.com/problems/sum-of-square-numbers/)

- 思路：此题可以将思路转化为一个排序后的数列中找到两个整数的平方和等于目标，而这个数列的范围是从 0 - sqrt(target)。
  1. 确认左右指针指向数列的头尾。
  2. 左右指针平方后相加与目标比对。
  3. 如果过大则 r--，反之 l++。
  4. 如果 l == r，则表明不存在。

- 总结：此题是典型的思路转换，将其转化为可以用双指针进行查找的数列。

### [680_ValidPalindromeII](./Src/DoublePointer/680_ValidPalindromeII.cpp)

- [leetcode](https://leetcode-cn.com/problems/valid-palindrome-ii/)

- 思路：回文问题往往采用双指针，左右指针实时比对。此题有个机会可以删除一个不对称的字符，由此产生两种情况**删掉左侧**与**删掉右侧**执行的字符，因此我们当遇到不相同的字符时，可以将这两种情况都进行计算最终得出结果，其中一种可以即能返回 true，反之 false。
  1. 设定左右两指针，指向字符串的头尾。
  2. 遍历字符串，比对每个字符。
  3. 当出现不相同的字符时，先尝试去掉左侧字符后遍历剩余字符串能否确认是回文。
  4. 同样遍历右侧，最后得出结果。

- 总结：回文字符串经典题型，可以判断字符串是否为回文以及如何修改成回文。

### [524_LongestWordInDictionaryThroughDeleting](./Src/DoublePointer/524_LongestWordInDicThroughtDel.cpp)

- [leetcode](https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/)

- 思路：查找子字符串与 76 题类似，不过本题有多个目标且不需要在源字符串中查找最短的情况，因此需要遍历目标集合，分别在源字符串中进行查找，最后再通过比对字符序来选取答案。
  1. 遍历目标集合。
  2. 双指针判断是否包含此字符串。
  3. 判断长度与字符序来确认最优答案。

- 总结：此题可以与 76 题对比来看，76 题是通过滑动窗口来找出包含目标字符串所有字符的最小子串，而本体使通过双指针判断所有在源字符串中包括的目标字符串找出其中最长的。

## [Binary search method 二分查找法](./Src/Middle/)

二分查找也常被称为二分法或者折半查找，每次查找时通过将待查找区间分成两部分并只取 一部分继续查找，将查找的复杂度大大减少。对于一个长度为 O(n) 的数组，二分查找的时间复 杂度为 O(log n)。二分查找也可以看作双指针的一种特殊情况，但我们一般会将二者区分。双指针类型的题， 指针通常是一步一步移动的，而在二分查找里，指针每次移动半个区间长度。

### [69_Sqrt](./Src/Middle/69_Sqrt.cpp)

- [leetcode](https://leetcode-cn.com/problems/sqrtx/)

- 思路：二分查找法也是先确定左右边界，与双指针不同之处在于它取中间值，如果中间值过大或过小来移动左右边界。此题可以先从输入的 x/2 判断其平方后是否等于 x，如果大于则移动 r 到 middle 的位置，再重新取 middle 进行计算，反之左侧同理。= 0

- 总结：计算中间值可以采用 `mid = l + (r-l)/2` 的方式避免 l + r 溢出。

### [34_FindFirstAndLastPositionOfElementInSortedArray](./Src/Middle/34_FindFirstAndLastPos.cpp)

- [leetcode](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

- 思路：可以看做进行两次二分查找法，一次查找低位一次查找高位，本题难度在于理解二分法细节可以区分如何查找高位还是地位。
  0. 使用左开右闭的方式，可以方便区分高位与低位。
  1. 首先通过二分法查找低位：
     1. 确定左右边界为数列两侧。
     2. 计算中间位置。
     3. 当 mid 位置的数**大于等于** target 时，将 r 偏移到 mid 的位置。
     4. 当 mid 位置的数**小于** target 时，将 l 偏移到 mid + 1 的位置。
     5. 最后直到 l==r 时返回 l 的位置即 低位 target。
  2. 使用二分查找法找高位：
     1. 确定左右边界为数列两侧。
     2. 计算中间位置。
     3. 当 mid 位置的数**大于** target 时，将 r 偏移到 mid 的位置。
     4. 当 mid 位置的数**小于等于** target 时，将 l 偏移到 mid + 1 的位置。
     5. 最后直到 l==r 返回 l 的位置即 高位 target 大 1 的位置。
  3. 最后 【步骤1结果，步骤2结果-1】即最终结果。

- 总结：对于二分法的左右边界考虑是难点。就此题而言，使用左开右闭的方式可以使左侧边界向前移动避免死循环，计算低位时采用小于时左侧才动，这样当左右相交时必然是 r 处于 target 的地位。计算高位时同理，使得 r 处于高位 +1 的位置上，也正是因此当返回 upper 后还要记得 -1。⚠️ 请思考下为什么 r = nums.size() 而不用 -1。

> 因为当数组仅有一个数据时如果 size - 1，则会直接返回导致 upper 返回值 -1 变成负数。

### [81_SearchInRotatedSortedArrayII](./Src/Middle/81_SearchInRotatedSortedArrayII.cpp)

- [leetcode](https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/)

- 思路：即使是旋转过的数组也可以利用已有的递增性质，进行二分查找。对于当前的中点， 如果它指向的值小于等于右端，那么说明右区间是排好序的;反之，那么说明左区间是排好序的。 如果目标值位于排好序的区间内，我们可以对这个区间继续二分查找;反之，我们对于另一半区 间继续二分查找。⚠️ 注意，因为数组存在重复数字，如果中点和左端的数字相同，我们并不能确定是左区间全部 相同，还是右区间完全相同。在这种情况下，我们可以简单地将左端点右移一位，然后继续进行 二分查找。
  1. 先确定左右边界为0、size - 1。
  2. 循环条件为 l <= r。
  3. 求中间值。
  4. 判断 mid 是否与 l 相等，如果相等无法判断左右是否有递增性，将 l + 1。
  5. 如果不想等则判断 l、r 位置的数字哪侧比 mid 大。
  6. 偏移左右边界，得出结果。

- 总结：此题为经典的二分查找法应用，难点在于如何在翻转后的数组中找到升序列，切记其中 `nums[mid] == nums[l]` 时无法判断升序的情况。

### [154_FindMinimumInRotatedSortedArrayII](./Src/Middle/154_FindMinimumInRotatedSortedArrayII.cpp)

- [leetcode](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/)

- 思路：此题与 81 不同在于查找最小值，而最小值伴随着数组的旋转后往往处于无序的那一侧，因此本题左右边界移动的条件便是当判断出一侧为有序后将范围缩小到相反的一侧。
  1. 确定左右边界。
  2. 循环条件为 l < r，左开右闭。
  3. 求取中值，判断 num[r] > num[r]，更新 l 反之更新 r。
  4. 如果相等判断不出则进行 r--。
  5. 最终 l 处即为最小值。

- 思路：结合 81 题分析，这两道题的难点在于如何找到旋转后的有序方向，其中 81 题判断 `nums[mid] == nums[l]` 这种情况无法判断时当前中值在左侧旋转后的数列还是在旋转前的数列中，因为存在重复的数。而此题是判断 `nums[mid] == nums[r]` 的时候缩小 r--，同理是因为存在重复数据无法判断当前中值是否被旋转过，需要继续 r-- 来缩小范围。

### [540_SingleElementInASortedArray](./Src/Middle/540_SingleElmentInASortedArray.cpp)

- [leetcode](https://leetcode-cn.com/problems/single-element-in-a-sorted-array/)

- 思路：出现单数的前后每一对数的奇偶性有变化，11 22 偶奇 偶奇，1122 3 4455，偶奇偶奇 偶 奇偶奇偶。根据此特性进行二分法查找即可。
  1. 确定左右边界。
  2. 循环条件为 l < r。
  3. 判断 mid 处是双数中的位置，判断当前位置是处于单数前还是后。
  4. 依据位置调整 l、r 边界。

- 总结：主要难点在于找出这个数列在单数前后的区分特点，用来进行左右边界调整的判断条件。注意其中边界 +1 -1 主要考虑要将数对包含或者排除，避免边界调整切割出单个数。
