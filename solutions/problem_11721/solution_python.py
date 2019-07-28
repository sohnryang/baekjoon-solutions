"""
Problem 11721
https://www.acmicpc.net/problem/11721
"""


def main():
    """main function"""
    input_str = input()
    for (index, char) in enumerate(input_str):
        if index % 10 == 0 and index != 0:
            print()
        print(char, end="")
    print()


if __name__ == "__main__":
    main()
