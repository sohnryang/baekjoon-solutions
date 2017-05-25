"""
Problem 2441
https://www.acmicpc.net/problem/2441
"""


def main():
    """main function"""
    input_n = int(input())
    for i in range(input_n, 0, -1):
        print(('*' * i).rjust(input_n))


if __name__ == "__main__":
    main()
