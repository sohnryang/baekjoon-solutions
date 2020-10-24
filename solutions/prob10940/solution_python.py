"""
Baekjoon Online Judge #10940
https://www.acmicpc.net/problem/10940
"""

from base64 import b16encode

print(b16encode(input().encode('utf-8')).decode('utf-8'))
