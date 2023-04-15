#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #define int long long
    int n, m, q;
    std::cin >> n;
    std::vector<int> fragen(n);
    for (int i = 0; i < n; i++) std::cin >> fragen[i];
    std::cin >> m;
    std::vector<int> zeit(m), antw(m);
    for (int i = 0; i < m; i++) std::cin >> zeit[i] >> antw[i];
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        int d, c = 0;
        std::cin >> d;
        std::vector<int>::iterator begin = zeit.begin();
        for (int j = 0; j < n; j++) {
            if (begin == (zeit.end()+1)) break;
            begin = lower_bound(begin, zeit.end(), fragen[j]-d+1);
            if (antw[begin-zeit.begin()-1] == j+1) c++;
            // std::cout << "\t" << antw[begin-zeit.begin()-1] << '\n';
        }
        // std::cout << "\t\t" << c << '\n';
        std::cout << c << ' ';
    }
}
