#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::string a, b;
    std::cin >> n >> a >> b;
    if (b[0] == '1') {
        if (a[0] == '0')      a[0] = 'X';
        else if (a[1] == '1') a[1] = 'X';
    }
    for (int i = 1; i < n-1; i++) {
        if (b[i] == '0') continue;
             if (a[i-1] == '1') a[i-1] = 'X';
        else if (a[i] == '0')   a[i] = 'X';
        else if (a[i+1] == '1') a[i+1] = 'X';
    }
    if (b[n-1] == '1') {
             if (a[n-2] == '1') a[n-2] = 'X';
        else if (a[n-1] == '0') a[n-1] = 'X';
    }
    int c = 0;
    for (char p : a) c += (p == 'X');
    std::cout << c << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
