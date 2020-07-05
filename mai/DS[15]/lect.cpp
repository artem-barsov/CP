// g++ -g3 lect.cpp
// valgrind ./a.out
// g++ -D debug lect.cpp
#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    int data;
};

struct SegmentTree {
    int n;
    Node* root = nullptr;

    Node* set(Node* node, int sl, int sr, int p, int x) {
        if (node == nullptr) {
            node = new Node;
        }
        if (sl == sr) {
            node->data = x;
            return node;
        }
        int m = (sl+sr)/2;
        if (p <= m) {
            root->left = set(node->left, sl, m, p, x);
        }
        else {
            root->right = set(node->right, m+1, sr, p, x);
        }
        node->data = max(node_data(node->left), node_data(node->right));
        return node;
    }

    void set(int p, int x) {
        root = set(root, 0, n-1, p, x);
    }

    int node_data(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->data;
    }

    int get(Node* node, int sl, int sr, int ql, int qr) {
        if (node == nullptr) {
            return 0;
        }
        if ((ql <= sl) && (sr <= qr)) {
            return node_data(node);
        }
        int m = (sl+sr)/2;
        if (qr <= m) {
            return get(node->left, sl, m, ql, qr);
        }
        if (m < ql) {
            return get(node->right, m+1, sr, ql, qr);
        }
        return max(get(node->left, sl, m, ql, qr), get(node->right, m+1, sr, ql, qr));
    }

    SegmentTree(int n_) {
        n = n_;
    }
};


int main(int argc, char const *argv[]) {

}
