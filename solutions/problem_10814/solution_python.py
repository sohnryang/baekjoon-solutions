"""
Baekjoon Online Judge #10814
https://www.acmicpc.net/problem/10814
"""

from sys import stdin
from collections import deque
from operator import itemgetter
infast = lambda: stdin.readline().strip()

N = int(infast())
accounts = deque([])

for _ in range(N):
    inputline = infast()
    accounts.append((int(inputline.split()[0]), inputline.split()[1]))

accounts = sorted(accounts, key=lambda x: x[0])
for account in accounts:
    print(account[0], account[1])
