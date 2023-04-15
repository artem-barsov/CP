#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    std::cin >> q;
    std::vector<int> nums(1000001);
    for (int i = 0; i < q; i++) {
        int t, x;
        std::cin >> t >> x;
        if (t == 1) nums[x]++;
        else if (t == 2) nums[x]--;
        else {
            int c = 0;
            for (int j = x; j < nums.size(); j += x) {
                if (nums[j]) c++;
            }
            std::cout << c << '\n';
        }
    }
}
