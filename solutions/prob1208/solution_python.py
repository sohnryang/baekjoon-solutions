"""
Baekjoon Online Judge #1208
https://www.acmicpc.net/problem/1208
"""

import itertools
from collections import defaultdict
from sys import stdin
from typing import DefaultDict

infast = lambda: stdin.readline().strip()


def power_set(arr):
    return itertools.chain.from_iterable(
        itertools.combinations(arr, r) for r in range(len(arr) + 1)
    )


N, S = map(int, infast().split())
arr = [int(x) for x in infast().split()]
left = arr[: N // 2]
right = arr[N // 2 :]
left_sums: DefaultDict[int, int] = defaultdict(lambda: 0)
for left_subset in power_set(left):
    left_sums[sum(left_subset)] += 1
right_sums: DefaultDict[int, int] = defaultdict(lambda: 0)
for right_subset in power_set(right):
    right_sums[sum(right_subset)] += 1

res = 0
for left_sum, left_sum_count in left_sums.items():
    right_sum = S - left_sum
    right_sum_count = right_sums[right_sum]
    if left_sum == 0 and right_sum == 0:
        res += max(left_sum_count * right_sum_count - 1, 0)
    else:
        res += left_sum_count * right_sum_count
print(res)
