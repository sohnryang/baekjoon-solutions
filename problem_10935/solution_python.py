"""
Baekjoon Online Judge #10935
https://www.acmicpc.net/problem/10935
"""

from base64 import b64encode

print(b64encode(input().encode('utf-8')).decode('utf-8'))
