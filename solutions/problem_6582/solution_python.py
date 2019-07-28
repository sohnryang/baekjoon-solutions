"""
Baekjoon Online Judge #6582
https://www.acmicpc.net/problem/6582
"""

import re

T = int(input())
for i in range(T):
    line = input()
    data = re.findall('(U=[0-9.]+[mkM]?V|I=[0-9.]+[mkM]?A|P=[0-9.]+[mkM]?W)+',
                      line)
    processed = dict()
    for token in data:
        prefix, value = ''.join(token).split('=')
        value = value[:-1]
        val = 0
        if value[-1] == 'm':
            val = float(value[:-1]) * 0.001
        elif value[-1] == 'k':
            val = float(value[:-1]) * 1000
        elif value[-1] == 'M':
            val = float(value[:-1]) * 1000 * 1000
        else:
            val = float(value)
        processed[prefix] = val

    print('Problem #%d' % (i + 1))
    if 'P' not in processed:
        print('P=%.2fW' % (processed['I'] * processed['U']))
    elif 'U' not in processed:
        print('U=%.2fV' % (processed['P'] / processed['I']))
    else:
        print('I=%.2fA' % (processed['P'] / processed['U']))
    print()
