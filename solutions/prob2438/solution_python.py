"""
Problem 2438
https://www.acmicpc.net/problem/2438
"""


def main():
    """main function"""
    input_n = int(input())
    for i in range(input_n):
        for _ in range(i + 1):
            print('*', end='')
        print()


if __name__ == "__main__":
    main()
