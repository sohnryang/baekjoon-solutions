/*
 * Baekjoon Online Judge #3217
 * https://www.acmicpc.net/problem/3217
 */

#include <algorithm>
#include <ios>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

int N;
string line;
unordered_map<string, pair<int, int>> vars;
list<pair<int, int>> blocks;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  blocks.push_back({1, 100000});
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> line;
    int open_pos = line.find('(');
    int close_pos = line.find(')');
    string paren_content = line.substr(open_pos + 1, close_pos - open_pos - 1);

    if (line.find('=') != string::npos) {
      string var_name = line.substr(0, 4);
      int size = stoi(paren_content);
      auto it = blocks.begin();
      for (; it != blocks.end(); ++it)
        if (it->second - it->first + 1 >= size)
          break;
      if (it == blocks.end()) {
        vars[var_name] = {0, 0};
        continue;
      }
      int addr = it->first;
      it->first += size;
      vars[var_name] = {addr, addr + size - 1};
      if (it->first > it->second)
        blocks.erase(it);
    } else if (line.substr(0, 5) == "free(") {
      if (!vars.count(paren_content) || vars[paren_content].first == 0)
        continue;
      auto it = blocks.begin();
      for (; it != blocks.end(); ++it)
        if (vars[paren_content].first < it->first)
          break;
      if (it == blocks.end()) {
        blocks.push_back(vars[paren_content]);
        it = prev(blocks.end());
      } else {
        blocks.insert(it, vars[paren_content]);
        it--;
      }
      if (it != blocks.begin()) {
        auto it_prev = prev(it);
        if (it->first - it_prev->second == 1) {
          it_prev->second = it->second;
          blocks.erase(it);
          it = it_prev;
        }
      }
      if (it != prev(blocks.end())) {
        auto it_next = next(it);
        if (it_next->first - it->second == 1) {
          it->second = it_next->second;
          blocks.erase(it_next);
        }
      }
      vars[paren_content] = {0, 0};
    } else {
      if (vars.count(paren_content))
        cout << vars[paren_content].first << "\n";
      else
        cout << "0\n";
    }
  }

  return 0;
}
