"""
Baekjoon Online Judge #15718
https://www.acmicpc.net/problem/15718
"""

from sys import stdin

infast = lambda: stdin.readline().strip()


def crt(a, b):
    j = (a - b) * pow(1031, -1, 97) % 97
    return (1031 * j + b) % (1031 * 97)


dp97 = []
for _ in range(97):
    dp97.append([1] + [0] * (97 - 1))
for i in range(1, 97):
    for j in range(1, 97):
        dp97[i][j] = (dp97[i - 1][j - 1] + dp97[i - 1][j]) % 97
dp1031 = []
for _ in range(1031):
    dp1031.append([1] + [0] * (1031 - 1))
for i in range(1, 1031):
    for j in range(1, 1031):
        dp1031[i][j] = (dp1031[i - 1][j - 1] + dp1031[i - 1][j]) % 1031

T = int(infast())
for _ in range(T):
    N, M = map(int, infast().split())
    if N == 0:
        print(1 if M == 1 else 0)
        continue
    elif M == 1:
        print(0)
        continue
    exp_n_97 = []
    exp_m_97 = []
    n = N - 1
    m = M - 2
    while n > 0 or m > 0:
        exp_n_97.append(n % 97)
        n //= 97
        exp_m_97.append(m % 97)
        m //= 97
    bino97 = 1
    for x, y in zip(exp_n_97, exp_m_97):
        bino97 *= dp97[x][y]
        bino97 %= 97
    exp_n_1031 = []
    exp_m_1031 = []
    n = N - 1
    m = M - 2
    while n > 0 or m > 0:
        exp_n_1031.append(n % 1031)
        n //= 1031
        exp_m_1031.append(m % 1031)
        m //= 1031
    bino1031 = 1
    for x, y in zip(exp_n_1031, exp_m_1031):
        bino1031 *= dp1031[x][y]
        bino1031 %= 1031
    print(crt(bino97, bino1031))
