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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (a + b) * (c - d) << '\n';
    cout << "Takahashi" << '\n';
}