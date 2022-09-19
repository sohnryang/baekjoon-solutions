"""
Baekjoon Online Judge #25542
https://www.acmicpc.net/problem/25542
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

N, L = map(int, infast().split())
seed = infast()
if N == 1:
    print(seed)
    exit(0)
S = []
for _ in range(N - 1):
    S.append(infast())

for mask_idx in range(L):
    mismatch_idxs = []
    for word in S:
        mismatch_idx = []
        for i, ch in enumerate(word):
            if i == mask_idx or ch == seed[i]:
                continue
            if len(mismatch_idx) == 1:
                break
            mismatch_idx.append(i)
        else:
            mismatch_idxs.append(mismatch_idx)
    if len(mismatch_idxs) != N - 1:
        continue
    for word in S:
        mismatch_counts = [len(l) for l in mismatch_idxs]
        mask_ch = word[mask_idx]
        for i, another_word in enumerate(S):
            mismatch_counts[i] += int(mask_ch != another_word[mask_idx])
        if all([x <= 1 for x in mismatch_counts]):
            print(seed[:mask_idx] + mask_ch + seed[mask_idx + 1:])
            exit(0)
print("CALL FRIEND")
