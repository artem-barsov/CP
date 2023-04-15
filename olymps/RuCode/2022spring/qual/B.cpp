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
    std::priority_queue<int> pq;
    int x = -1;
    do {
        std::cin >> x;
        pq.push(x);
    } while(x != 0);
    pq.pop();
    std::cout << pq.top() << '\n';
}
