"""
Problem 10430
https://www.acmicpc.net/problem/10430
"""


def solve(input_1, input_2, input_3):
    """solves problem"""
    return ((input_1 + input_2) % input_3,
            (input_1 % input_3 + input_2 % input_3) % input_3,
            (input_1 * input_2) % input_3,
            (input_1 % input_3 * input_2 % input_3) % input_3)


def main():
    """main function"""
    in1, in2, in3 = [int(x) for x in input().split()]
    result = solve(in1, in2, in3)
    for i in result:
        print(i)


if __name__ == "__main__":
    main()
