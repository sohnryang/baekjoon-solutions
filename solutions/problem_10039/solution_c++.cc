#include <iostream>

using std::cin;
using std::cout;

int main() {
    int scores[5];
    for (int i = 0; i < 5; ++i) {
        int score;
        cin >> score;
        if (score < 40) scores[i] = 40;
        else scores[i] = score;
    }

    int sum = 0;
    for (auto score: scores) sum += score;
    cout << sum / 5 << '\n';
}
