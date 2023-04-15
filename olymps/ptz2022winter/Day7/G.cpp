#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n = 64;
    printf("  ");
    for (int i = 0; i < n; i++) {
        if (i < 10) printf(" ");
        printf(" %d", i);
    }
    printf("\n");
    for (unsigned int i = 0; i < n; i++) {
        printf("%d: ", i);
        if (i < 10) printf(" ");
        for (unsigned int j = 0; j < n; j++) {
            // if (j >= 10) printf(" ");
            printf("%d  ", std::popcount(i & j) & 1);
        }
        printf("\n");
    }
}
