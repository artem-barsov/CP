#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int event, city;
    deque<int> q;
    while (true) {
        cin >> event;
        if (event == 1) {
            cin >> city;
            q.push_front(city);
        }
        if (event == 2) {
            cin >> city;
            q.push_back(city);
        }
        if (event == 3) {
            cout << q.front() << '\n';
            q.pop_front();
        }
        if (event == 4) {
            cout << q.back() << '\n';
            q.pop_back();
        }
        if (event == 5) {
            cout << q.front() << '\n';
        }
        if (event == 6) {
            cout << q.back() << '\n';
        }
        if (event == 7) {
            cout << q.size() << '\n';
        }
        if (event == 8) {
            q.clear();
        }
        if (event == 9) {
            break;
        }
    }
}