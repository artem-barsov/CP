#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000000;

struct Node
{
    int v;
    map<int, int> go;
    int prev;
};

Node tree[MAXN];
int sz = 1;
int ans = 0;

bool canGo(int v, int x) {
    return tree[v].go.count(x);
}

int add(int v, int x) {
    if (!canGo(v, x)) {
        ans++;
        tree[v].go[x] = sz++;
    }
    int nw = tree[v].go[x];
    tree[nw].prev = v;
    tree[nw].v = x;
    return nw;
}

void solve() {
    int k, n;
    cin >> k >> n;
    vector<int> a(k, 0);
    vector<int> b(k, 0);
    for (int i = 0; i < n; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            a[x] = add(a[x], y);
            b[x]++;
        } else if (cmd == 2) {
            int x;
            cin >> x;
            x--;
            a[x] = tree[a[x]].prev;
            b[x]--;
        } else {
            int x, y;
            cin >> x >> y;
            x--; y--;
            bool f = false;
            if (b[x] > b[y]) {
                swap(b[x], b[y]);
                swap(a[x], a[y]);
                f = true;
            }
            while (b[y] - b[x] > 1) {
                a[x] = add(a[x], tree[a[y]].v);
                a[y] = tree[a[y]].prev;
                b[y]--;
                b[x]++;
            }
            if (f) {
                swap(b[x], b[y]);
                swap(a[x], a[y]);
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
        solve();
}
