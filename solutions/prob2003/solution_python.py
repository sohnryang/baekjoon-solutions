"""
Baekjoon Online Judge #2003
https://www.acmicpc.net/problem/2003
"""

N, M = map(int, input().split())
A = list(map(int, input().split()))
A.append(0)
lo = 0
hi = 0
running_sum = A[0]
result = 0
while lo <= hi < N:
    if running_sum < M:
        hi += 1
        running_sum += A[hi]
    elif running_sum == M:
        result += 1
        hi += 1
        running_sum += A[hi]
    elif running_sum > M:
        running_sum -= A[lo]
        lo += 1
        if hi < lo < N:
            hi = lo
            running_sum = A[lo]
print(result)
