"""
Baekjoon Online Judge #1085
https://www.acmicpc.net/problem/1085
"""

in_x, in_y, in_w, in_h = map(int, input().split())
print(min(min(in_w - in_x, in_x), min(in_h - in_y, in_y)))