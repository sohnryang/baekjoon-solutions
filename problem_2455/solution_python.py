"""
Baekjoon Online Judge #2455
https://www.acmicpc.net/problem/2455
"""

first = list(map(int, input().split()))
second = list(map(int, input().split()))
third = list(map(int, input().split()))
fourth = list(map(int, input().split()))
maximum = first[1]
maximum = max(maximum, first[1] - second[0] + second[1])
maximum = max(maximum, first[1] - second[0] + second[1] - third[0] + third[1])
maximum = max(
    maximum,
    first[1] - second[0] + second[1] - third[0] + \
            third[1] - fourth[0] + fourth[1]
)
print(maximum)
