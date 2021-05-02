#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<std::string> nums = {"1","2","3","4","5","6","7","8","9"};
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            nums.push_back(to_string(i)+to_string(j));
        }
    }
    nums.push_back("100");
    int l = 0, r;
    for (int i = 0; i < nums.size(); i++) {
        r = nums[i].length();
        if (s.substr(l, r) != nums[i]) {
            std::cout << nums[i] << '\n';
            break;
        }
        l += r;
    }
}
