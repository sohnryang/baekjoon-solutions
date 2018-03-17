"""
Problem 15552
https://www.acmicpc.net/problem/15552
"""
from sys import stdin, stdout


def main():
    """main function"""
    test_cases = int(input())
    for _ in range(test_cases):
        num1, num2 = [int(x) for x in stdin.readline().split()]
        stdout.write(str(num1 + num2) + '\n')


if __name__ == '__main__':
    main()
