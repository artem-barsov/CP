#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (auto &&x : v) os << x << ' ';
    return os;
}

vector<vector<int>> divs;

void precalc(int n) {
    divs.resize(n+1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            divs[j].push_back(i);
        }
    }
}

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n;
    cin >> n;
    precalc(n);
    set<pair<int, int>> s;
    for (int a = 1, b = n-1; a <= b; a++, b--) {
        // cout << "divisors " << a << ": " << divs[a] << '\n';
        // cout << "divisors " << b << ": " << divs[b] << '\n';
        for (int faca : divs[a])
            for (int facb : divs[b]) {
                if (faca < facb) 
                {
                    // if (!s.contains({faca, facb})) cout << "adedd pair (" << faca << ' ' << facb << ")'\n";
                    s.emplace(faca, facb);
                }
                else if (faca > facb)
                {
                    // if (!s.contains({facb, faca})) cout << "adedd pair (" << facb << ' ' << faca << ")'\n";
                    s.emplace(facb, faca);
                }
            }
        // cout << '\n';
    }
    cout << s.size() << '\n';
}