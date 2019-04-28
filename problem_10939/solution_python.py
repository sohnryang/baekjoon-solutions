"""
Baekjoon Online Judge #10939
https://www.acmicpc.net/problem/10939
"""

from base64 import b32decode

print(b32decode(input()).decode('utf-8'))
