#include <bits/stdc++.h>

using namespace std;

struct Node {
	int key, prior, cnt;
	Node * l, * r;
	Node() { }
	Node(int key, int prior) : key(key), prior(prior), l(nullptr), r(nullptr) { }
};

int cnt(Node* t) {
	return t ? t->cnt : 0;
}

void upd_cnt(Node* t) {
	if (t) t->cnt = 1 + cnt(t->l) + cnt(t->r);
}

void split(Node* t, int key, Node* & l, Node* & r) {
	if (!t) l = r = NULL;
	else if (key < t->key)
		split(t->l, key, l, t->l), r = t;
	else split(t->r, key, t->r, r), l = t;
	upd_cnt(t);
}

void insert(Node* & t, Node* it) {
	if (!t) t = it;
	else if (it->prior > t->prior) {
        split(t, it->key, it->l, it->r);
        t = it;
    }
	else insert(it->key < t->key ? t->l : t->r, it);
	upd_cnt(t);
}

void merge(Node* & t, Node* l, Node* r) {
	if (!l || !r) t = l ? l : r;
	else if (l->prior > r->prior)
		merge(l->r, l->r, r), t = l;
	else merge(r->l, l, r->l), t = r;
	upd_cnt(t);
}

void erase(Node* & t, int key) {
	if (t->key == key) merge(t, t->l, t->r);
	else erase(key < t->key ? t->l : t->r, key);
	upd_cnt(t);
}

Node* unite(Node* l, Node* r) {
	if (!l || !r) return l ? l : r;
	if (l->prior < r->prior) swap(l, r);
	Node* lt, * rt;
	split(r, l->key, lt, rt);
	l->l = unite(l->l, lt);
	l->r = unite(l->r, rt);
	return l;
}

int main(int argc, char const *argv[]) {
    Node* treap = nullptr;
    insert(treap, new Node(3, 3));
    insert(treap, new Node(2, 1));
    insert(treap, new Node(1, 2));
    insert(treap, new Node(5, 4));
    insert(treap, new Node(4, 5));
    insert(treap, new Node(0, 0));

	std::cout << cnt(treap) << '\n';

    std::cout << treap->key << ' ' << treap->prior << '\n';
    std::cout << treap->l->key << ' ' << treap->l->prior << '\n';
    std::cout << treap->l->l->key << ' ' << treap->l->l->prior << '\n';
    std::cout << treap->l->l->l->key << ' ' << treap->l->l->l->prior << '\n';
 // std::cout << treap->l->l->l->l->key << ' ' << treap->l->l->l->l->prior << '\n';
 // std::cout << treap->l->l->l->r->key << ' ' << treap->l->l->l->r->prior << '\n';
    std::cout << treap->l->l->r->key << ' ' << treap->l->l->r->prior << '\n';
 // std::cout << treap->l->l->r->l->key << ' ' << treap->l->l->r->l->prior << '\n';
 // std::cout << treap->l->l->r->r->key << ' ' << treap->l->l->r->r->prior << '\n';
 // std::cout << treap->l->r->key << ' ' << treap->l->r->prior << '\n';
    std::cout << treap->r->key << ' ' << treap->r->prior << '\n';
 // std::cout << treap->r->l->key << ' ' << treap->r->l->prior << '\n';
 // std::cout << treap->r->r->key << ' ' << treap->r->r->prior << '\n';
}
//       4,5
//     3,3 5,4
//   1,2
// 0,0 2,1
