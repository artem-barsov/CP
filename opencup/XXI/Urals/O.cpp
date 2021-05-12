#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int vowels = 0;
	int consonants = 0;
	for(int i = 0; i < s.size(); ++i){
		if( s[i] == 'y' ){
			continue;
		}
		if( (s[i] == 'a') || (s[i] == 'e') || (s[i] == 'i') || (s[i] == 'o') || (s[i] == 'u')){
			++vowels;
		}
		else{
			++consonants;
		}
	}
	int answer = 0;
	while( vowels <= consonants ){
		--consonants;
		++vowels;
		++answer;
	}
	cout << answer << endl;
}
