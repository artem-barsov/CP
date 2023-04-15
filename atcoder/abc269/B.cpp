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
    vector<string> s(10);
    int a = -1, b = -1, c = -1, d = -1;
    for (auto &&l : s) cin >> l;
    bool brk = false;
    for (int i = 0; i < 10 && !brk; i++) {
        for (int j = 0; j < 10; j++) {
            if (s[i][j] == '#') {
                a = i;
                c = j;
                brk = true;
                break;
            }
        }
    }
    brk = false;
    for (int i = 9; i >= 0 && !brk; i--) {
        for (int j = 9; j >= 0; j--) {
            if (s[i][j] == '#') {
                b = i;
                d = j;
                brk = true;
                break;
            }
        }
    }
    cout << a + 1 << ' ' << b + 1 << '\n';
    cout << c + 1 << ' ' << d + 1 << '\n';
}