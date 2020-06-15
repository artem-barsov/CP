#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

int main(int argc, char const *argv[]) {
#define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    std::cin >> q;
    std::map<int, int> nums;
    for (int i = 0; i < q; i++) {
        int t, x;
        std::cin >> t >> x;
        switch (t) {
            case 1:
                nums[x]++;
                // nums.insert(x);
                break;;
            case 2:
                nums[x]--;
                // nums.erase(nums.find(x));
                break;;
            case 3:
                int c = 0;
                for (auto & it : nums) {
                    // std::cout << it.first << ' ' << it.second << '\n';
                    if ((it.second > 0) && (it.first % x == 0)) c++;
                }
                std::cout << c << '\n';
                break;;
        }
    }
}
