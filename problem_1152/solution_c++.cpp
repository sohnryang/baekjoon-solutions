#include <cstring>
#include <iostream>

using std::cin;
using std::cout;
using std::getline;
using std::strlen;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    char line[1000001];
    cin.getline(line, 1000001);
    int len = strlen(line);
    if (len == 0 || (len == 1 && line[0] == ' '))
        cout << 0 << '\n';
    else {
        int word_count = 1;
        for (int i = 0; line[i] != '\0'; ++i)
            if (line[i] == ' ' && i != 0 && i != len - 1)
                word_count++;
        cout << word_count << '\n';
    }
    return 0;
}
