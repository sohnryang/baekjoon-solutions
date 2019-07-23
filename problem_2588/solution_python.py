"""
Baekjoon Online Judge #2588
https://www.acmicpc.net/problem/2588
"""

N = int(input())
M = int(input())
M_str = str(M)
for m in reversed(M_str):
    print(int(m) * N)
print(N * M)
