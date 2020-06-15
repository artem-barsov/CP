#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
    int n;
    std::vector<int> data;
    std::vector<int> delay;

    // void bauen(unsigned long long a[], int v, int tl, int tr) {
    // 	if (tl == tr) data[v] = a[tl];
    // 	else {
    // 		int tm = (tl + tr) / 2;
    // 		bauen(a, v*2, tl, tm);
    // 		bauen(a, v*2+1, tm+1, tr);
    //         data[v] = __gcd(data[v*2], data[v*2+1]);
    // 	}
    // }

    void add(int id, int sl, int sr, int ql, int qr, int x) {
        if ((ql <= sl) && (sr <= qr)) {
            delay[id] += x;
            return;
        }
        push(id, sl, sr);
        int m = (sl + sr) / 2;
        if (ql <= m) {
            add(id*2+1, sl, m, ql, qr, x);
        }
        if (m < qr) {
            add(id*2+2, m+1, sr, ql, qr, x);
        }
        data[id] = max(data[id*2+1], data[id*2+2]);
        data[id] = max(get(id*2+1, sl, m, sl, m), get(id*2+2, sr, m+1, sr, m+1));
    }

    void push(int id, int sl, int sr) {
        data[id] += delay[id];
        if (sl != sr) {
            delay[id*2+1] += delay[id];
            delay[id*2+2] += delay[id];
        }
        delay[id] = 0;
    }

    int get(int id, int sl, int sr, int ql, int qr) {
        push(id, sl, sr);
        if ((ql <= sl) && (sr <= qr)) {
            return data[id];
        }
        int m = (sl + sr) / 2;
        if (qr <= m) {
            return get(id*2+1, sl, m, ql, qr);
        }
        if (m < ql) {
            return get(id*2+2, m+1, sr, ql, qr);
        }
        return max(get(id*2+1, sl, m, ql, qr), get(id*2+2, m+1, sr, ql, qr));
    }

    SegmentTree(int n_) {
        n = n_;
    }
};


int main(int argc, char const *argv[]) {
    int n, k;
    std::cin >> n;
    SegmentTree baum(n);
    baum.data.reserve(4*n);
    baum.delay.reserve(4*n);
    // std::vector<int> a(n);
    // for (size_t i = 0; i < count; i++) std::cin >> a[i];
    // baum.bauen(a.data(), 1, 0, )
    for (int i = 0; i < n; i++) {
        int inp;
        std::cin >> inp;
        // baum.add(i, 0, n-1, 0, n-1, inp);
        baum.push(i, 0, i);
    }
    std::cin >> k;
    for (size_t i = 0; i < k; i++) {
        int l, r, x;
        std::cin >> l >> r >> x;
        std::cout << baum.get(0, 0, n-1, l-1, r-1) << '\n';
    }
}
