#include <bits/stdc++.h>

using namespace std;

unsigned long long solve()
{
    unsigned long long n;
    cin >> n;
    vector<unsigned long long> l(n);
    for (unsigned long long i = 0; i < n; i++) cin >> l[i];
    if (n < 3) return 0;
    sort(l.begin(), l.end());
    vector<unsigned long long> ps(n+1, 0);
    for (unsigned long long i = 0; i < n; i++) ps[i+1] = ps[i] + l[i];

    unsigned long long i = n-1;
    while ((l[i] >= ps[i]) && (i >= 2)) i--;
    if (i < 2) return 0;
    return ps[i+1];
}

int main() {
    unsigned long long z;
    cin >> z;
    for (unsigned long long i = 0; i < z; i++) cout << solve() << endl;
}
