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

## [Greedy 贪心算法](./Src/Greedy)

- 贪心策略：保证每次操作都是局部最优解，从而使最后得出的结论使全局最优的。

### [455_AssignCookie](./Src/Greedy/455_AssignCookies.cpp)

- [leetcode](https://leetcode-cn.com/problems/assign-cookies/)

- 思路：贪心算法首先是将问题局部话并且取得局部的最优解。此问题中是需要喂给对应孩子可以喂饱的饼干，为了使得剩余的饼干可以满足饥饿度高的孩子因此优先处理饥饿度低的孩子保证数量。
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


