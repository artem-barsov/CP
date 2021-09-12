#include <iostream>

using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    if (n < m + 1)
        cout << 0 << endl;
    else
        cout << n - m << endl;
}
