#include <bits/stdc++.h>

using namespace std;

int main(long long argc, char const *argv[]) {
    long long n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::set<long long> > features(5);
    for (long long i = 0; i < k; i++) {
        long long c, f;
        std::cin >> c >> f;
        features[f-1].insert(c);
    }
    long long vars = 0;
    std::vector<long long> outs;
    while (vars++ < 32) {
        std::set<long long> out;
        for (long long i = 0; i < 5; i++) {
            if (vars & (1<<i))
                out.insert(features[i].begin(), features[i].end());
        }
        if (out.size() >= n-m) outs.push_back(out.size());
    }
    if (outs.empty()) std::cout << "Round will be unrated\n";
    else {
        sort(outs.begin(), outs.end());
        std::cout << n - outs[0] << '\n';
    }
}
