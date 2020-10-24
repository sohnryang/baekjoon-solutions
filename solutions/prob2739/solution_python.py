"""
Problem 2739
https://www.acmicpc.net/problem/2739
"""


def main():
    """main function"""
    input_n = int(input())
    for i in range(1, 10):
        print("{0} * {1} = {2}".format(input_n, i, input_n * i))


if __name__ == "__main__":
    main()
