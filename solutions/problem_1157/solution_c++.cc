/*
 * Baekjoon Online Judge #1157
 * https://www.acmicpc.net/problem/1157
 */

#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

char in_s[1000001];

int main() {
    scanf("%s", in_s);
    int len = strlen(in_s);
    int alphabets[26];
    memset(alphabets, 0, sizeof(alphabets));
    for (int i = 0; i < len; ++i) {
        if (in_s[i] >= 'a') alphabets[in_s[i] - 'a']++;
        else alphabets[in_s[i] - 'A']++;
    }
    int max_letter = -1;
    for (int i = 0; i < 26; ++i)
        max_letter = max(max_letter, alphabets[i]);
    int max_count = 0, max_idx = 0;
    for (int i = 0; i < 26; ++i) {
        if (alphabets[i] == max_letter) {
            max_idx = i;
            max_count++;
        }
    }
    if (max_count > 1) printf("?\n");
    else printf("%c\n", max_idx + 'A');
    return 0;
}