"""
Problem 4344
https://www.acmicpc.net/problem/4344
"""


def main():
    """main function"""
    test_cases = int(input())
    for _ in range(test_cases):
        input_str = input()
        scores = [int(x) for x in input_str.split()][1:]
        average = sum(scores) / len(scores)
        higher_than_avg = 0
        for score in scores:
            if score > average:
                higher_than_avg += 1
        percentage = higher_than_avg / len(scores) * 100
        print(format(percentage, '.3f') + '%')


if __name__ == "__main__":
    main()
