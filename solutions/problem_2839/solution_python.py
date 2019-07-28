"""
Problem 2839
https://www.acmicpc.net/problem/2839
"""


def main():
    """main function"""
    input_n = int(input())
    number_of_5kg = input_n // 5
    number_of_3kg = -1

    while number_of_5kg >= 0:
        if (input_n - number_of_5kg * 5) % 3 == 0:
            number_of_3kg = (input_n - number_of_5kg * 5) / 3
            break
        number_of_5kg -= 1

    if number_of_3kg == -1:
        print(-1)
    else:
        assert input_n == (number_of_3kg * 3 + number_of_5kg * 5)
        print(int(number_of_3kg + number_of_5kg))


if __name__ == "__main__":
    main()
