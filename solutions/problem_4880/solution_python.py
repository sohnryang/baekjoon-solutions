"""
Baekjoon Online Judge #4880
https://www.acmicpc.net/problem/4880
"""

while True:
    in_numbers = list(map(int, input().split()))
    if all([n == 0 for n in in_numbers]):
        break
    if in_numbers[1] - in_numbers[0] == in_numbers[2] - in_numbers[1]:
        print('AP %d' % (in_numbers[1] - in_numbers[0] + in_numbers[2]))
    else:
        print('GP %d' % (in_numbers[1] // in_numbers[0] * in_numbers[2]))
