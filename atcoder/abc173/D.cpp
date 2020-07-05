#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    sort(a.begin(), a.end(), [](const int& l, const int& r){return l > r;});
    unsigned long long sum = 0;
    for (int i = 2; i <= n; i++)
        sum += a[(i-1) >> 1];
    std::cout << sum << '\n';
}
