#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int iter;
    cin >> iter;
    while(iter--){
        unsigned long long n, x, t;
        cin >> n >> x >> t;
        unsigned long long answer1 = 4 * n * t;
        if( (2 * t + x) > (2 * n * t) ){
            answer1 += (2 * t + x) - (2 * n * t);
        }
        unsigned long long answer2 = 4 * n * t + t;
        if( (t + x) > (2 * n * t + t) ){
            answer2 += (t + x) - (2 * n * t + t);
        }
        cout << min(answer1, answer2) << "\n";
    }
}
