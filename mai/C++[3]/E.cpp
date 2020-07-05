#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<char> Klammern;
    char ch = getchar();
    for (size_t i = 0; i < n; i++) {
        ch = getchar();
        if ((ch == '{') || (ch == '(') || (ch == '['))
            Klammern.push_back(ch);
        else {
            if (Klammern.empty() || ((Klammern.back() == '{')&&(ch != '}'))
                                || ((Klammern.back() == '(')&&(ch != ')'))
                                || ((Klammern.back() == '[')&&(ch != ']'))) {
                cout << "Nein";
                return 0;
            }
            else Klammern.pop_back();
        }
    }
    if (Klammern.empty()) cout << "Ja";
    else cout << "Nein";
}
