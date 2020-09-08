#include <bits/stdc++.h>

using namespace std;

struct SegTree {
    std::vector<long long> tree;
    int size;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size - 1, 0);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
            set(i, v, 2*x+1, lx, m);
        else
            set(i, v, 2*x+2, m, rx);
        tree[x] = tree[2*x+1] + tree[2*x+2];
    }
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    long long sum(int l, int r, int x, int lx, int rx) {
        if ((r <= lx) || (rx <= l)) return 0;
        if ((l <= lx) && (rx <= r)) return tree[x];
        int m = (lx + rx) / 2;
        return sum(l, r, 2*x+1, lx, m) + sum(l, r, 2*x+2, m, rx);
    }
    long long sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

int main(int argc, char const *argv[]) {
    int n, m;
    std::cin >> n >> m;
    SegTree st;
    st.init(n);
    for (size_t i = 0; i < n; i++) {
        int v;
        std::cin >> v;
        st.set(i, v);
    }
    for (size_t i = 0; i < m; i++) {
        int q, a, b;
        std::cin >> q >> a >> b;
        if (q == 1)
            st.set(a, b);
        else
            std::cout << st.sum(a, b) << '\n';
    }
}
