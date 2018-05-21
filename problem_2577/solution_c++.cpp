#include <cstring>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::memset;
using std::string;
using std::to_string;

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;
    string number = to_string(a * b * c);
    int count[10];
    memset(count, 0, sizeof(count));
    for (auto c: number) count[c - '0']++;
    for (int i = 0; i < 10; ++i) cout << count[i] << '\n';
    return 0;
}
