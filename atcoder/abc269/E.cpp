#include <bits/stdc++.h>

using namespace std;

int ask(int lx, int ly, int rx, int ry) {
    cout << "? " << lx << ' ' << rx << ' ' << ly << ' ' << ry << '\n';
    fflush(stdout);
    int resp;
    cin >> resp;
    return resp;
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    int l = 0, r = n+1;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (ask(l+1, 1, m, n) != m-l) r = m;
        else                          l = m;
    }
    int x = r;
    l = 0, r = n+1;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (ask(1, l+1, n, m) != m-l) r = m;
        else                          l = m;
    }
    int y = r;
    cout << "! " << x << ' ' << y << '\n';
    fflush(stdout);
}