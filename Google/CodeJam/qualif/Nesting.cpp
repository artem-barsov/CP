#include <bits/stdc++.h>
std::string solve() {
    std::string s, res;
    std::cin >> s;
    res.append(s[0]-'0', '(') += s[0];
    for (int i = 1; i < s.length(); i++)
        res.append(abs(s[i]-s[i-1]), s[i]-s[i-1] > 0 ? '(' : ')') += s[i];
    return res.append(s.back()-'0', ')');
}
int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; i++) printf("Case #%d: %s\n", i, solve().c_str());
}
