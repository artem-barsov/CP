#include <bits/stdc++.h>

using namespace std;

struct TEvent {
    int start, end;
};

int main(int argc, char const *argv[]) {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<TEvent> det(n);
    for (int i = 0; i < n; i++) {
        int t;
        std::cin >> t;
        det[i] = TEvent{i*m, i*m + t};
    }
    sort(det.begin(), det.end(),
        [](const TEvent& lhs, const TEvent& rhs) {
            if (lhs.end != rhs.end)
                return lhs.end < rhs.end;
            return lhs.start < rhs.start;
        }
    );
    int c = 0, curEnd = 0;
    for (int i = 0; i < n; i++) {
        if ((curEnd <= det[i].start) && (det[i].end <= k)) {
            ++c;
            curEnd = det[i].end;
        }
    }
    std::cout << c << '\n';
}
