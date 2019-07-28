#include <cstring>
#include <iostream>

using std::cin;
using std::cout;
using std::memset;

int main() {
    char str[101];
    cin >> str;
    int alphabet_count['z' - 'a' + 1];
    memset(alphabet_count, -1, sizeof(alphabet_count));
    for (int i = 0; str[i] != '\0'; ++i)
        alphabet_count[str[i] - 'a'] = 
            alphabet_count[str[i] - 'a'] != -1 ?
            alphabet_count[str[i] - 'a'] : i;
    for (auto count: alphabet_count) cout << count << ' ';
    cout << '\n';
    return 0;
}
