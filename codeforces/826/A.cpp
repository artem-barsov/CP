#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    if (a == b)
        cout << '=' << '\n';
    else if (a.back() == b.back()) {
        if (a == "M" && b == "M")
            cout << '=' << '\n';
        else if (a.back() == 'S')
            cout << (a.size() > b.size() ? '<' : '>') << '\n';
        else
            cout << (a.size() > b.size() ? '>' : '<') << '\n';
    }
    else
        cout << (a.back() < b.back() ? '>' : '<') << '\n';
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    cin >> t;
    while (t--) solve();
}