#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int opposite(int i) {
    if (i == 0) return 5;
    if (i == 1) return 3;
    if (i == 2) return 4;
    if (i == 3) return 1;
    if (i == 4) return 2;
    if (i == 5) return 0;
    return -1;
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    std::string s, t;
    std::cin >> s >> t;
    bool prob0 = false;
    double prob = 1;
    for (int i = 0; i < s.length(); i++) {
        std::string cube;
        std::cin >> cube;
        if (cube.find(s[i]) == std::string::npos) prob0 = true;
        if (prob0 || s[i] == t[i]) continue;
        int c = std::count(cube.begin(), cube.end(), t[i]);
        if (c == 0) prob0 = true;
        else if (c == 2) {
            if (cube[0] == t[i] && cube[opposite(0)] == t[i]
             || cube[1] == t[i] && cube[opposite(1)] == t[i]
             || cube[2] == t[i] && cube[opposite(2)] == t[i]) {
                prob *= 0.5;
            }
            else continue;
        }
        else if (c >= 3) continue;
        else { // c == 1
            double aver = 0;
            int cnt = 0;
            for (int j = 0; j < 6; j++) {
                if (s[i] == cube[j]) {
                    if (cube[opposite(j)] == t[i]) aver += 1;
                    else aver += 0.5;
                    cnt++;
                }
            }
            prob *= (aver / cnt);
        }
    }
    std::cout.precision(20);
    std::cout << (prob0 ? 0 : prob) << '\n';
}
