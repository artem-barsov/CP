#include <bits/stdc++.h>

using namespace std;

mt19937 rng;
struct Node {
	int prior, value, cnt, max;
	bool rev;
	Node* l, * r;
	Node(int value) : value(value), prior(rng()), max(value), l(nullptr), r(nullptr) {}
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
	upd_max(t);
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
	upd_max(t);
}

void insert(Node* & t, Node* it, int pos) {
	Node *t1, *t2;
	split(t, t1, t2, pos);
	merge(t1, t1, it);
	merge(t, t1, t2);
	upd_cnt(t);
	upd_max(t);
}

void move_to_begin(Node* & t, int l, int r) {
	Node * t1, *t2, *t3;
	split(t, t1, t2, l);
	split(t2, t2, t3, r-l+1);
	merge(t2, t2, t1);
	merge(t, t2, t3);
	// upd_cnt(t);
	// upd_max(t);
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

void reverse(Node* &t, int l, int r) {
	Node* t1, * t2, * t3;
	split(t, t1, t2, l);
	split(t2, t2, t3, r-l+1);
	t2->rev ^= true;
	merge(t, t1, t2);
	merge(t, t, t3);
}

void output(Node* t) {
	if (!t) return;
	push(t);
	output(t->l);
	std::cout << t->value << ' ';
	output(t->r);
}

int main(int argc, char const *argv[]) {
	Node* treap = nullptr;
	insert(treap, new Node(1), 0);
	insert(treap, new Node(2), 1);
	insert(treap, new Node(3), 2);
	insert(treap, new Node(4), 0);
	insert(treap, new Node(5), 2);
	output(treap);
	std::cout << '\n';
	reverse(treap, 0, 4);
	output(treap);
}
