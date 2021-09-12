#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main () {
    int x1, y1, x2, y2, w;
    cin >> x1 >> y1 >> x2 >> y2 >> w;
    int d = abs(x1 - x2) + abs(y1 - y2);
    if (d <= w && (d - w) % 2 == 0) cout << "Y\n";
    else cout << "N\n";
}
