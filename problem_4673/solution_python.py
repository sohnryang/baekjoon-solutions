"""
Problem 4673
https://www.acmicpc.net/problem/4673
"""


def generate_nonself_numbers(number):
    """generates <=10000 self numbers from n"""
    nonself_numbers = []
    current = number
    while current <= 10000:
        digits = [int(x) for x in str(current)]
        nonself_number = current + sum(digits)
        if nonself_number > 10000:
            break
        nonself_numbers.append(nonself_number)
        current = nonself_number
    return nonself_numbers


def main():
    """main function"""
    self_numbers = [True] * 10000
    for i in range(1, 10001):
        if self_numbers[i - 1] is True:
            nonself_numbers = generate_nonself_numbers(i)
            for nonself_number in nonself_numbers:
                self_numbers[nonself_number - 1] = False

    for number, result in enumerate(self_numbers, 1):
        if result is True:
            print(number)


if __name__ == "__main__":
    main()
