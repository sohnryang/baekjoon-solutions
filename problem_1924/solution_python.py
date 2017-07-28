"""
Problem 1924
https://www.acmicpc.net/problem/1924
"""


def main():
    """main function"""
    input_x, input_y = [int(x) for x in input().split()]
    month_len = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    day_str = ["MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"]
    days_from_newyear = sum(month_len[:input_x]) + input_y
    answer = day_str[days_from_newyear % 7 - 1]
    print(answer)


if __name__ == "__main__":
    main()
