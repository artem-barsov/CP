#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, p;
    std::cin >> n >> p;
    int prev_t = -1, perep = 0;
    std::vector<bool> diff(n);
    bool zero = true;
    for (int i = 0; i < n; i++) {
        int t;
        std::cin >> t;
        if (!t) {
            if (prev_t) diff[i] = true;
            prev_t = t;
            continue;
        }
        zero = false;
        if (prev_t > t) {
            diff[i] = true;
            ++perep;
        }
        prev_t = t;
    }
    if (zero) {
        for (int i = 0; i < n; i++) {
            std::cout << 0 << '\n';
        }
        return 0;
    }
    if (perep != p-1) {
        std::cout << "ambiguous" << '\n';
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (diff[i]) --p;
        std::cout << p << '\n';
    }
}
