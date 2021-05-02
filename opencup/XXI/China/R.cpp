#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    map<int, int> nums;
    long long ans = 0;
    long long prev = 0;
    long long glob = 0;
    long long sender;
    cin >> sender;
    --sender;
    ans = prev = n - 1;
    cout << ans << '\n';
    glob = 1;
    nums[sender] = -1;
    for (size_t i = 1; i < m; i++) {
        cin >> sender;
        --sender;
        ans = prev + (n - 1) - (glob + nums[sender]);
        prev = ans;
        ++glob;
        nums[sender] = -glob;
        cout << ans << '\n';
    }
}
