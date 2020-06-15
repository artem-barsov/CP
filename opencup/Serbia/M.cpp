#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    std::vector<std::string> v(n);
    map<std::string, int> c;
    for (int i = 0; i < n; i++) {
        std::string s;
        cin >> s;
        v[i] = s;
        sort(s.begin(), s.end());
        c[s]++;
    }
    int m = 0;
    for (auto & i : c) m = max(m, i.second);
    for (int i = 0; i < n; i++) {
        std::string s = v[i];
        sort(s.begin(), s.end());
        if (c[s] == m) {
            cout << v[i] << ' ' << m - 1 << '\n';
            break;
        }
    }
}
