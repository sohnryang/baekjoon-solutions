/*
 * Baekjoon Online Judge #1662
 * https://www.acmicpc.net/problem/1662
 */

#include <ios>
#include <iostream>
#include <string>

using namespace std;

const int MAX_LEN = 51;
string S;

int f(string::iterator &it) {
  int res = 0;
  while (it < S.end()) {
    char curr = *it;
    if (it + 1 == S.end()) {
      res += (curr != ')');
      return res;
    }
    if (curr == ')') {
      it++;
      return res;
    }
    char ahead = *(it + 1);
    if (ahead == '(') {
      it += 2;
      res += (int)(curr - '0') * f(it);
    } else {
      it++;
      res++;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> S;
  auto it = S.begin();
  cout << f(it) << "\n";

  return 0;
}
