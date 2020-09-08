#include <bits/stdc++.h>

using namespace std;

struct SegTree {
    std::vector<long long> tree;
    int size;

    void init(int n, int v) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size - 1, v);
    }

    void build_min(std::vector<int>& a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < a.size()) tree[x] = a[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build_min(a, 2*x+1, lx, m);
        build_min(a, 2*x+2, m, rx);
        tree[x] = ::min(tree[2*x+1], tree[2*x+2]);
    }
    void build_min(std::vector<int>& a) {
        init(a.size(), 1e9+1);
        build_min(a, 0, 0, size);
    }

    void set_min(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
            set_min(i, v, 2*x+1, lx, m);
        else
            set_min(i, v, 2*x+2, m, rx);
        tree[x] = ::min(tree[2*x+1], tree[2*x+2]);
    }
    void set_min(int i, int v) {
        set_min(i, v, 0, 0, size);
    }

    int min(int l, int r, int x, int lx, int rx) {
        if ((r <= lx) || (rx <= l)) return 1e9+1;
        if ((l <= lx) && (rx <= r)) return tree[x];
        int m = (lx + rx) / 2;
        return ::min(min(l, r, 2*x+1, lx, m), min(l, r, 2*x+2, m, rx));
    }
    int min(int l, int r) {
        return min(l, r, 0, 0, size);
    }
};

int main(int argc, char const *argv[]) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    SegTree st;
    st.build_min(a);
    for (int i = 0; i < m; i++) {
        int q, a, b;
        std::cin >> q >> a >> b;
        if (q == 1)
            st.set_min(a, b);
        else
            std::cout << st.min(a, b) << '\n';
    }
}
