"""
Problem 2439
https://www.acmicpc.net/problem/2439
"""


def main():
    """main function"""
    input_n = int(input())
    for i in range(1, input_n + 1):
        print(('*' * i).rjust(input_n))


if __name__ == "__main__":
    main()
