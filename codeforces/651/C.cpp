#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x) {
    if (x <= 1) return false;
	for (int i = 2; i <= sqrt(x); i++)
		if (x%i == 0) return false;
	return true;
}

void solve() {
    int n;
    std::cin >> n;
    if (n == 1)
        std::cout << "FastestFinger" << '\n';
    else if (n&1)
        std::cout << "Ashishgup" << '\n';
    else if ((n&(n-1)) == 0) {
        if (n > 2)
            std::cout << "FastestFinger" << '\n';
        else
            std::cout << "Ashishgup" << '\n';
    }
    else {
        if (!(n&2))
            std::cout << "Ashishgup" << '\n';
        else if (isPrime(n/2))
            std::cout << "FastestFinger" << '\n';
        else
            std::cout << "Ashishgup" << '\n';
    }
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
