/*
 * Baekjoon Online Judge #12899
 * https://www.acmicpc.net/problem/12899
 */

#include <cstdio>
#include <cstdlib>
#include <limits>
#include <utility>

using namespace std;

typedef int ktype;

struct treap_node {
    ktype key;
    int priority, size;
    treap_node *left, *right;
    treap_node(const ktype& _key): key(_key), priority(rand()), size(1),
                                   left(nullptr), right(nullptr) {}

    void set_left(treap_node* new_left) {
        left = new_left;
        calc_size();
    }

    void set_right(treap_node* new_right) {
        right = new_right;
        calc_size();
    }

    void calc_size() {
        size = 1;
        if (left) size += left->size;
        if (right) size += right->size;
    }
};

typedef pair<treap_node*, treap_node*> node_pair;

node_pair split(treap_node* root, ktype key) {
    if (root == nullptr) return node_pair(nullptr, nullptr);
    if (root->key < key) {
        node_pair rs = split(root->right, key);
        root->set_right(rs.first);
        return node_pair(root, rs.second);
    }
    node_pair ls = split(root->left, key);
    root->set_left(ls.second);
    return node_pair(ls.first, root);
}

treap_node* insert(treap_node* root, treap_node* node) {
    if (root == nullptr) return node;
    if (root->priority < node->priority) {
        node_pair splitted = split(root, node->key);
        node->set_left(splitted.first);
        node->set_right(splitted.second);
        return node;
    } else if (node->key < root->key) {
        root->set_left(insert(root->left, node));
    } else {
        root->set_right(insert(root->right, node));
    }
    return root;
}

treap_node* merge(treap_node* a, treap_node* b) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;
    if (a->priority < b->priority) {
        b->set_left(merge(a, b->left));
        return b;
    }
    a->set_right(merge(a->right, b));
    return a;
}

treap_node* erase(treap_node* root, ktype key) {
    if (root == nullptr) return root;
    if (root->key == key) {
        treap_node* ret = merge(root->left, root->right);
        delete root;
        return ret;
    }
    if (key < root->key) {
        root->set_left(erase(root->left, key));
    } else {
        root->set_right(erase(root->right, key));
    }
    return root;
}

treap_node* kth(treap_node* root, int k) {
    int left_size = 0;
    if (root->left != nullptr) left_size = root->left->size;
    if (k <= left_size) return kth(root->left, k);
    if (k == left_size + 1) return root;
    return kth(root->right, k - left_size - 1);
}

int less_than(treap_node* root, ktype key) {
    if (root == nullptr) return 0;
    if (root->key >= key) return less_than(root->left, key);
    int ls = (root->left ? root->left->size : 0);
    return ls + 1 + less_than(root->right, key);
}

int main() {
    int N;
    scanf("%d", &N);
    treap_node* treap = nullptr;
    for (int _ = 0; _ < N; ++_) {
        int T, X;
        scanf("%d %d", &T, &X);
        if (T == 1) treap = insert(treap, new treap_node(X));
        else {
            treap_node* node = kth(treap, X);
            printf("%d\n", node->key);
            treap = erase(treap, node->key);
        }
    }
    return 0;
}
