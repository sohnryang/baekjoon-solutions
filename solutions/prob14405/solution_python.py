"""
Baekjoon Online Judge #14405
https://www.acmicpc.net/problem/14405
"""

in_str = input()
result = 'YES'
i = 0
while i < len(in_str):
    if in_str[i:i + 2] in ['pi', 'ka']:
        i += 2
    elif in_str[i:i + 3] == 'chu':
        i += 3
    else:
        result = 'NO'
        break
print(result)
