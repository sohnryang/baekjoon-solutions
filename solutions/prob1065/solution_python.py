"""
Problem 1065
https://www.acmicpc.net/problem/1065
"""


def solve(n):
    """solves problem"""
    result = 0

    for i in range(1, n + 1):
        if i < 100:
            result += 1
            continue

        number_list = [int(x) for x in str(i)]
        step = number_list[1] - number_list[0]
        last = number_list[1]
        legitimate = True

        for number in number_list[2:]:
            if number - last is not step:
                legitimate = False
                break

        if legitimate is True:
            result += 1

    return result


def main():
    """main function"""
    input_n = int(input())
    print(solve(input_n))


if __name__ == "__main__":
    main()
