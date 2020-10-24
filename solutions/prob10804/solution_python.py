"""
Baekjoon Online Judge #10804
https://www.acmicpc.net/problem/10804
"""

cards = list(range(1, 21))
for _ in range(10):
    a, b = map(int, input().split())
    cards[a - 1:b] = reversed(cards[a - 1:b])
for card in cards:
    print(card, end=' ')
print()
