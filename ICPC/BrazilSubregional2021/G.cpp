#include <bits/stdc++.h>

using namespace std;
using ll = long long;

deque<ll> dq;
vector<ll> fib(80, 0);
vector<ll> fib_num;
set<ll> st;

void print_ans() {
    while (!dq.empty()) {
        ll f = dq.front();
        dq.pop_front();

        while (--f) {
            cout << "A";
        }
        cout << "B";
    }

    cout << endl;
}

void calc(ll n) {
    if (st.count(n) > 0) {
        return;
    }
    st.insert(n);

    if (n == 1) {
        print_ans();
        exit(0);
    }

    for (int i = fib.size() - 1; i >= 0; i--) {
        if (n % fib[i] == 0) {
            dq.push_back(fib_num[i]);
            calc(n / fib[i]);
            dq.pop_back();
        }
    }
}

void solve() {
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < fib.size(); i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    ll n;
    cin >> n;

    vector<ll> new_fib;
    for (int i = 2; i < fib.size(); i++) {
        if (n % fib[i] == 0) {
            new_fib.push_back(fib[i]);
            fib_num.push_back(i);
        }
    }
    fib = move(new_fib);

    calc(n);

    cout << "IMPOSSIBLE" << endl;

}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ll t;
    // cin >> t;
    // while (t--)
        solve();


    return 0;
}
