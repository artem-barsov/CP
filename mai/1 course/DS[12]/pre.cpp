#include <bits/stdc++.h>

using namespace std;
struct Tsegtree {
    std::vector<int> t;
    void build (int a[], int v, int tl, int tr) {
    	if (tl == tr)
    		t[v] = a[tl];
    	else {
    		int tm = (tl + tr) / 2;
    		build (a, v*2, tl, tm);
    		build (a, v*2+1, tm+1, tr);
    		t[v] = t[v*2] + t[v*2+1];
            // t[v] = __gcd(t[v*2], t[v*2+1]);
    	}
    }

    int sum (int v, int tl, int tr, int l, int r) {
    	if (l > r)
    		return 0;
    	if (l == tl && r == tr)
    		return t[v];
    	int tm = (tl + tr) / 2;
    	return sum (v*2, tl, tm, l, min(r,tm)) +
               sum (v*2+1, tm+1, tr, max(l,tm+1), r);
    }

    // int get_gcd(int v, int tl, int tr, int l, int r) {
    //     if (l > r) return 0;
    //     if (l == tl && r == tr) return t[v];
    //     int tm = (tl + tr) / 2;
    //     // return get_gcd(v*2, tl, tm, l, min(r, tm))+get_gcd(v*2+1, tm+1, tr, max(l,tm+1), r);
    //     return __gcd(get_gcd(v*2, tl, tm, l, min(r, tm)), get_gcd(v*2+1, tm+1, tr, max(l,tm+1), r));
    // }

    void update (int v, int tl, int tr, int pos, int new_val) {
    	if (tl == tr)
    		t[v] = new_val;
    	else {
    		int tm = (tl + tr) / 2;
    		if (pos <= tm)
    			update (v*2, tl, tm, pos, new_val);
    		else
    			update (v*2+1, tm+1, tr, pos, new_val);
    		t[v] = t[v*2] + t[v*2+1];
    	}
    }
};

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    Tsegtree tree;
    tree.t.reserve(4*n);
    std::vector<int> a(n);
    for (size_t i = 0; i < n; i++) std::cin >> a[i];
    tree.build(a.data(), 1, 0, n-1);
    int k;
    std::cin >> k;
    for (size_t i = 0; i < k; i++) {
        int l, r;
        std::cin >> l >> r;
        std::cout << tree.get_gcd(1, 0, n-1, l-1, r-1) << '\n';
    }
}
