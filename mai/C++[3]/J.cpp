#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> Preis(n);
    for (size_t i = 0; i < n; i++) std::cin >> Preis[i];
    sort(Preis.begin(), Preis.end());
    int sum=0;
    for (int i = n-1; i >= 0; i--)
        if ((n-i) % k > 0) sum += Preis[i];
    cout << sum;
}
