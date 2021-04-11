#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

mt19937 rng;
struct Node {
	int prior, value, cnt, max;
	Node* l, * r;
	Node(int value) : value(value), prior(rng()), max(value), l(nullptr), r(nullptr) {}
};

int cnt(Node* it) {
	return it ? it->cnt : 0;
}

void upd_cnt(Node* it) {
	if (it) it->cnt = cnt(it->l) + cnt(it->r) + 1;
}

int max(Node* it) {
    return it ? it->max : INT_MIN;
}

void upd_max(Node* it) {
    if (it) it->max = max(max(max(it->l), max(it->r)), it->value);
}

void merge(Node* & t, Node* l, Node* r) {
	if (!l || !r) t = l ? l : r;
	else if (l->prior > r->prior)
		merge(l->r, l->r, r), t = l;
	else merge(r->l, l, r->l), t = r;
	upd_cnt(t);
    upd_max(t);
}

void split(Node* t, Node* & l, Node* & r, int key, int add = 0) {
	if (!t) return void( l = r = 0 );
	int cur_key = add + cnt(t->l);
	if (key <= cur_key)
		split(t->l, l, t->l, key, add), r = t;
	else split(t->r, t->r, r, key, add + 1 + cnt(t->l)), l = t;
	upd_cnt(t);
    upd_max(t);
}

void insert(Node* & t, Node* it, int pos) {
	Node * t1, * t2;
	split(t, t1, t2, pos);
	merge(t1, t1, it);
	merge(t, t1, t2);
	upd_cnt(t);
    upd_max(t);
}

int maximum(Node* t, int l, int r) {
    Node * t1, *t2, *t3;
    split(t, t1, t2, l);
    split(t2, t2, t3, r-l+1);
    int res = max(t2);
    merge(t, t1, t2);
    merge(t, t, t3);
    return res;
}

void inorder(Node* t) {
	if (!t) return;
	inorder(t->l);
    std::cout << t->value << ' ';
	inorder(t->r);
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	Node* treap = nullptr;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int q, v, p, l, r;
        std::cin >> q;
        if (q == 1) {
            std::cin >> v >> p;
            insert(treap, new Node(v), p);
        }
        else {
            std::cin >> l >> r;
            std::cout << maximum(treap, l-1, r-1) << '\n';
        }
    }
}
