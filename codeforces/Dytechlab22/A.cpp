#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    map<char, int> avail;
    for (char c : s) avail[c]++;
    for (int i = 0; i < k; i++) {
        int t = n / k;
        for (char c = 'a'; c <= 'z'; c++) {
            if (avail[c] && t) {
                t--;
                avail[c]--;
            }
            else {
                cout << c;
                break;
            }
        }
    }
    cout << '\n';
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