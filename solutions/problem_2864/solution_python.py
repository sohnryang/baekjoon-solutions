"""
Baekjoon Online Judge #2864
https://www.acmicpc.net/problem/2864
"""

[in_a, in_b] = map(int, input().split())
max_a = int(str(in_a).replace('5', '6'))
max_b = int(str(in_b).replace('5', '6'))
min_a = int(str(in_a).replace('6', '5'))
min_b = int(str(in_b).replace('6', '5'))
print('%d %d' % (min_a + min_b, max_a + max_b))
