"""
Baekjoon Online Judge #2675
https://www.acmicpc.net/problem/2675
"""

in_t = int(input())
for i in range(in_t):
    in_raw = input()
    in_r = int(in_raw.split()[0])
    in_s = in_raw.split()[1]
    result = ''
    for char in in_s:
        result += (char * in_r)
    print(result)