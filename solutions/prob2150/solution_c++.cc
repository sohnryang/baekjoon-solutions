/*
 * Baekjoon Online Judge #2150
 * https://www.acmicpc.net/problem/2150
 */

#include <algorithm>
#include <ios>
#include <iostream>
#include <list>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

const int MAX_V = 10'001;
int V, E, scc_counter, vertex_counter;
vector<int> graph[MAX_V], scc_id, visited;
stack<int> s;

int scc(int v) {
  int result = visited[v] = vertex_counter++;
  s.push(v);
  for (int u : graph[v]) {
    if (visited[u] == -1)
      result = min(result, scc(u));
    else if (scc_id[u] == -1)
      result = min(result, visited[u]);
  }
  if (result == visited[v]) {
    while (true) {
      int t = s.top();
      s.pop();
      scc_id[t] = scc_counter;
      if (t == v)
        break;
    }
    ++scc_counter;
  }
  return result;
}

vector<int> tarjan_scc() {
  scc_id = visited = vector<int>(V + 1, -1);
  scc_counter = vertex_counter = 0;
  for (int i = 1; i <= V; ++i)
    if (visited[i] == -1)
      scc(i);
  return scc_id;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> V >> E;
  for (int i = 0; i < E; ++i) {
    int s, d;
    cin >> s >> d;
    graph[s].push_back(d);
  }
  tarjan_scc();

  cout << scc_counter << "\n";
  unordered_map<int, vector<int>> scc_table;
  for (int i = 1; i <= V; ++i)
    scc_table[scc_id[i]].push_back(i);
  for (int i = 1; i <= V; ++i) {
    if (scc_table.count(scc_id[i]) == 0)
      continue;
    for (int v : scc_table[scc_id[i]])
      cout << v << " ";
    scc_table.erase(scc_id[i]);
    cout << "-1\n";
  }
  return 0;
}
