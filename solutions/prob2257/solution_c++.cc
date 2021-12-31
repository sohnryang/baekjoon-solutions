/*
 * Baekjoon Online Judge #2257
 * https://www.acmicpc.net/problem/2257
 */

#include <ios>
#include <iostream>
#include <string>

using namespace std;

string S;

inline bool is_numeric(char ch) { return '0' <= ch && ch <= '9'; }

int f(string::iterator &it) {
  int res = 0;
  while (it < S.end()) {
    char ch = *it;
    if (ch == '(') {
      int m = f(++it);
      if (it == S.end())
        return res + m;
      else if (is_numeric(*it)) {
        int mul = (*it) - '0';
        res += mul * m;
        it++;
      } else
        res += m;
    } else if (ch == ')') {
      it++;
      return res;
    } else {
      int m;
      switch (ch) {
      case 'C':
        m = 12;
        break;
      case 'O':
        m = 16;
        break;
      case 'H':
        m = 1;
        break;
      }
      it++;
      if (it == S.end())
        return res + m;
      else if (is_numeric(*it)) {
        int mul = (*it) - '0';
        res += mul * m;
        it++;
      } else
        res += m;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> S;
  string::iterator it = S.begin();
  cout << f(it) << "\n";

  return 0;
}
