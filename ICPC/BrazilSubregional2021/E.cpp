#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

struct Person {
    int time, dir;
};

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif

    int n;
    std::cin >> n;
    std::vector<int> arrive(1e7, -1);

    for (int i = 0; i < n; i++) {
        int t, d;
        std::cin >> t >> d;
        arrive[t] = d;
    }

    int state = -1;
    Person lastOnEsc{-1, -1};
    Person lastWait{-1, -1};

    int k = 0;

    int t = 0;
    for (;; t++) {
        // printf("t = %d:\n", t);
        if (lastOnEsc.time != -1 && lastOnEsc.time + 10 == t) {
            // printf("\tpop lastOnEsc(%d, %d)\n", lastOnEsc.time,
            // lastOnEsc.dir);
            state = -1;
            lastOnEsc = {-1, -1};
            if (lastWait.time != -1) {
                // printf("\tpop lastWait(%d, %d)\n", lastWait.time,
                // lastWait.dir);
                lastOnEsc = {t, lastWait.dir};
                state = lastWait.dir;
                lastWait = {-1, -1};
            } else if (k == n)
                break;
        }
        if (arrive[t] != -1) {
            ++k;
            // printf("\tarrived %d : ", arrive[t]);
            if (state == arrive[t] || state == -1) {
                state = arrive[t];
                lastOnEsc = {t, arrive[t]};
                // printf("lastOnEsc = { %d, %d };\n", t, arrive[t]);
            } else {
                lastWait = {t, arrive[t]};
                // printf("lastWait = { %d, %d };\n", t, arrive[t]);
            }
        }
    }
    std::cout << t << '\n';
}
