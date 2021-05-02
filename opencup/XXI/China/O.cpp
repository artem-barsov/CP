#include <bits/stdc++.h>

using namespace std;

int main() {
    char c;
	string s;
	set<char> nums;
	bool ok = true;
	cin >> s;
	for (int i = 0; i < s.size(); ++i){
		if ( nums.find(s[i]) != nums.end() ){
			ok = false;
			break;
		}
		nums.insert(s[i]);
	}
    std::cout << ok << '\n';
}
