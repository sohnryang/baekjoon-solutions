"""
Baekjoon Online Judge #11021
https://www.acmicpc.net/problem/11021
"""

in_t = int(input())
for i in range(1, in_t + 1):
    [in_a, in_b] = map(int, input().split());
    print('Case #%d: %d' % (i, in_a + in_b))
