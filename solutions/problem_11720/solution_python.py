"""
Problem 11720
https://www.acmicpc.net/problem/11720
"""


def main():
    """main function"""
    input_n = int(input())
    input_str = str(input())
    result = 0
    for i in range(input_n):
        result += int(input_str[i])
    print(result)


if __name__ == "__main__":
    main()
