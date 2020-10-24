#include <cstring>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::memset;
using std::string;

int input;
int stars[1024][1024];
int printable_stars[3072][6144];

void draw_stars(int y, int x, int n) {
    if (n == 3) {
        stars[y][x] = 1;
        return;
    } else {
        draw_stars(y, x, n / 2);
        draw_stars(y + n / 6, x, n / 2);
        draw_stars(y + n / 6, x + n / 6, n / 2);
    }
}

void convert_to_printable() {
    for (int y = 0; y < input / 3; ++y) {
        for (int x = 0; x < input / 3; ++x) {
            if (stars[y][x] == 1) {
                printable_stars[y * 3][x * 6 + 2] = 1;
                printable_stars[y * 3 + 1][x * 6 + 1] = 1;
                printable_stars[y * 3 + 1][x * 6 + 3] = 1;
                printable_stars[y * 3 + 2][x * 6] = 1;
                printable_stars[y * 3 + 2][x * 6 + 1] = 1;
                printable_stars[y * 3 + 2][x * 6 + 2] = 1;
                printable_stars[y * 3 + 2][x * 6 + 3] = 1;
                printable_stars[y * 3 + 2][x * 6 + 4] = 1;
            }
        }
    }
}

void print_result() {
    for (int y = 0; y < input; ++y) {
        int spaces = input - 1 - y - 
            (((y + 1) % 3 == 0 ? 0 : 3 - (y + 1) % 3));
        for (int x = 0; x < spaces; ++x) cout << ' ';
        for (int x = spaces; x < input * 2; ++x)
            cout << (printable_stars[y][x - spaces] ? '*' : ' ');
        cout << '\n';
    }
}

int main() {
    cin >> input;
    memset(stars, 0, sizeof(stars));
    memset(printable_stars, 0, sizeof(printable_stars));
    draw_stars(0, 0, input);
    convert_to_printable();
    print_result();
    return 0;
}
