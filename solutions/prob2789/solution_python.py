"""
Baekjoon Online Judge #2789
https://www.acmicpc.net/problem/2789
"""

censored_char = 'CAMBRIDGE'
in_str = input()
for char in censored_char:
    in_str = in_str.replace(char, '')
print(in_str)
