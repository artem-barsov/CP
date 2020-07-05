#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, q;
    cin >> n;
    vector<long long> v(n), ps(n+1, 0);
    for (long long i = 0; i < n; i++) {
        cin >> v[i];
        ps[i+1] = ps[i] + v[i];
    }
    cin >> q;
    for (long long i = 0; i < q; i++) {
        long long l, r;
        cin >> l >> r;
        cout << ps[r] - ps[l-1] << '\n';
    }
}
