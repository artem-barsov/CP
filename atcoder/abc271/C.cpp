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
    int n;
    cin >> n;
    map<int, int> ma;
    if (n == 1) {
        int a;
        cin >> a;
        cout << (a == 1 ? 1 : 0) << '\n';
        return 0;
    }
    if (n == 2) {
        int a1, a2;
        cin >> a1 >> a2;
        if (a1 > a2) swap(a1, a2);
        cout << (a1 == 1 && a2 ==  2 ? 2 : 1) << '\n';
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ma[a]++;
    }
    int stor = 0;
    int v = 1;
    for (;; v++) {
printf("v = %d:\t", v);
        if (ma.find(v) != ma.end()) {
            stor += ma[v] - 1;
printf("exists, (store += %d) = %d\n", ma[v] - 1, stor);
        }
        else {
            if (stor >= 2) {
                stor -= 2;
printf("(stor -= 2) = %d\n", stor);
            }
            else if (stor == 1) {
                if (ma.rbegin()->first < v) {
printf("last is BAD %d\n", ma.rbegin()->first);
                    break;
                }
                stor--;
printf("(stor--) = %d, ", stor);
                if (ma.rbegin()->second > 1)
                    ma.rbegin()->second--;
                else {
                    ma.erase(prev(ma.end()));
                    if (ma.empty()) {
printf("ma is empty\n");
                        break;
                    }
                }
printf("last is now [%d : %d]\n", ma.rbegin()->first, ma.rbegin()->second);
            }
            else {
                if (ma.rbegin()->first < v) {
printf("last is BAD %d\n", ma.rbegin()->first);
                    break;
                }
                if (ma.rbegin()->second > 1)
                    ma.rbegin()->second--;
                else {
                    ma.erase(prev(ma.end()));
                    if (ma.empty()) {
printf("ma is empty\n");
                        break;
                    }
                }
                if (ma.rbegin()->first < v) {
printf("last is BAD %d\n", ma.rbegin()->first);
                    break;
                }
                if (ma.rbegin()->second > 1)
                    ma.rbegin()->second--;
                else {
                    ma.erase(prev(ma.end()));
                    if (ma.empty()) {
printf("ma is empty\n");
                        break;
                    }
                }
printf("last is now [%d : %d]\n", ma.rbegin()->first, ma.rbegin()->second);
            }
            ma[v]++;
        }
    }
    cout << v - 1 << '\n';
}