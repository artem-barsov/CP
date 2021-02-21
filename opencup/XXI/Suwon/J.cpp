#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int res = -1;
    bool ans = false;
    for (int i = 0; i < n && !ans; i++) {
        bool run = true;
        for (int j = i + 1; j < n - 5 && run; j++) {
            for (int k = j + 1; k < n - 4; k++) {
                if (v[j] + v[k] <= v[i]) {
                    run = false;
                    break;
                }
                if (v[k + 1] + v[k + 2] + v[k + 3] + v[k + 4] > v[j] + v[k]) {
                    res = max(res, v[k + 1] + v[k + 2] + v[k + 3] + v[k + 4] + v[j] + v[k] + v[i]);
                    ans = true;
                    break;
                }
            }
        }
    }
    cout << res << endl;
}
