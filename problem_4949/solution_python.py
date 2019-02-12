"""
Baekjoon Online Judge #4949
https://www.acmicpc.net/problem/4949
"""

import re

while True:
    in_str = input()
    if in_str == '.':
        break
    in_str = re.sub(r'[^\[\]\(\)]', '', in_str)
    result = 'yes'
    stack = []
    if in_str:
        for c in in_str:
            if c == '(' or c == '[':
                stack.append(c)
            else:
                if not stack:
                    result = 'no'
                    break
                last = stack.pop()
                if (last == '(' and c == ')') or (last == '[' and c == ']'):
                    continue
                else:
                    result = 'no'
                    break
        if result == 'yes':
            result = 'yes' if len(stack) == 0 else 'no'
    print(result)
