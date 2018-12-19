"""
Baekjoon Online Judge #2941
https://www.acmicpc.net/problem/2941
"""

in_str = input()
in_str = in_str.replace('c=', '*')
in_str = in_str.replace('c-', '*')
in_str = in_str.replace('dz=', '*')
in_str = in_str.replace('d-', '*')
in_str = in_str.replace('lj', '*')
in_str = in_str.replace('nj', '*')
in_str = in_str.replace('s=', '*')
in_str = in_str.replace('z=', '*')
print(len(in_str))
