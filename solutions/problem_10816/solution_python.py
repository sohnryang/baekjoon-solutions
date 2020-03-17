"""
Baekjoon Online Judge #10816
https://www.acmicpc.net/problem/10816
"""

from sys import stdin
infast = lambda: stdin.readline().strip()

N = int(infast())
cards = list(map(int, infast().split()))
card_dict = dict()

for card in cards:
    if card in card_dict:
        card_dict[card] += 1
    else:
        card_dict[card] = 1

M = int(infast())
lookups = list(map(int, infast().split()))

for lookup in lookups:
    if lookup in card_dict:
        print(card_dict[lookup], end=' ')
    else:
        print(0, end=' ')
print()
