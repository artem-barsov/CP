#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

bool valid(vector<int> a) {
    sort(a.begin(), a.end());
    return a[0] + a[1] > a[2];
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int a[4];
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    for (int i = 0; i < 3; i++) {
        for (int j = i+1; j < 4; j++) {
            int bd = a[i], dc = a[j];
            int bc = bd + dc;
            int ab = 0, ac = 0;
            for (int k = 0; k < 4; k++) {
                if (!ab && k != i && k != j)
                    ab = a[k];
                else if (ab && k != i && k != j)
                    ac = a[k];
            }
            if (!valid({ab, bc, ac})) continue;
            if (bd * ac == dc * ab || dc * ac == bd * ab) {
                cout << 1 << '\n';
                return 0;
            }
        }
    }
    cout << 0 << '\n';
}