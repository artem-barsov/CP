#include <bits/stdc++.h>

using namespace std;
using namespace std::__detail;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    n--;
    int first = min(a, b);
    unsigned long long Zeit = LONG_LONG_MAX-1;
    for (int i = 0; i < n; i++)
        Zeit = min(Zeit, (unsigned long long)max(a*i, b*(n-i)));
    cout << first + !!n*Zeit << '\n';
}
