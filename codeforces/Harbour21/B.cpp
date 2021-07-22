#include <bits/stdc++.h>

using namespace std;

enum SIDE { LEFT, RIGHT };

bool move(std::string& s, std::string& t, int fs, int ft, SIDE side) {
    if (ft == t.length()) return true;
    if (fs < 0 || s.length() <= fs) return false;
    if (s[fs] != t[ft]) return false;
    bool ret = false;
    if (side == RIGHT) {
        ret = move(s, t, fs+1, ft+1, RIGHT);
        if (!ret) ret = move(s, t, fs-1, ft+1, LEFT);
    }
    else {
        ret = move(s, t, fs-1, ft+1, LEFT);
    }
    return ret;
}

void solve() {
    std::string s, t;
    std::cin >> s >> t;
    for (size_t i = 0; i < s.length(); i++) {
        if (move(s, t, i, 0, RIGHT)) {
            std::cout << "YES" << '\n';
            return;
        }
    }
    std::cout << "NO" << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
