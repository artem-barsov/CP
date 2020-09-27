#include <bits/stdc++.h>

using namespace std;

int prod(std::string n) {
    int p = 1;
    for (int i = 0; i < n.length(); i++) {
        if (n[i] != '0') {
            p *= n[i] - '0';
        }
    }
    return p;
}

int main(int argc, char const *argv[]) {
    string n;
    cin >> n;
    int ans = prod(n);
    for(int i = n.length() - 1; i > 0; --i){
        if (n[i] != '9' ){
            n[i] = '9';
            n = to_string(int(atoi(n.c_str()) - pow(10, n.length() - i)));
            ans = max(ans, prod(n));
        }
    }
    std::cout << ans << '\n';
}
