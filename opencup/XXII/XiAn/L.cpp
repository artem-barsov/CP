#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    std::string s, line;
    while (getline(cin, line))
        s += line + ' ';
    for (int i = 0; i + 4 < s.length(); i++) {
        if ((s[i] == 'A' && i+5 < s.length() && s.substr(i+1, 4) == "pple")
        || (s[i] == 'i' && i+6 < s.length() && s.substr(i+1, 5) == "Phone")
        || (s[i] == 'i' && (s.substr(i+1, 3) == "Pod" || s.substr(i+1, 3) == "Pad")))
            std::cout << "MAI MAI MAI!" << '\n';
        else if (s[i] == 'S' && s.substr(i+1, 3) == "ony")
            std::cout << "SONY DAFA IS GOOD!" << '\n';
    }
}
