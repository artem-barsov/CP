#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	v.reserve(600);
	int k;
	while (cin >> std::hex >> k) {
		v.push_back(k);
	}
	bool is_pascal = false;
	bool is_cstyle = false;
	int size = v.size();
	int iter = 0;
	while (iter < size) {
		if (v[iter] == '\0') {
			is_cstyle = true;
			break;
		}
		if (v[iter] < 0x20 ||
	        v[iter] > 0x7f) {
			break;
		}
		++iter;
	}
	if (!v.empty() && v[0] < size) {
		int last = v.front() + 1;
		iter = 1;
		while (iter < last) {
			if (v[iter] < 0x20 ||
				v[iter] > 0x7f) {
				break;
			}
			++iter;
		}
		is_pascal = iter >= last;
	}
	if (is_cstyle && is_pascal)
		cout << "Both\n";
	if (is_cstyle && !is_pascal)
		cout << "C\n";
	if (!is_cstyle && is_pascal)
		cout << "Pascal\n";
	if (!is_cstyle && !is_pascal)
		cout << "None\n";
}
