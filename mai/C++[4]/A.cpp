#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    std::vector<int> deck(n);
    for (size_t i = 0; i < n; i++) std::cin >> deck[i];
    sort(deck.begin(), deck.end());
    for (size_t i = 1; i < n; i++) {
        if (deck[i] - deck[i-1] != 1) {
            std::cout << "Scammed";
            return 0;
        }
    }
    std::cout << "Deck looks good";
}
