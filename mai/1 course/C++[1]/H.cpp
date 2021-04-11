#include <bits/stdc++.h>
using namespace std;
int main() {
	int x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	if (x1 > x2) swap(x1, x2);
	if (y1 > y2) swap(y1, y2);
	if (x3 > x4) swap(x3, x4);
	if (y3 > y4) swap(y3, y4);
	int a = x2-x1 + x4-x3 - (max(x2,x4)-min(x1,x3));
	int b = y2-y1 + y4-y3 - (max(y2,y4)-min(y1,y3));
	if ((a > 0) && (b > 0)) cout << a*b;
	else cout << 0;
}
    
