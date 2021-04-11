#define _CRT_DISABLE_PERFCRIT_LOCKS
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    sort(a.begin(), a.end());
    unsigned long long c = 0;
    for (int i = n-1; i > 1; i--) {
        for (int j = i-1, k; j > 0; j--) {
            int unterstrecke;
            if ((unterstrecke = (j - (upper_bound(a.begin(), a.end(), a[i]-a[j]) - a.begin()))) > 0) c += unterstrecke;
        }
    }
    std::cout << c;
}
