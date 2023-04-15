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
    int n;
    cin >> n;
    map<int, int> ma;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ma[a]++;
    }
    vector<pair<int,int>> va(ma.begin(), ma.end());
    for (int k = 0; k < n; k++) {
        if (va.size()-k-1 < va.size())
            cout << va[va.size()-k-1].second << '\n';
        else
            cout << 0 << '\n';
    }
}