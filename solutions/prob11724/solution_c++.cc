/*
 * Baekjoon Online Judge #11724
 * https://www.acmicpc.net/problem/11724
 */

#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAX_N = 1001;
int N, M;
bool visited[MAX_N];
vector<int> graph[MAX_N];

void dfs(int start) {
  visited[start] = true;
  for (int nextpoint: graph[start])
    if (!visited[nextpoint])
      dfs(nextpoint);
}

int count_components() {
	int result = 0;
  for (int i = 1; i <= N; ++i) {
    if (visited[i]) continue;
    dfs(i);
    result++;
  }
  return result;
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < M; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  memset(visited, false, sizeof(visited));
  printf("%d\n", count_components());
  return 0;
}
