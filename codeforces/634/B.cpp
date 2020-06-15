#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;
    std::string s;
    std::string cyc(a, ' ');
    for (int i = 0; i < b; i++) cyc[i] = 'a' + i;
    for (int i = b; i < a; i++) cyc[i] = cyc[i-1];
    for (int i = 0; i < n/a; i++) s += cyc;
    for (int i = 0; s.length() != n; i++) s += cyc[i];
    std::cout << s << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
