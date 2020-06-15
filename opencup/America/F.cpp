#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int> > floor(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> floor[i][j];
        }
    }
    std::vector<std::vector<std::pair<int, int> > > gr(k+1);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < count; k++) {
                if (floor[j][k] == i+1) {
                    /* code */
                }
            }
        }
    }
}
