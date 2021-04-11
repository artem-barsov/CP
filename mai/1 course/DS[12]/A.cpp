#include <bits/stdc++.h>

using namespace std;

struct Tsegtree {
    std::vector<unsigned long long> data;
    void bauen(unsigned long long a[], int v, int tl, int tr) {
    	if (tl == tr) data[v] = a[tl];
    	else {
    		int tm = (tl + tr) / 2;
    		bauen(a, v*2, tl, tm);
    		bauen(a, v*2+1, tm+1, tr);
            data[v] = __gcd(data[v*2], data[v*2+1]);
    	}
    }
    unsigned long long get_gcd(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl && r == tr) return data[v];
        int tm = (tl + tr) / 2;
        return __gcd(get_gcd(v*2, tl, tm, l, min(r, tm)), get_gcd(v*2+1, tm+1, tr, max(l,tm+1), r));
    }
};

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    Tsegtree tree;
    tree.data.reserve(4*n);
    std::vector<unsigned long long> a(n);
    for (size_t i = 0; i < n; i++) std::cin >> a[i];
    tree.bauen(a.data(), 1, 0, n-1);
    int k;
    std::cin >> k;
    for (size_t i = 0; i < k; i++) {
        int l, r;
        std::cin >> l >> r;
        std::cout << tree.get_gcd(1, 0, n-1, l-1, r-1) << '\n';
    }
}
