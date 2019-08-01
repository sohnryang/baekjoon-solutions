# 사용한 코드
```python
"""
Baekjoon Online Judge #10775
https://www.acmicpc.net/problem/10775
"""

from sys import stdin

class UnionFind:
    def __init__(self, N):
        self.set_size = [1] * N
        self.num_sets = N
        self.parents = [0] * N
        for i in range(N):
            self.parents[i] = i

    def find_set(self, i):
        if self.parents[i] != i:
            self.parents[i] = self.find_set(self.parents[i])
            return self.parents[i]
        return i

    def same_set(self, i, j):
        return self.find_set(i) == self.find_set(j)

    def union_set(self, i, j):
        if self.same_set(i, j):
            return
        self.num_sets -= 1
        x = self.find_set(i)
        y = self.find_set(j)
        self.parents[x] = y
        self.set_size[x] += self.set_size[y]

G = int(stdin.readline().strip())
P = int(stdin.readline().strip())
ufds = UnionFind(G + 1)
result = 0

for _ in range(P):
    G_i = int(stdin.readline().strip())
    dock = ufds.find_set(G_i)
    if dock == 0:
        break
    ufds.union_set(dock, dock - 1)
    result += 1

print(result)
```

# 사용한 알고리즘
문제를 보면 탐욕법이나 DP를 사용해야 할 것 같지만, 사실 이 문제는 Union-Find Disjoint Set(UFDS)을 이용하여 푸는 문제이다.

보통 UFDS는 [이런](https://www.acmicpc.net/problem/1717) [문제들](https://www.acmicpc.net/problem/1976)에 사용하는 것이 나을 것 같지만 이 문제에서도 요긴하게 쓸 수 있다.

이번 문제에서는 (말로 표현하기는 어렵지만) UFDS의 특성을 이용하여 문제를 빠르게 해결할 수 있다고 할 수 있다.

위에서 작성한 코드가 어떻게 작동하는지 알아보자.

다음과 같은 입력을 받았다고 하자: (문제의 예제 입력 1이다.)

```text
4
3
4
1
1
```

이때 크기가 5인 UFDS를 하나 만든다.

```python
[0, 1, 2, 3, 4]
```

첫 번째 비행기는 1번째 게이트부터 4번째 게이트까지 어디든 갈 수 있다. 다음 비행기들이 최대한 도킹할 수 있으려면 가능한 번호가 큰 게이트로 가야 할 것이다. UFDS에서 4를 `Find`하면 4이므로 비행기는 4번 게이트에 도킹하고, 4번과 4 - 1번 집합을 `Union` 연산으로 합친다. (여기서 3이 4의 parent가 되도록 합쳐져야 한다. 이를 위해서는 만약 구현했을 경우, union-by-rank 최적화를 하면 안 된다. 구현에 따라 다르지만, union-by-rank 때문에 4가 3의 parent가 되는 경우가 생길 수도 있다.)

```python
[0, 1, 2, (3, 4)]
```

왜 4번 집합과 4 - 1번 집합을 합치는지 의문이 들 것이다.

그 이유는 UFDS의 효율성을 최대한 이용하기 위해서이다. 예를 들어, (예제 입력에서는 그렇지 않지만) 다음 비행기도 1번~4번 게이트 중 하나에 도킹해야 할 경우, 4가 속한 집합 (즉, 4를 리프로 하는 트리의 루트)를 구하기만 하면 어디에 도킹해야 하는지를 알 수 있다. 만약 UFDS를 사용하지 않고, 루프를 돌면서 확인했다면 각 비행기 당 $\mathscr{O}(N)$의 시간이 걸린다. 반면, UFDS `Find` 연산의 시간 복잡도는 $\mathscr{O}(\alpha(N)) \approx \mathscr{O}(1)$이므로 훨씬 빠르게 어디에 도킹할지를 정할 수 있다.

두 번째 비행기는 1번째 게이트에만 도킹할 수 있다. 1을 `Find`하면 1이므로 1번과 1 - 1번 집합을 `Union`한다.

```python
[(0, 1), 2, (3, 4)]
```

세 번째 비행기도 두 번째 비행기처럼 1번 게이트에만 도킹할 수 있다. 1을 `Find`하면 0이다. 이는 도킹할 수 있는 게이트가 없다는 의미이므로 더 이상 실행하지 못한다는 의미이다.
