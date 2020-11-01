#include <bits/stdc++.h>

using namespace std;

vector<int> p;
typedef long long int ll;

class SegmentTree {
private:
    struct Node {
        int idx;
        ll max, opv;
        Node() : idx(0), max(0), opv(0) { }
    };
    std::vector<Node> m_tree;
    size_t m_size;
public:
    SegmentTree(size_t size) {
        m_size = 1;
        while (m_size < size) m_size <<= 1;
        m_tree.assign(2 * m_size - 1, {});
        fill(0, m_size, 0);
    }
    ll get_max() {
        return m_tree[0].idx;
    }
    void set_add(size_t l, size_t r, ll v) {
        if ((r - l) != 0) {
            set_add(0, m_size, 0, l, r, v);
        }
    }
    void reset(size_t i) {
        reset(0, m_size, 0, i);
    }
private:
    void fill(size_t lx, size_t rx, size_t ti) {
        if ((rx - lx) == 1) {
            if (lx < p.size()) {
                m_tree[ti].max = p[lx];
                m_tree[ti].idx = lx;
            }
            else {
                m_tree[ti].max = -10000000;
                m_tree[ti].idx = lx;
            }
            return;
        }
        size_t m = lx + (rx - lx) / 2;
        size_t lc = 2 * ti + 1;
        size_t rc = 2 * ti + 2;
        fill(lx, m, lc);
        fill(m, rx, rc);
        Node& ln = m_tree[lc];
        Node& rn = m_tree[rc];
        Node& cn = m_tree[ti];
        if (ln.max >= rn.max) {
            cn.max = ln.max;
            cn.idx = ln.idx;
        }
        else {
            cn.max = rn.max;
            cn.idx = rn.idx;
        }
    }
    void set_add(size_t lx, size_t rx, size_t ti, size_t l, size_t r, ll v) {
        Node& cr = m_tree[ti];
        if (lx >= l && rx <= r) {
            cr.max += v;
            cr.opv += v;
            return;
        }
        size_t m = lx + (rx - lx) / 2;
        size_t lc = 2 * ti + 1;
        size_t rc = 2 * ti + 2;
        Node& pl = m_tree[lc];
        Node& pr = m_tree[rc];
        if (cr.opv) {
            pl.max += cr.opv;
            pl.opv += cr.opv;
            pr.max += cr.opv;
            pr.opv += cr.opv;
            cr.opv = 0;
        }
        if (l < m) {
            set_add(lx, m, lc, l, r, v);
        }
        if (r > m) {
            set_add(m, rx, rc, l, r, v);
        }
        if (pl.max >= pr.max) {
            cr.max = pl.max;
            cr.idx = pl.idx;
        }
        else {
            cr.max = pr.max;
            cr.idx = pr.idx;
        }
    }
    void reset(size_t lx, size_t rx, size_t ti, size_t i) {
        Node& cr = m_tree[ti];
        size_t m = rx - lx;
        if (m == 1) {
            cr.max = p[lx];
            return;
        }
        m >>= 1;
        size_t lc = 2 * ti + 1;
        size_t rc = 2 * ti + 2;
        Node& pl = m_tree[lc];
        Node& pr = m_tree[rc];
        if (cr.opv) {
            pl.max += cr.opv;
            pl.opv += cr.opv;
            pr.max += cr.opv;
            pr.opv += cr.opv;
            cr.opv = 0;
        }
        m += lx;
        if (i < m) {
            reset(lx, m, lc, i);
        }
        else {
            reset(m, rx, rc, i);
        }
        if (pl.max >= pr.max) {
            cr.max = pl.max;
            cr.idx = pl.idx;
        }
        else {
            cr.max = pr.max;
            cr.idx = pr.idx;
        }
    }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, t;
    cin >> n >> t;
    p.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    SegmentTree tree(n);
    std::vector<int> answ(n, 0);
    for (int i = 0; i < t; ++i) {
        int m_index = tree.get_max();
        tree.reset(m_index);
        tree.set_add(0, m_index, 1);
        tree.set_add(m_index + 1, n, 1);
        ++answ[m_index];
    }
    for (int i = 0; i < n; ++i) {
        cout << answ[i] << ' ';
    }
    cout << '\n';
}
