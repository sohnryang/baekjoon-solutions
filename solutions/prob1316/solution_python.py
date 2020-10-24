"""
Baekjoon Online Judge #1316
https://www.acmicpc.net/problem/1316
"""

in_n = int(input())
result = 0
for i in range(in_n):
    in_word = input()
    alphabet_table = [False] * 26
    group_word = True
    for index, char in enumerate(in_word):
        if alphabet_table[ord(char) - ord('a')] and index != 0 and \
                in_word[index - 1] != char:
            group_word = False
            break
        else:
            alphabet_table[ord(char) - ord('a')] = True
    result += int(group_word)
print(result)
