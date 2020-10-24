"""
Problem 1546
https://www.acmicpc.net/problem/1546
"""


def main():
    """main function"""
    input()
    scores = [int(x) for x in input().split()]
    max_score = max(scores)
    faked_scores = []
    for score in scores:
        faked_scores.append(score / max_score * 100)
    print(sum(faked_scores) / len(faked_scores))


if __name__ == "__main__":
    main()
