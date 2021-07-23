#include <bits/stdc++.h>

using namespace std;

struct T { char ch; int freq; };

void solve() {
    std::string s;
    std::cin >> s;
    std::unordered_map<char, int> fr;
    for (size_t i = 0; i < s.length(); i++) {
        fr[s[i]]++;
    }
    std::vector<T> v;
    for (auto& x : fr) {
        v.push_back({x.first, x.second});
    }
    sort(v.begin(), v.end(), [&](const T& lhs, const T& rhs) {
        return lhs.freq > rhs.freq;
    });
    int i = 0;
    while (i<v.size() && v[i].freq>=2) i++;
    std::cout << i + (v.size()-i)/2 << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
