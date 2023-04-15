#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n, p;
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        int a, s;
        cin >> a >> s;
        if (s >= p) {
            cout << a * p << '\n';
        }
        else {
            int k = p / s + !!(p%s);
            cout << (a / k + !!(a%k)) * p << '\n';
        }
    }
}