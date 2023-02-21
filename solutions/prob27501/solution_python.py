"""
Baekjoon Online Judge #27501
https://www.acmicpc.net/problem/27501
"""

from collections import defaultdict
from sys import stdin
from typing import DefaultDict, Dict, List, Set, Tuple

infast = lambda: stdin.readline().strip()

N = int(infast())
graph: DefaultDict[int, List[int]] = defaultdict(list)
for _ in range(N - 1):
    A, B = map(int, infast().split())
    graph[A].append(B)
    graph[B].append(A)
visited: Set[int] = set()
tree: DefaultDict[int, List[int]] = defaultdict(list)
stack: List[Tuple[int, int, bool]] = [(1, 0, False)]
topological_sorted: List[int] = []
while stack:
    here, here_parent, second_visit = stack.pop()
    if second_visit:
        topological_sorted.append(here)
        continue
    if here in visited:
        continue
    tree[here_parent].append(here)
    visited.add(here)
    stack.append((here, here_parent, True))
    for there in graph[here]:
        stack.append((there, here, False))
scores: Dict[Tuple[int, int], int] = {}
for i in range(1, N + 1):
    score = [int(x) for x in infast().split()]
    for c, s in enumerate(score):
        scores[(i, c)] = s
dp: List[List[int]] = []
traces: List[List[List[int]]] = []
for _ in range(N + 1):
    dp.append([0] * 3)
    trace_case = []
    for _ in range(3):
        trace_case.append([])
    traces.append(trace_case)
for here in topological_sorted:
    for here_color in range(3):
        dp[here][here_color] = scores[(here, here_color)]
        for there in tree[here]:
            plus1_color = (here_color + 1) % 3
            plus2_color = (here_color + 2) % 3
            plus1_score = dp[there][plus1_color]
            plus2_score = dp[there][plus2_color]
            if plus1_score > plus2_score:
                dp[here][here_color] += plus1_score
                traces[here][here_color].append(plus1_color)
            else:
                dp[here][here_color] += plus2_score
                traces[here][here_color].append(plus2_color)
max_score = max(dp[1])
print(max_score)
max_score_color = dp[1].index(max_score)
colors = [0] * (N + 1)
colors[1] = max_score_color
trace_stack = [1]
trace_visited = set()
while trace_stack:
    here = trace_stack.pop()
    if here in trace_visited:
        continue
    trace_visited.add(here)
    for there, there_color in zip(tree[here], traces[here][colors[here]]):
        trace_stack.append(there)
        colors[there] = there_color
for color in colors[1:]:
    print("RGB"[color], end="")
print()
