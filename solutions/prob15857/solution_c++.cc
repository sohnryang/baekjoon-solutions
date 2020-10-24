/*
 * Baekjoon Online Judge #15857
 * https://www.acmicpc.net/problem/15857
 */

#include <cstdio>

using namespace std;

int main() {
    int problem_number;
    char answer_table[9] = "abbcdddc";
    scanf("%d", &problem_number);
    printf("%c\n", answer_table[problem_number - 1]);
    return 0;
}
