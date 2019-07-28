/*
 * Baekjoon Online Judge #1780
 * https://www.acmicpc.net/problem/1780
 */

#include <cstdio>
#include <cstring>

using namespace std;

int in_n, paper[2188][2188], result[3];

void cut_paper(int y, int x, int size) {
    if (size == 1) {
        result[paper[y][x] + 1]++;
        return;
    } else {
    	bool same_number = true;
        for (int i = y; i < y + size; ++i) {
        	if (!same_number) break;
            for (int j = x; j < x + size; ++j) {
                if (paper[i][j] != paper[y][x]) {
                    same_number = false;
                    break;
                }
            }
        }
        if (same_number) {
            result[paper[y][x] + 1]++;
            return;
        }
    }
	cut_paper(y, x, size / 3);
    cut_paper(y, x + size / 3, size / 3);
    cut_paper(y, x + (size / 3) * 2, size / 3);
	cut_paper(y + size / 3, x, size / 3);
    cut_paper(y + size / 3, x + size / 3, size / 3);
    cut_paper(y + size / 3, x + (size / 3) * 2, size / 3);
	cut_paper(y + (size / 3) * 2, x, size / 3);
    cut_paper(y + (size / 3) * 2, x + size / 3, size / 3);
    cut_paper(y + (size / 3) * 2, x + (size / 3) * 2, size / 3);
}

int main() {
	memset(paper, -1, sizeof(paper));
    memset(result, 0, sizeof(result));
    scanf("%d", &in_n);
    for (int y = 0; y < in_n; ++y)
        for (int x = 0; x < in_n; ++x)
            scanf("%d", &paper[y][x]);

    cut_paper(0, 0, in_n);
    printf("%d\n%d\n%d", result[0], result[1], result[2]);
    return 0;
}
