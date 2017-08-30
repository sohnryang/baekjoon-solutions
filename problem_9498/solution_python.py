"""
Problem 9498
https://www.acmicpc.net/problem/9498
"""


def main():
    """main function"""
    input_score = int(input())
    if 90 <= input_score <= 100:
        print('A')
    elif 80 <= input_score <= 89:
        print('B')
    elif 70 <= input_score <= 79:
        print('C')
    elif 60 <= input_score <= 69:
        print('D')
    else:
        print('F')


if __name__ == '__main__':
    main()
