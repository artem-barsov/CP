#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    int pos = 0;
    for(int i = 0; i < n; ++i){
        if( s[i] == '-' ){
            pos = i;
            break;
        }
    }
    int from = 0;
    int base = 1;
    for(int i = pos - 3; i >= 0; --i){
        from += (s[i] - '0') * base;
        base *= 10;
    }
    int to = 0;
    base = 1;
    for(int i = (n - 1) - 2; i > pos; --i){
        to += (s[i] - '0') * base;
        base *= 10;
    }
    if( s[pos - 2] == 'B' ){
        from = 754 - from;
    }
    else{
        from = 753 + from;
    }
    if( s[n - 2] == 'B' ){
        to = 754 - to;
    }
    else{
        to = 753 + to;
    }
    ///////////////////////////////////////
    std::array<int, 10> unit_len;
    unit_len[0] = 0;
    unit_len[1] = 1;
    unit_len[2] = 2;
    unit_len[3] = 3;
    unit_len[4] = 2;
    unit_len[5] = 1;
    unit_len[6] = 2;
    unit_len[7] = 3;
    unit_len[8] = 4;
    unit_len[9] = 2;
    int max_len = 0;
    for (int i = from; i <= to; i++) {
        int len = 0;
        int thou = (i/1000)%10;
        int hund = (i/100)%10;
        int tens = (i/10)%10;
        int unit = (i/1)%10;
        len += unit_len[thou];
        len += unit_len[hund];
        len += unit_len[tens];
        len += unit_len[unit];
        if (max_len < len) max_len = len;
    }
    std::cout << max_len << '\n';
}
