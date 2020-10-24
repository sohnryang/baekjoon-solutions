"""
Baekjoon Online Judge #2263
https://www.acmicpc.net/problem/2263
"""

from collections import deque
from sys import stdin
infast = lambda: stdin.readline().strip()

N = int(infast())
inorder = list(map(int, infast().split()))
inorder_intervals = deque([(0, N)])
postorder = list(map(int, infast().split()))
postorder_intervals = deque([(0, N)])
idx_table = [None] * (N + 1)
for i, elem in enumerate(inorder):
    idx_table[elem] = i

while inorder_intervals:
    current_in = inorder_intervals.popleft()
    current_post = postorder_intervals.popleft()
    interval_size = current_in[1] - current_in[0]
    if interval_size == 1:
        print(inorder[current_in[0]], end=' ')
        continue
    elif interval_size == 0:
        continue
    root = postorder[current_post[1] - 1]
    root_pos = idx_table[root]
    print(root, end=' ')
    left_in = (current_in[0], root_pos)
    right_in = (root_pos + 1, current_in[1])
    inorder_intervals.appendleft(right_in)
    inorder_intervals.appendleft(left_in)
    left_post = (current_post[0], current_post[0] + left_in[1] - left_in[0])
    right_post = (current_post[0] + left_in[1] - left_in[0],
                  current_post[1] - 1)
    postorder_intervals.appendleft(right_post)
    postorder_intervals.appendleft(left_post)
print()
