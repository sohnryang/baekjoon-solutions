/*
 * Baekjoon Online Judge #2261
 * https://www.acmicpc.net/problem/2261
 */

#include <algorithm>
#include <cmath>
#include <ios>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

int dist(pair<int, int> x, pair<int, int> y) {
  return (x.first - y.first) * (x.first - y.first) +
         (x.second - y.second) * (x.second - y.second);
}

int N;
vector<pair<int, int>> points;

bool cmp(const pair<int, int> &x, const pair<int, int> &y) {
  return x.second < y.second;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int X, Y;
    cin >> X >> Y;
    points.push_back({Y, X});
  }
  sort(points.begin(), points.end(), cmp);
  set<pair<int, int>> cands;
  cands.insert(points[0]);
  cands.insert(points[1]);
  int result = dist(points[0], points[1]);
  int start = 0;
  for (int i = 2; i < N; ++i) {
    auto current = points[i];
    while (start < i) {
      auto p = points[start];
      int xdist = p.second - current.second;
      if (xdist * xdist > result) {
        cands.erase(p);
        start++;
      } else
        break;
    }
    int d = sqrt(result) + 1;
    pair<int, int> lower_point = {current.first - d, -1e5};
    pair<int, int> upper_point = {current.first + d, 1e5};
    auto lower = cands.lower_bound(lower_point);
    auto upper = cands.upper_bound(upper_point);
    for (auto it = lower; it != upper; ++it) {
      int d = dist(current, *it);
      result = min(result, d);
    }
    cands.insert(current);
  }
  cout << result << '\n';
  return 0;
}
