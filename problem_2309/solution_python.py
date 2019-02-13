"""
Baekjoon Online Judge #2309
https://www.acmicpc.net/problem/2309
"""

in_heights = []
for _ in range(9):
    in_heights.append(int(input()))

kill_loop = False
for i in range(8):
    for j in range(i + 1, 9):
        if sum(in_heights) - in_heights[i] - in_heights[j] == 100:
            in_heights[i] = 0
            in_heights[j] = 0
            in_heights.sort()
            for height in in_heights:
                if height > 0:
                    print(height)
            kill_loop = True
            break
    if kill_loop:
        break
