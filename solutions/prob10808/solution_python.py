"""
Baekjoon Online Judge #10808
https://www.acmicpc.net/problem/10808
"""

S = input()
chars = [0] * 26
for c in S:
    chars[ord(c) - ord('a')] += 1
for n in chars:
    print(n, end=' ')
print()
