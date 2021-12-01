#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int x1, p1, x2, p2;
    std::cin >> x1 >> p1 >> x2 >> p2;
    std::string s1 = to_string(x1);
    std::string s2 = to_string(x2);
    if (s1.length() + p1 < s2.length() + p2)
        std::cout << '<' << '\n';
    else if (s1.length() + p1 > s2.length() + p2)
        std::cout << '>' << '\n';
    else {
        if (s1.length() < s2.length())
            s1 += std::string(s2.length() - s1.length(), '0');
        else if (s1.length() > s2.length())
            s2 += std::string(s1.length() - s2.length(), '0');

        if (s1 < s2)
            std::cout << '<' << '\n';
        else if (s1 > s2)
            std::cout << '>' << '\n';
        else
            std::cout << '=' << '\n';
    }
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    std::cin >> t;
    while (t--) solve();
}
