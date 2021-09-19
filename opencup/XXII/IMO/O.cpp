#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;
using ull = unsigned ll;

ll ans;

void generate(string s) {
    int k = s.size();
    ll a = stoll(s);
    ll N = 1;
    for (int i = 0; i < k; ++i) N *= 10;
    std::vector<int> d(10);
    std::iota(d.begin(), d.end(), 0);
    ll m = 0;
    do {
        ll b = 0;
        for (int i = 0; i < k; ++i) {
            b *= 10;
            b += d[i];
        }
        ll curr = min(abs(a - b), N - abs(a - b));
        if (curr > m) {
            ans = b;
            m = curr;
        }
        std::reverse(d.begin() + k, d.end());
    } while (next_permutation(d.begin(), d.end()));
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    generate(s);
    cout << setw(s.size()) << setfill('0') << ans << endl;
}
