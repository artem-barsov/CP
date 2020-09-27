#include <bits/stdc++.h>
using namespace std;

int main() {
    string inps;
    getline(cin, inps);
    long long idx;
    for(idx = 0; idx < inps.length(); ++idx){
        if (inps[idx] != ' ') break;
    }
    bool ok = true;

    if( idx == inps.length()) ok = false;

    for(int i = idx; i < inps.length(); ++i){
        if (inps[i] < '0' || inps[i] > '9') ok = false;
    }
    inps = inps.substr(idx, inps.length() - idx);
    if (ok == true) {
        inps.erase(0, min(inps.find_first_not_of('0'), inps.length()-1));
        if (inps.length() == 0) cout << 0 << '\n';
        else cout << inps << '\n';
    }
    else{
        cout << "invalid input\n";
    }
}
