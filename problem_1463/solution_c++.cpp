#include <cstring>
#include <iostream>

using std::cin;
using std::cout;
using std::memset;
using std::min;

int cache[1000001];
const int INF = 987654321;

int make_one(int n) {
    int& result = cache[n];
    if (result != -1) return result;
    result = INF;
    if (n == 1) {
        result = 0;
        return result;
    }
    if (n % 3 == 0) result = min(result, 1 + make_one(n / 3));
    if (n % 2 == 0) result = min(result, 1 + make_one(n / 2));
    result = min(result, 1 + make_one(n - 1));
    return result;
}

int main() {
    cin.sync_with_stdio(false);
    memset(cache, -1, sizeof(cache));

    int n;
    cin >> n;
    cout << make_one(n) << '\n';
    return 0;
}
