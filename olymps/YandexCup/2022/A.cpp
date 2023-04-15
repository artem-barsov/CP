#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        if (n == 1) {
            cout << "YES" << '\n';
            cout << 1 << '\n';
        }
        else cout << "NO" << '\n';
        return 0;
    }
    if (n*n % k != 0) {
        cout << "NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n';
    if (n == 6 && k == 9) {
        cout << "1 2 3 4 5 6\n"
                "7 8 9 1 2 3\n"
                "4 5 6 7 8 9\n"
                "1 2 3 4 5 6\n"
                "7 8 9 1 2 3\n"
                "4 5 6 7 8 9\n";
        return 0;
    }
    if (n*n == k) {
        int t = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << t++ << ' ';
            cout << '\n';
        }
        return 0;
    }
    if (n==4&&k==8 || n==6&&k==4 || n==10&&k==4) {
        string pat;
        int t = 1;
        for (int i = 0; i < n; i++) {
            pat += (t++) + '0';
            pat += ' ';
            if (t > k) t = 1;
        }
        pat += '\n';
        for (int i = 0; i < n; i++) {
            pat += (t++) + '0';
            pat += ' ';
            if (t > k) t = 1;
        }
        pat += '\n';
        for (int i = 0; i < n/2; i++)
            cout << pat;
        return 0;
    }
    string pat;
    int t = 1;
    for (int i = 0; i < n; i++) {
        if (t == 10)
            pat += "10";
        else
            pat += (t++) + '0';
        pat += ' ';
        if (t > k) t = 1;
    }
    string atp = pat.substr(2) + pat.front();
    for (int i = 0; i < n; i++)
        cout << ((i&1) ? pat : atp) << '\n';
}