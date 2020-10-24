"""
Baekjoon Online Judge #12400
https://www.acmicpc.net/problem/12400
"""

rel = {'a': 'y', 'b': 'h', 'c': 'e', 'd': 's', 'e': 'o', 'f': 'c', 'g': 'v',
       'h': 'x', 'i': 'd', 'j': 'u', 'k': 'i', 'l': 'g', 'm': 'l', 'n': 'b',
       'o': 'k', 'p': 'r', 'q': 'z', 'r': 't', 's': 'n', 't': 'w', 'u': 'j',
       'v': 'p', 'w': 'f', 'x': 'm', 'y': 'a', 'z': 'q'}

T = int(input())
for i in range(1, T + 1):
    encoded = input()
    decoded = ''
    for c in encoded:
        if c == ' ':
            decoded += c
        else:
            decoded += rel[c]
    print('Case #%d: %s' % (i, decoded))
