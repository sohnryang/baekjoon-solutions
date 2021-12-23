"""
Baekjoon Online Judge #23845
https://www.acmicpc.net/problem/23845
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

N = int(infast())
X = [int(x) for x in infast().split()]
X.sort()
size_table = dict()
for x in X:
    if x not in size_table:
        size_table[x] = 0
    size_table[x] += 1

res = 0
while size_table:
    largest = 0
    deleted = []
    for x in size_table.keys():
        if not deleted or x - largest == 1:
            largest = x
            deleted.append(x)
        elif x == largest:
            continue
        else:
            break
    res += largest * len(deleted)
    for x in deleted:
        size_table[x] -= 1
        if size_table[x] == 0:
            del size_table[x]
print(res)
