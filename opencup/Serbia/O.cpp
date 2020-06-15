#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
	while (!((a == 0) && (b == 0) && (c == 0) && (d == 0))) {
		if (a == 0) a = d / (b * c);
		if (b == 0) b = d / (a * c);
		if (c == 0) c = d / (a * b);
		if (d == 0) d = a * b * c;
        printf("%d %d %d %d\n", a, b, c, d);
        cin >> a >> b >> c >> d;
	}
}
