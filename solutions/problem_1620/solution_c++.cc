/*
 * Baekjoon Online Judge #1620
 * https://acmicpc.net/problem/1620
 */

#include <bits/stdc++.h>

using namespace std;

int in_n, in_m;
map<string, int> pokemon_dict;
vector<string> pokemon_table;

int main() {
    scanf("%d %d", &in_n, &in_m);
    for (int i = 0; i < in_n; ++i) {
    	char raw_str[25];
        scanf("%s", raw_str);
        string str = raw_str;
        pokemon_dict[str] = i;
        pokemon_table.push_back(str);
    }
    for (int i = 0; i < in_m; ++i) {
        char raw_str[25];
        scanf("%s", raw_str);
        if (raw_str[0] >= '0' && raw_str[0] <= '9')
            printf("%s\n", pokemon_table[atoi(raw_str) - 1].c_str());
        else
            printf("%d\n", pokemon_dict[raw_str] + 1);
    }
    return 0;
}
