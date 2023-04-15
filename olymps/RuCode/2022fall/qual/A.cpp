#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    cin >> t;
    int h = t / 3600;
    t -= h * 3600;
    int m = t / 60;
    t -= m * 60;
    int s = t;
    printf("%s%d:%s%d:%s%d\n", (h<10?"0":""), h, 
                               (m<10?"0":""), m, 
                               (s<10?"0":""), s);
}