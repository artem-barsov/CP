#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    sort(a.begin(), a.end());
    unsigned long long c = 0;
    for (int i = n-1; i > 1; i--) {
        for (int j = i-1; j > 0; j--) {
            for (int k = j-1; k >= 0; k--) {
                if (a[i] < a[j]+a[k]) c++;
                else break;
            }
        }
    }
    std::cout << c;
}
