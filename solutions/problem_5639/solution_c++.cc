/*
 * Baekjoon Online Judge #5639
 * https://www.acmicpc.net/problem/5639
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> in_preorder;
int size;

void preorder_to_postorder(int start, int end) {
    if (end - start == 1)
        printf("%d\n", in_preorder[start]);
    else if (end - start == 0)
        return;
    else {
        int left_root = start + 1, right_root;
        for (right_root = left_root; right_root < end; ++right_root)
            if (in_preorder[right_root] > in_preorder[start])
                break;
        preorder_to_postorder(left_root, right_root);
        preorder_to_postorder(right_root, end);
        printf("%d\n", in_preorder[start]);
    }
}

int main() {
	int in_num;
	while (scanf("%d", &in_num) != -1) {
	    in_preorder.push_back(in_num);
	    size++;
	}
	preorder_to_postorder(0, size);
    return 0;
}
