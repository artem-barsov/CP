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
    int n, k;
    cin >> n >> k;
    priority_queue<int> a;
    for (int i = 0; i < k; i++) {
        int ai;
        cin >> ai;
        a.push(ai);
    }
    bool taka = true;
    int ans = 0;
    while (n) {
        while (a.top() > n) a.pop();
        if (taka) {
            n -= a.top();
            ans += a.top();
        }
        else {
            n -= a.top();
        }
        taka = !taka;
    }
    cout << ans << '\n';
}