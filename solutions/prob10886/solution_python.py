"""
Baekjoon Online Judge #10886
https://www.acmicpc.net/problem/10886
"""

in_n = int(input())
cute = 0
not_cute = 0
for _ in range(in_n):
    if int(input()) == 0:
        not_cute += 1
    else:
        cute += 1
print('Junhee is not cute!' if not_cute > cute else 'Junhee is cute!')
