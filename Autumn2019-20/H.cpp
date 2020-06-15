#define _CRT_DISABLE_PERFCRIT_LOCKS
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (x > 0) {
            int l = 0, r = 1000001, c = (l+r)/2, prevc = 0;
            while (((unsigned long long)c*c*c != x) && (prevc != c)) {
                if ((unsigned long long)c*c*c > x) r = c;
                else l = c;
                prevc = c;
                c = (l+r)/2;
            }
            if ((unsigned long long)c*c*c == x) cout << c << '\n';
            else cout << "NO\n";
        }
        else {
            x = -x;
            int l = 0, r = 1000001, c = (l+r)/2, prevc = 0;
            while (((unsigned long long)c*c*c != x) && (prevc != c)) {
                if ((unsigned long long)c*c*c > x) r = c;
                else l = c;
                prevc = c;
                c = (l+r)/2;
            }
            if ((unsigned long long)c*c*c == x) cout << (signed int)-c << '\n';
            else cout << "NO\n";
        }
    }
}
