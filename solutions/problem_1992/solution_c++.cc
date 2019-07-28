/*
 * Baekjoon Online Judge #1992
 * https://www.acmicpc.net/problem/1992
 */

#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int picture[65][65];

string compress(int y, int x, int segment_size) {
    if (segment_size == 1) return string(1, '0' + picture[y][x]);

    int last_pixel = picture[y][x];
    bool same_color = true;
    for (int i = y; i < y + segment_size; ++i) {
        if (!same_color) break;
        for (int j = x; j < x + segment_size; ++j) {
            if (picture[i][j] != last_pixel) {
                same_color = false;
                break;
            }
        }
    }
    if (same_color) return string(1, '0' + last_pixel);

    string result = string("(");
    result += compress(y, x, segment_size / 2);
    result += compress(y, x + segment_size / 2, segment_size / 2);
    result += compress(y + segment_size / 2, x, segment_size / 2);
    result += compress(y + segment_size / 2, x + segment_size / 2,
                       segment_size / 2);
    result += string(")");
    return result;
}

int main() {
    int input_n;
    scanf("%d", &input_n);
    memset(picture, -1, sizeof(picture));
    for (int y = 0; y < input_n; ++y) {
        char line[65];
        scanf("%s", line);
        for (int x = 0; x < input_n; ++x)
            picture[y][x] = line[x] - '0';
    }
    string result = compress(0, 0, input_n);
    printf("%s", result.c_str());
    return 0;
}
