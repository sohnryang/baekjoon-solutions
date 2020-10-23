"""
Baekjoon Online Judge #1043
https://www.acmicpc.net/problem/1043
"""

from collections import deque
from sys import stdin
infast = lambda: stdin.readline().strip()

N, M = map(int, infast().split())
knowing_people = list(map(int, infast().split()))[1:]
parties = []
graph = dict()
for i in range(1, N + 1):
    graph[i] = set()
for _ in range(M):
    party = set(list(map(int, infast().split()))[1:])
    parties.append(party)
    for person in party:
        others = party - set([person])
        graph[person] |= others

q = deque(knowing_people)
visited = set(knowing_people)
while q:
    here = q.popleft()
    for there in graph[here]:
        if there not in visited:
            visited.add(there)
            q.append(there)

result = 0
for party in parties:
    result += int(party.pop() not in visited)
print(result)
