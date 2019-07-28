#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int test_cases;
    cin >> test_cases;
    for (int i = 0; i < test_cases; ++i) {
        string input;
        cin >> input;
        int total_score = 0, segment_score = 0;
        for (auto c: input) {
            if (c == 'O') total_score += ++segment_score;
            else segment_score = 0;
        }
        cout << total_score << '\n';
    }
}
