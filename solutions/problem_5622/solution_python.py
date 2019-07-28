"""
Baekjoon Online Judge #5622
https://www.acmicpc.net/problem/5622
"""

def query_dial(letter):
    if letter in 'ABC':
        return 3
    elif letter in 'DEF':
        return 4
    elif letter in 'GHI':
        return 5
    elif letter in 'JKL':
        return 6
    elif letter in 'MNO':
        return 7
    elif letter in 'PQRS':
        return 8
    elif letter in 'TUV':
        return 9
    else:
        return 10

in_str = input()
number = []
for c in in_str:
    number.append(query_dial(c))
result = 0
for n in number:
    result += n
print(result)
