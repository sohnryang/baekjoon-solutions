"""
Baekjoon Online Judge #1076
https://www.acmicpc.net/problem/1076
"""

color_table = {
    'black': 0,
    'brown': 1,
    'red': 2,
    'orange': 3,
    'yellow': 4,
    'green': 5,
    'blue': 6,
    'violet': 7,
    'grey': 8,
    'white': 9
}

first = input()
second = input()
third = input()
print((color_table[first] * 10 + color_table[second]) * 10 ** color_table[third])