#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    for(int i = 1; i <= n; ++i)
        cin >> nums[i];
    std::vector<int> cycles;
    std::vector<bool> ans(n+1, false);
    int maxcnt = 0;
    for(int i = 1; i <= n; ++i){
        if( nums[i] != -1 ){
            int cnt = 1;
            int cur = i;
            int par = nums[i];
            while( cur != par && par != -1 ){
                nums[cur] = -1;
                cur = par;
                par = nums[par];
                ++cnt;
            }
            if (cnt != 1 ) --cnt;
            maxcnt = max(maxcnt, cnt);
            bool met = false;
            for (size_t j = 0; j < cycles.size(); j++) {
                ans[cycles[j]+cnt] = true;
                if (cycles[j] == cnt) met = true;
            }
            if (!met) cycles.push_back(cnt);
        }
    }
    for (size_t i = 1; i <= n; i++) {
        if (i <= maxcnt) std::cout << (i==n?"No":"Yes") << '\n';
        else std::cout << (ans[i] ? "Yes" : "No") << '\n';
    }
}
