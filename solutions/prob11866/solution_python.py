"""
Baekjoon Online Judge #11866
https://www.acmicpc.net/problem/11866
"""

N, K = map(int, input().split())
people = list(range(1, N + 1))

print('<', end='')
first = True
kill = K
while len(people) > 1:
    if first:
        first = False
    else:
        print(', ', end='')
    print(people[kill - 1], end='')
    del people[kill - 1]
    kill -= 1
    kill = (kill + K) % len(people)
    if kill == 0:
        kill = len(people)
if N != 1:
    print(', %d>' % people[0])
else:
    print('1>')
