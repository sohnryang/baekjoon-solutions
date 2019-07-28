"""
Baekjoon Online Judge #16462
https://www.acmicpc.net/problem/16462
"""

import math

in_t = int(input())
scores = []
for i in range(in_t):
    score = input()
    score = score.replace('0', '9')
    score = score.replace('6', '9')
    score_num = int(score)
    if score_num > 100:
        score_num = 100
    scores.append(score_num)
print(round(sum(scores) / in_t + 1e-10))
