"""
Problem 10817
https://www.acmicpc.net/problem/10817
"""


def main():
    """main function"""
    input_list = [int(x) for x in input().split()]
    sorted_list = sorted(input_list)
    print(sorted_list[1])


if __name__ == '__main__':
    main()
