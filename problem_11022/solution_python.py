"""
Baekjoon Online Judge #11022
https://www.acmicpc.net/problem/11022
"""

in_t = int(input())
for i in range(1, in_t + 1):
    [in_a, in_b] = map(int, input().split())
    print('Case #%d: %d + %d = %d' % (i, in_a, in_b, in_a + in_b))
