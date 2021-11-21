#include <bits/stdc++.h>
// #define int long long

using namespace std;
string s;

void mv(string t) {
    cout << "? " << t << endl;
    cin >> s;
}

string solve() {
    if (s == "queen") {
        mv("D");
        if (s == "queen")
            return "d1";
        else
            return "d8";
    } else if (s == "king") {
        mv("D");
        if (s == "king")
            return "e1";
        else
            return "e8";
    } else if (s == "bishop") {
        mv("R");
        if (s == "queen") {
            mv("D");
            if (s == "queen")
                return "c1";
            else
                return "c8";
        } else {
            mv("D");
            if (s == "knight")
                return "f1";
            else
                return "f8";
        }
    } else if (s == "knight") {
        mv("R");
        if (s == "rook") {
            mv("D");
            if (s == "rook")
                return "g1";
            else
                return "g8";
        } else {
            mv("D");
            if (s == "bishop")
                return "b1";
            else
                return "b8";
        }
    } else if (s == "rook") {
        mv("R");
        if (s == "rook") {
            mv("D");
            if (s == "rook")
                return "h1";
            else
                return "h8";
        } else {
            mv("D");
            if (s == "knight")
                return "a1";
            else
                return "a8";
        }
    } else if (s == "pawn") {
        mv("D");
        if (s == "white") {
            mv("U");
            mv("U");
            if (s == "rook")
                return "a7";
            if (s == "bishop")
                return "c7";
            if (s == "king")
                return "e7";
            if (s == "knight")
                return "g7";
        } else if (s == "black") {
            mv("U");
            mv("U");
            if (s == "rook")
                return "h7";
            if (s == "bishop")
                return "f7";
            if (s == "queen")
                return "d7";
            if (s == "knight")
                return "b7";
        } else {
            if (s == "queen")
                return "d2";
            if (s == "king")
                return "e2";
            if (s == "rook") {
                mv("R");
                if (s == "rook")
                    return "h2";
                else
                    return "a2";
            }
            if (s == "knight") {
                mv("R");
                if (s == "bishop")
                    return "b2";
                else
                    return "g2";
            }
            if (s == "bishop") {
                mv("R");
                if (s == "queen")
                    return "c2";
                else
                    return "f2";
            }
        }
    } else {
        string ans = "";
        int t = 0;
        while(s == "black" || s == "white") {
            mv("D");
            t++;
        }
        ans = solve();
        ans[1] = ans[1] + t;
        return ans;
    }
    return "";
}

void solver() {
    cin >> s;
    string ans = solve();
    cout << "! " << ans << endl;
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // signed t;
    // cin >> t;
    // while(t--)
        solver();

    return 0;
}
