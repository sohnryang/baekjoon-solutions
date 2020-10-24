"""
Baekjoon Online Judge #1181
https://www.acmicpc.net/problem/1181
"""

from functools import cmp_to_key

def sorted_by(a, b):
    if len(a) != len(b):
        return len(a) - len(b)
    else:
        return 1 if a > b else 0 if a == b else -1

in_n = int(input())
in_words = []
for _ in range(in_n):
    word = input()
    if word not in in_words:
        in_words.append(word)
in_words = sorted(in_words, key=cmp_to_key(sorted_by))
for word in in_words:
    print(word)
