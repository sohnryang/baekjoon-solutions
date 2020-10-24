/*
 * Baekjoon Online Judge #11004
 * https://www.acmicpc.net/problem/11004
 */
 
#include <algorithm>
#include <cstdio>
#include <vector>
 
using namespace std;
 
int main() {
    int input_n, input_k;
    scanf("%d %d", &input_n, &input_k);
    vector<int> arr;
 
    for (int i = 0; i < input_n; ++i) {
        int n;
        scanf("%d", &n);
        arr.push_back(n);
    }
 
    nth_element(arr.begin(), arr.begin() + input_k - 1, arr.end());
    printf("%d", arr[input_k - 1]);
 
    return 0;
}
