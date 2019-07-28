#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::memset;

int cache[41][2];

int fib_count0(int n) {
    if (n == 0) return 1;
    else if (n == 1) return 0;
    else {
        int& result = cache[n][0];
        if (result != -1) return result;
        result = fib_count0(n - 1) + fib_count0(n - 2);
        return result;
    }
}

int fib_count1(int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else {
        int& result = cache[n][1];
        if (result != -1) return result;
        result = fib_count1(n - 1) + fib_count1(n - 2);
        return result;
    }
}

int main() {
    int test_cases;
    memset(cache, -1, sizeof(cache));
    cin.sync_with_stdio(false);
    cin >> test_cases;

    for (int i = 0; i < test_cases; i++) {
        int n;
        cin >> n;
        cout << fib_count0(n) << ' ' << fib_count1(n) << '\n';
    }

    return 0;
}
