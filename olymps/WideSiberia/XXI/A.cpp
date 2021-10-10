#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, m, r, c, s;
    cin >> n >> m >> r >> c >> s;
    bool ok = true;
    if ((s >= r - 1) && (s >= c - 1)) ok = false;
    if ((r + s >= n) && (c + s >= m)) ok = false;
    if ((s >= r - 1) && (r + s >= n)) ok = false;
    if ((s >= c - 1) && (c + s >= m)) ok = false;
    std::cout << (ok ? "Barsik" : "Tuzik") << '\n';
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) solve();
}
