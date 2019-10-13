"""
Baekjoon Online Judge #11723
https://www.acmicpc.net/problem/11723
"""

from sys import stdin

infast = lambda: stdin.readline().strip()
M = int(infast())
s = [False] * 21

for _ in range(M):
    cmd, *arg = infast().split()
    if cmd == 'add':
        arg = int(arg[0])
        s[arg] = True
    elif cmd == 'remove':
        arg = int(arg[0])
        s[arg] = False
    elif cmd == 'check':
        arg = int(arg[0])
        print(int(s[arg]))
    elif cmd == 'toggle':
        arg = int(arg[0])
        s[arg] = not s[arg]
    elif cmd == 'all':
        s = [True] * 21
    elif cmd == 'empty':
        s = [False] * 21
