#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::string t;
    std::queue<int> qout;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(t.begin(), t.end(), s[0]);
        int idx = std::distance(t.begin(), it);
        if (s.length() + idx > 1)
            qout.push(s.length() + idx);
        if (s.length() + idx - 1 > 1)
            qout.push(s.length() + idx - 1);
        t.insert(it, s[0]);
        s.erase(0, 1);
    }
    std::cout << qout.size() << '\n';
    while (!qout.empty()) {
        std::cout << qout.front() << ' ';
        qout.pop();
    }
    std::cout << '\n';
    // std::cout << t << '\n';
}
