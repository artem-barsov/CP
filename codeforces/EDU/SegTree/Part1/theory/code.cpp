#include <bits/stdc++.h>

using namespace std;

struct SegTree {
    struct Node {
        int min, cnt;
    };
    const Node ZERO = Node{INT_MAX, 1};

    std::vector<long long> tree;
    std::vector<Node> tree_node;
    int size;

    Node combine(Node a, Node b) {
        if (a.min < b.min) return a;
        if (a.min > b.min) return b;
        return Node{a.min, a.cnt + b.cnt};
    }

    void init(int n, int v) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size - 1, v);
    }
    void init_node(int n, Node v) {
        size = 1;
        while (size < n) size *= 2;
        tree_node.assign(2 * size - 1, v);
    }

    void build_sum(std::vector<int>& a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < a.size()) tree[x] = a[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build_sum(a, 2*x+1, lx, m);
        build_sum(a, 2*x+2, m, rx);
        tree[x] = tree[2*x+1] + tree[2*x+2];
    }
    void build_sum(std::vector<int>& a) {
        init(a.size(), 0);
        build_sum(a, 0, 0, size);
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
        init(a.size(), INT_MAX);
        build_min(a, 0, 0, size);
    }

    void build_min_cnt(std::vector<int>& a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < a.size()) tree_node[x] = Node{a[lx], 1};
            return;
        }
        int m = (lx + rx) / 2;
        build_min_cnt(a, x, lx, m);
        build_min_cnt(a, x, m, rx);
        tree_node[x] = combine(tree_node[2*x+1], tree_node[2*x+2]);
    }
    void build_min_cnt(std::vector<int>& a) {
        init_node(a.size(), ZERO);
        build_min_cnt(a, 0, 0, size);
    }

    void set_sum(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
            set_sum(i, v, 2*x+1, lx, m);
        else
            set_sum(i, v, 2*x+2, m, rx);
        tree[x] = tree[2*x+1] + tree[2*x+2];
    }
    void set_sum(int i, int v) {
        set_sum(i, v, 0, 0, size);
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

    void set_min_cnt(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree_node[x] = {v, 1};
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
            set_min_cnt(i, v, 2*x+1, lx, m);
        else
            set_min_cnt(i, v, 2*x+2, m, rx);
        tree_node[x] = combine(tree_node[2*x+1], tree_node[2*x+2]);
    }
    void set_min_cnt(int i, int v) {
        set_min_cnt(i, v, 0, 0, size);
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

    int min(int l, int r, int x, int lx, int rx) {
        if ((r <= lx) || (rx <= l)) return INT_MAX;
        if ((l <= lx) && (rx <= r)) return tree[x];
        int m = (lx + rx) / 2;
        return ::min(min(l, r, 2*x+1, lx, m), min(l, r, 2*x+2, m, rx));
    }
    int min(int l, int r) {
        return min(l, r, 0, 0, size);
    }

    Node min_cnt(int l, int r, int x, int lx, int rx) {
        if ((r <= lx) || (rx <= l)) return ZERO;
        if ((l <= lx) && (rx <= r)) return tree_node[x];
        int m = (lx + rx) / 2;
        Node node1 = min_cnt(l, r, 2*x+1, lx, m);
        Node node2 = min_cnt(l, r, 2*x+2, m, rx);
        return combine(node1, node2);
    }
    Node min_cnt(int l, int r) {
        return min_cnt(l, r, 0, 0, size);
    }
};

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    SegTree st;
    st.build_min_cnt(a);
    while (true) {
        int q, a, b;
        std::cin >> q >> a >> b;
        if (q == 1)
            st.set_min_cnt(a, b);
        else {
            SegTree::Node ans = st.min_cnt(a, b);
            std::cout << ans.min << ' ' << ans.cnt << '\n';
        }
    }
}
