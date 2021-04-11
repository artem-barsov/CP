#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    std::vector<std::vector<int> > distances(N, std::vector<int>(n));

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (distances[i][j] > distances[i][k]+distances[k][j]) {
                    distances[i][j] = distances[i][k]+distances[k][j];
                }
            }
        }
    }
}
