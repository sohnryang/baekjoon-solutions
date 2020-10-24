"""
Baekjoon Online Judge #3009
https://www.acmicpc.net/problem/3009
"""

a = []
b = []
for _ in range(3):
    x, y = map(int, input().split())
    if x in a:
        a.remove(x)
    else:
        a.append(x)
    if y in b:
        b.remove(y)
    else:
        b.append(y)
print(a[0], b[0])
