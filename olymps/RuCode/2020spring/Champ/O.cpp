#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
// #define _DEBUG

// template <class T>
// istream& operator >>(istream& in, vector <T>& a)
// {
//     for(auto &i : a){
//         in >> i;
//     }
//     return in;
// }

// template <class T>
// ostream& operator <<(ostream& out, vector <T>& a)
// {
//     for(auto &i : a){
//         out << i << " ";
//     }
//     return out;
// }

// template <class T, class U>
// istream& operator >>(istream& in, vector <pair <T, U>>& a)
// {
//     for(auto &i : a){
//         in >> i.first >> i.second;
//     }
//     return in;
// }

// template <class T, class U>
// ostream& operator <<(ostream& out, vector <pair <T, U>>& a)
// {
//     for(auto &i : a){
//         out << i.first << " " << i.second << "\n";
//     }
//     return out;
// }


int main() {

	#ifdef _DEBUG
		freopen("input.txt", "r", stdin);
		int tt = clock();
	#endif

	long long n;
	cin >> n;
	long long x = n - 3;
	if( n == 1){
		cout << 0 << "\n";
	}
	else{
		long long zigzag = max(0LL , (x + 1) * x + x + 1);
		// long long zigzag = (( 1 + n - 3) * (n - 3)) / 2;
		// zigzag = 2 *zigzag + n - 2;
		long long simple = n * n - zigzag;
		long double answer = simple;
		answer += sqrt(2) * zigzag;
		cout.precision(5);
		// cout<< "----------------\n";
		// cout << simple << "\n";
		// cout<< "----------------\n";
		cout << fixed << answer << "\n";
	}




	#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
	#endif

	return 0;  

}