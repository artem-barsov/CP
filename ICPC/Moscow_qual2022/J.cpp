#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;

class SegmentTree {
private:
    int n_;
    vector<int> data_;

public:
    SegmentTree(const vector<int>& values) {
        n_ = values.size();
        data_.resize(4 * n_);
        build(0, 0, n_ - 1, values);
    }
    void build(int id, int sl, int sr, const vector<int>& values) {
        if (sl == sr) {
            data_[id] = values[sl];
            return;
        }
        int m = (sl + sr) / 2;
        build(id * 2 + 1, sl, m, values);
        build(id * 2 + 2, m + 1, sr, values);
        data_[id] = min(data_[id * 2 + 1], data_[id * 2 + 2]);
    }
    int get(int ql, int qr) {
        return get(0, 0, n_ - 1, ql, qr);
    }
    int get(int id, int sl, int sr, int ql, int qr) {
        if (ql <= sl && sr <= qr) {
            return data_[id];
        }
        int m = (sl + sr) / 2;
        if (qr <= m) {
            return get(id * 2 + 1, sl, m, ql, qr);
        }
        if (m < ql) {
            return get(id * 2 + 2, m + 1, sr, ql, qr);
        }
        return min(get(id * 2 + 1, sl, m, ql, qr),
                   get(id * 2 + 2, m + 1, sr, ql, qr));
    }
};

int bal(char ch) {
    return (ch == '(' ? 1 : -1);
}

auto main() -> signed {
//     cin.tie(nullptr);
//     ios::sync_with_stdio(false);
// #ifdef DEBUG
//     freopen("test", "r", stdin);
// #endif

    int n, q;
    cin >> n >> q;

    vector<int> balance(n);
    for (int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;
        balance[i] = bal(ch);
    }
    vector<int> balance_sum(n + 1);

    for (int i = 1; i <= n; ++i) {
        balance_sum[i] = balance_sum[i - 1] + balance[i - 1];
    }

    SegmentTree st2(balance_sum);

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;

        --l, --r;

        auto qr2 = st2.get(l + 1, r + 1);

        int v = 0;
        if (balance[l] != balance[r]) {
            if (balance[l] == 1) {
                v = -1;
            }
        }

        if (qr2 + v < 0) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }

    return 0;
}
