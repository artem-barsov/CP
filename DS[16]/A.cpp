#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

struct Node {
	int key, prior;
	Node * l, * r;
	Node (int key, int prior) : key(key), prior(prior), l(nullptr), r(nullptr) { }
};

void split (Node* t, int key, Node* & l, Node* & r) {
	if (!t)
		l = r = NULL;
	else if (key < t->key) {
		split (t->l, key, l, t->l);
		r = t;
	}
	else {
		split (t->r, key, t->r, r);
		l = t;
	}
}

void insert (Node* & t, Node* it) {
	if (!t)
		t = it;
	else if (it->prior > t->prior) {
        split (t, it->key, it->l, it->r);
        t = it;
    }
	else
		insert (it->key < t->key ? t->l : t->r, it);
}

void preorder(Node* treap) {
	if (treap) {
		std::cout << treap->key << ' ' << treap->prior << '\n';
		preorder(treap->l);
		preorder(treap->r);
	}
	else std::cout << "null" << '\n';
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	std::cin >> n;
    Node* treap = nullptr;
	for (int i = 0; i < n; i++) {
		int k, p;
		std::cin >> k >> p;
		insert(treap, new Node(k, p));
	}
	preorder(treap);
}
