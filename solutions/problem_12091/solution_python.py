"""
Baekjoon Online Judge #12091
https://www.acmicpc.net/problem/12091
"""

from random import choice, randint, seed
from time import sleep
sleep(randint(5000, 10000) / 100000)
tries = []
for _ in range(10):
    seed()
    sleep(randint(50000, 100000)/ 10000000)
    tries.append(choice(['Vaporeon', 'Jolteon', 'Flareon']))
print(max(tries, key=tries.count))
sleep(randint(1000, 2000) / 1000000)
