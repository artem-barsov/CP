#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
	string s;
	cin >> n >> s;
	//GLASNYE
	int vowels = 0;
	//SOGLASNYE
	int consonants = 0;
	int answer = 0;
	for (int i = 0; i < n; ++i) {
		if ( (s[i] == 'a') || (s[i] == 'i') || (s[i] == 'o') || (s[i] == 'u') || (s[i] == 'e') || (s[i] == 'y') ) {
			++vowels;
		}
		else {
			++consonants;
		}
		if ( (vowels > 0) && (consonants > 0) ) {
			++answer;
			vowels = 0;
			consonants = 0;
		}
	}
	cout << answer << "\n";
}
