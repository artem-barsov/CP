#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int n, m;

bool dfs(std::vector<std::string>& board,
         std::vector<std::vector<char> >& used,
         std::string& path, int row, int col) {
    used[row][col] = true;
    if (row == n - 1 && col == m - 1) {
        return true;
    }
    if (col + 1 < m && board[row][col+1] != '#' && !used[row][col+1]) {
        path += 'P';
        if (dfs(board, used, path, row, col + 1)) return true;
        path.pop_back();
    }
    if (row + 1 < n && board[row+1][col] != '#' && !used[row+1][col]) {
        path += 'D';
        if (dfs(board, used, path, row + 1, col)) return true;
        path.pop_back();
    }
    return false;
}

void solve() {
    std::cin >> n >> m;
    std::vector<std::string> board(n);
    for (auto& s : board) std::cin >> s;
    std::vector<std::vector<char> > used(n, std::vector<char>(m, false));
    std::string path;
    if (dfs(board, used, path, 0, 0)) {
        std::cout << "TAK" << '\n';
        std::string taprow = std::string(n, 'N');
        std::string tapcol = std::string(m, 'N');
        int row = 0, col = 0;
        if (board[0][0] == '@') {
            if (path[0] == 'P') tapcol[0] = 'T';
            else                taprow[0] = 'T';
        }
        for (int i = 0; i < path.length(); i++) {
            if (path[i] == 'P') col++;
            else                row++;
            if (board[row][col] == '@' && tapcol[col] == 'N' && taprow[row] == 'N'
            ||  board[row][col] == 'O' && (tapcol[col] == 'T' || taprow[row] == 'T')) {
                if (path[i] == 'P') tapcol[col] = 'T';
                else                taprow[row] = 'T';
            }
        }
        std::cout << taprow << '\n';
        std::cout << tapcol << '\n';
        std::cout << path   << '\n';
    }
    else
        std::cout << "NIE" << '\n';
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    std::cin >> t;
    while (t--) solve();
}
