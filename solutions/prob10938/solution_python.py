"""
Baekjoon Online Judge #10938
https://www.acmicpc.net/problem/10938
"""

from base64 import b32encode

print(b32encode(input().encode('utf-8')).decode('utf-8'))
