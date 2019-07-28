"""
Problem 10871
https://www.acmicpc.net/problem/10871
"""


def main():
    """main function"""
    _, input_x = [int(x) for x in input().split()]
    numbers = [int(x) for x in input().split()]
    for number in numbers:
        if number < input_x:
            print(number, end=' ')


if __name__ == "__main__":
    main()
