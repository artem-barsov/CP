#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int> > a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a.begin(), a.end());
    std::cout << a[n-2].second << '\n';
}
