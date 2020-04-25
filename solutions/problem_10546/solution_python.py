"""
Baekjoon Online Judge #10546
https://www.acmicpc.net/problem/10546
"""

from sys import stdin
infast = lambda: stdin.readline().strip()

N = int(infast())
players = {}

for _ in range(N):
    player = infast()
    if player in players:
        players[player] += 1
    else:
        players[player] = 1
for _ in range(N - 1):
    player = infast()
    players[player] -= 1
    if players[player] == 0:
        del players[player]

print(list(players.keys())[0])
