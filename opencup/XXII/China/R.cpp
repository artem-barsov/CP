#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    string s;
    map<string, char> decode;
    decode[".-"] = 'A';
    decode["-..."] = 'B';
    decode["-.-."] = 'C';
    decode["-.."] = 'D';
    decode["."] = 'E';
    decode["..-."] = 'F';
    decode["--."] = 'G';
    decode["...."] = 'H';
    decode[".."] = 'I';
    decode[".---"] = 'J';
    decode["-.-"] = 'K';
    decode[".-.."] = 'L';
    decode["--"] = 'M';
    decode["-."] = 'N';
    decode["---"] = 'O';
    decode[".--."] = 'P';
    decode["--.-"] = 'Q';
    decode[".-."] = 'R';
    decode["..."] = 'S';
    decode["-"] = 'T';
    decode["..-"] = 'U';
    decode["...-"] = 'V';
    decode[".--"] = 'W';
    decode["-..-"] = 'X';
    decode["-.--"] = 'Y';
    decode["--.."] = 'Z';
    decode[""] = ' ';
    while (std::getline(cin, s))
    {
        stringstream ss(s);
        string word;
        while (std::getline(ss, word, '/'))
            cout << decode[word];
        cout << '\n';
    }
}