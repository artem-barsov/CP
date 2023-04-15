#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int f(int x) {
    if (x == 0) return 1;
    int cnt = 0, t = 1;
    while (t <= x) {
        t *= 10;
        cnt++;
    }
    return cnt;
}

void oper(map<int, int>& ma, map<int, int>& mb) {
    auto la = std::prev(ma.end());
    int nx = f(la->first);
    if (la->second == 1)
        ma.erase(la);
    else
        la->second--;
    
    auto itb = mb.find(nx);
    if (itb != mb.end()) {
        if (--(itb->second) == 0) mb.erase(itb);
    }
    else {
        ma[nx]++;
    }
}

void del0(map<int, int>& ma, map<int, int>& mb) {
    if (ma.find(0) != ma.end()) {
        mb[1] += ma[0];
        ma.erase(0);
    }
}

void solve() {
    int n;
    cin >> n;
    map<int, int> ma, mb;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ma[a]++;
    }
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        auto it = ma.find(b);
        if (it != ma.end()) {
            if (--(it->second) == 0) ma.erase(it);
        }
        else {
            mb[b]++;
        }
    }
    del0(ma, mb);
    del0(mb, ma);
    int cnt = 0;
    while (!ma.empty() || !mb.empty())
    {
        auto la = ma.rbegin();
        auto lb = mb.rbegin();
        // for (auto& [k, v] : ma) {
        //     for (int i = 0; i < v; i++)
        //         cout << k << ' ';
        // } cout << '\n';
        // for (auto& [k, v] : mb) {
        //     for (int i = 0; i < v; i++)
        //         cout << k << ' ';
        // } cout << '\n';

        if (la->first > lb->first) {
            // cout << "extract from ma:\n";
            oper(ma, mb);
        }
        else {
            // cout << "extract from mb:\n";
            oper(mb, ma);
        }
        cnt++;
    }
    cout << cnt << '\n';
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    std::cin >> t;
    while (t--) solve();
}