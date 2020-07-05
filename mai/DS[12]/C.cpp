#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

struct Tsegtree {
    std::vector<long long> data;
    void bauen (long long a[], int v, int tl, int tr) {
    	if (tl == tr)
    		data[v] = a[tl];
    	else {
    		int tm = (tl + tr) >> 1;
    		bauen (a, v<<1, tl, tm);
    		bauen (a, (v<<1)+1, tm+1, tr);
    		data[v] = data[v<<1] + data[(v<<1)+1];
    	}
    }

    long long sum (int v, int tl, int tr, int l, int r) {
    	if (l > r)
    		return 0;
    	if (l == tl && r == tr)
    		return data[v];
    	int tm = (tl + tr) >> 1;
    	return sum (v<<1, tl, tm, l, min(r,tm)) +
               sum ((v<<1)+1, tm+1, tr, max(l,tm+1), r);
    }

    void add(int v, int tl, int tr, int pos, long long toadd) {
    	if (tl == tr)
    		data[v] += toadd;
    	else {
    		int tm = (tl + tr) >> 1;
    		if (pos <= tm)
    			add(v<<1, tl, tm, pos, toadd);
    		else
    			add((v<<1)+1, tm+1, tr, pos, toadd);
    		data[v] = data[v<<1] + data[(v<<1)+1];
    	}
    }
};

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    std::cin >> n;
    Tsegtree tree;
    tree.data.reserve(4*n);
    std::vector<long long> a(n);
    for (size_t i = 0; i < n; i++) std::cin >> a[i];
    tree.bauen(a.data(), 1, 0, n-1);
    int k;
    std::cin >> k;
    for (size_t i = 0; i < k; i++) {
        int q, l, r;
        std::cin >> q >> l >> r;
        if (q == 0) {
            std::cout << tree.sum(1, 0, n-1, l-1, r-1) << '\n';
        } else {
            tree.add(1, 0, n-1, l-1, r);
        }
    }
}
