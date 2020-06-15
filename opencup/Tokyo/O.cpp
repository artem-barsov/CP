#include <bits/stdc++.h>

using namespace std;

void parse(const std::string expr, std::string & num1, char & op, std::string & num2, std::string & num3) {
    int i = 0;
    while ((expr[i] != '+')&&((expr[i] != '-')||(i==0))&&(expr[i] != '*')) {
        num1 += expr[i++];
    }
    op = expr[i++];
    while (expr[i] != '=') {
        num2 += expr[i++];
    }
    num3 = expr.substr(i+1, expr.length()-i);
}
// -0
int main(int argc, char const *argv[]) {
    std::string expr;
    std::cin >> expr;
    std::vector<bool> used(10);
    std::vector<int> fragen;
    for (int i = 0; i < expr.length(); i++) {
        if ((expr[i] >= '0') && (expr[i] <= '9'))
            used[expr[i] - '0'] = true;
        if (expr[i] == '?') fragen.push_back(i);
    }
    for (char digit = '0'; digit <= '9'; digit++) {
        if (used[digit - '0']) continue;
        for (int j = 0; j < fragen.size(); j++) {
            expr[fragen[j]] = digit;
        }
        std::string num1="", num2="", num3="";
        char op;
        parse(expr, num1, op, num2, num3);
        if (   ((num1[0] == '0') && (num1.length() > 1))
            || ((num2[0] == '0') && (num2.length() > 1))
            || ((num3[0] == '0') && (num3.length() > 1))
            || ((num1[0] == '-') && (num1[1] == '0'))
            || ((num2[0] == '-') && (num2[1] == '0'))
            || ((num3[0] == '-') && (num3[1] == '0'))
        ) continue;
        // std::cout << num1 << op << num2 << '=' << num3 << '\t';
        // std::cout << atoi(num1.c_str()) <<op<< atoi(num2.c_str()) <<'='<< atoi(num3.c_str()) << '\n';
        if (op == '+') {
            if (atoi(num1.c_str()) + atoi(num2.c_str()) == atoi(num3.c_str())) {
                std::cout << digit << '\n';
                return 0;
            }
        }
        else if (op == '-') {
            if (atoi(num1.c_str()) - atoi(num2.c_str()) == atoi(num3.c_str())) {
                std::cout << digit << '\n';
                return 0;
            }
        }
        else if (op == '*') {
            if ((long long)((long long)atoi(num1.c_str()) * (long long)atoi(num2.c_str())) == (long long)atoi(num3.c_str())) {
                std::cout << digit << '\n';
                return 0;
            }
        }
    }
    std::cout << -1 << '\n';
}
