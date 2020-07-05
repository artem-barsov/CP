#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

mt19937 rng;
struct Node {
	int prior, value, cnt;
	bool rev;
	Node* l, * r;
	Node(int value) : value(value), prior(rng()), l(nullptr), r(nullptr) {}
};

int cnt(Node* it) {
	return it ? it->cnt : 0;
}

void upd_cnt(Node* it) {
	if (it)
		it->cnt = cnt(it->l) + cnt(it->r) + 1;
}

void push(Node* it) {
	if (it && it->rev) {
		it->rev = false;
		swap(it->l, it->r);
		if (it->l) it->l->rev ^= true;
		if (it->r) it->r->rev ^= true;
	}
}

void merge(Node* & t, Node* l, Node* r) {
	push(l);
	push(r);
	if (!l || !r)
		t = l ? l : r;
	else if (l->prior > r->prior)
		merge(l->r, l->r, r), t = l;
	else
		merge(r->l, l, r->l), t = r;
	upd_cnt(t);
}

void split(Node* t, Node* & l, Node* & r, int key, int add = 0) {
	if (!t)
		return void( l = r = 0 );
	push(t);
	int cur_key = add + cnt(t->l);
	if (key <= cur_key)
		split(t->l, l, t->l, key, add), r = t;
	else
		split(t->r, t->r, r, key, add + 1 + cnt(t->l)), l = t;
	upd_cnt(t);
}

void insert(Node* & t, Node* it, int pos) {
	Node * t1 = nullptr, * t2 = nullptr;
	split(t, t1, t2, pos);
	merge(t1, t1, it);
	merge(t, t1, t2);
	upd_cnt(t);
}

void inorder(Node* t) {
	if (!t) return;
	push(t);
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
        int v, p;
        std::cin >> v >> p;
        insert(treap, new Node(v), p);
    }
	inorder(treap);
}
