#include <bits/stdc++.h>

using namespace std;

std::vector<int> nMatches;

std::string minMatch(int n) {
    int places = 1 + n / 7;
    // if (n == 7) places -= 1;
    std::string res;
    for (int digit = 0 ; digit < places ; ++digit )
    {
        int minM = std::max(2, n - 7 * (places - 1 - digit));
        int maxM = std::min(7, n - 2 * (places - 1 - digit));
        for (int digit = digit > 0 ? 0 : 1; digit <= 9; digit++) {
            if((nMatches[digit] >= minM) && (nMatches[digit] <= maxM)) {
                res += digit + '0';
                n -= nMatches[digit];
                break;
            }
        }
    }
    res.erase(0, min(res.find_first_not_of('0'), res.size()-1));
    return res;
}

int main()
{
    nMatches.push_back(6);
    nMatches.push_back(2);
    nMatches.push_back(5);
    nMatches.push_back(5);
    nMatches.push_back(4);
    nMatches.push_back(5);
    nMatches.push_back(6);
    nMatches.push_back(3);
    nMatches.push_back(7);
    nMatches.push_back(6);

    int n;
    std::cin >> n;
    std::cout << minMatch(n) << '\n';
}
