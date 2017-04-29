"""
Problem 10869
https://www.acmicpc.net/problem/10869
"""


def solve(input_1, input_2):
    """solves problem"""
    return (input_1 + input_2, input_1 - input_2, input_1 * input_2,
            input_1 // input_2, input_1 % input_2)


def main():
    """main function"""
    in1, in2 = [int(x) for x in input().split()]
    result = solve(in1, in2)
    for i in result:
        print(i)


if __name__ == "__main__":
    main()
