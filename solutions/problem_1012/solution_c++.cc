#include <iostream>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::pair;
using std::vector;

int height, width;
vector<vector<int> > ground;

bool range_test(int y, int x) {
    bool y_inrange = y >= 0 && y < height;
    bool x_inrange = x >= 0 && x < width;

    return x_inrange && y_inrange;
}

void read_input() {
    int pos_count;
    cin >> width >> height >> pos_count;
    ground.clear();

    vector<int> tmp(width, 0);
    for (int y = 0; y < height; ++y) {
        ground.push_back(tmp);
    }

    for (int i = 0; i < pos_count; ++i) {
        int x, y;
        cin >> x >> y;
        ground[y][x] = 1;
    }
}

void expand(int y, int x) {
    if (ground[y][x] == 0 || ground[y][x] == 2) return;
    ground[y][x] = 2;
    if (range_test(y + 1, x)) expand(y + 1, x);
    if (range_test(y - 1, x)) expand(y - 1, x);
    if (range_test(y, x + 1)) expand(y, x + 1);
    if (range_test(y, x - 1)) expand(y, x - 1);
}

int count_worms() {
    int result = 0;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (ground[y][x] == 1) {
                expand(y, x);
                result++;
            }
        }
    }

    return result;
}

int main() {
    int test_cases;
    cin.sync_with_stdio(false);

    cin >> test_cases;
    for (int i = 0; i < test_cases; ++i) {
        read_input();
        cout << count_worms() << '\n';
    }

    return 0;
}
