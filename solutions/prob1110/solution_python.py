"""
Problem 1110
https://www.acmicpc.net/problem/1110
"""


def main():
    """main function"""
    input_n = int(input())
    end_cycle = False
    num_cycles = 0
    tmp_num = input_n
    while not end_cycle:
        first_digit = tmp_num // 10
        second_digit = tmp_num % 10
        tmp_num = second_digit * 10 + (first_digit + second_digit) % 10
        num_cycles += 1
        if tmp_num is input_n:
            end_cycle = True
    print(num_cycles)


if __name__ == "__main__":
    main()
