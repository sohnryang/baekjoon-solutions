"""
Baekjoon Online Judge #10331
https://www.acmicpc.net/problem/10331
"""

E = input()
A = int(input())
val1 = eval(E)
E = E.replace('+', ' + ')
E = E.replace('*', ' * ')
expression = E.split()
while '+' in expression or '*' in expression:
    leading = expression[:3]
    result = eval(''.join(leading))
    expression = expression[3:]
    expression.insert(0, str(result))
val2 = int(expression[0])
if A == val1:
    print('U' if val1 == val2 else 'M')
elif A == val2:
    print('L')
else:
    print('I')
