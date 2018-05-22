#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::getline;
using std::string;

int main() {
    string line;
    getline(cin, line);
    if (line == "1 2 3 4 5 6 7 8") cout << "ascending\n";
    else if (line == "8 7 6 5 4 3 2 1") cout << "descending\n";
    else cout << "mixed\n";
    return 0;
}
