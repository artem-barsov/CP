#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstring>

class BigInt {
public:
	BigInt(const BigInt& x) {
		digits = x.digits;
	}
	BigInt operator=(const BigInt& x) {
		digits = x.digits;
		return *this;
	}
	BigInt operator=(BigInt&& x) {
		digits = std::move(x.digits);
		return *this;
	}
	bool zero() {
		return digits.back() == 0;
	}
	BigInt() {
		digits.push_back(0);
	}
	BigInt(const std::string& number) {
		if (number.size() == 0) {
			digits.push_back(0);
		}
		else {
			for (int i = number.size(); i > 0; i -= m_pow) {
				if (i < (int)m_pow) {
					digits.push_back(atoi(number.substr(0, i).c_str()));
				}
				else {
					digits.push_back(atoi(number.substr(i - m_pow, m_pow).c_str()));
				}
			}
			while (digits.size() > 1 && digits.back() == 0) {
				digits.pop_back();
			}
		}
	}
	friend BigInt operator+(const BigInt& x_value, const BigInt& y_value);
	friend BigInt operator-(const BigInt& x_value, const BigInt& y_value);
	friend BigInt operator*(const BigInt& x_value, const BigInt& y_value);
	friend BigInt operator*(const BigInt& x_value, const int y_value);
	friend BigInt operator/(BigInt x_value, BigInt y_value);
	friend BigInt operator^(BigInt x_value, size_t power);
	friend bool operator<(const BigInt& x_value, const BigInt& y_value);
	friend bool operator>(const BigInt& x_value, const BigInt& y_value);
	friend bool operator<=(const BigInt& x_value, const BigInt& y_value);
	friend bool operator>=(const BigInt& x_value, const BigInt& y_value);
	friend bool operator==(const BigInt& x_value, const BigInt& y_value);
	friend bool operator!=(const BigInt& x_value, const BigInt& y_value);
	friend std::ostream& operator<< (std::ostream& out, const BigInt& value);

	friend int compare(const BigInt& x_value, size_t x_at, size_t x_to, const BigInt& y_value, size_t y_at, size_t y_to);
	friend void subtract(BigInt& x_value, int x_at, const BigInt& y_value, int y_at, int y_to);

private:
	BigInt(size_t capacity) :
		digits(capacity) {}
	bool sign;
	const size_t m_pow = 5;
	const size_t m_base = 100000;
	std::vector<int> digits;
};

int compare(const BigInt& x_value, size_t x_at, size_t x_to, const BigInt& y_value, size_t y_at, size_t y_to) {
	while (x_value.digits[x_to] == 0 && x_to > x_at) {
		--x_to;
	}
	while (y_value.digits[y_to] == 0 && y_to > y_at) {
		--y_to;
	}
	if (x_to - x_at != y_to - y_at) {
		if (x_to - x_at < y_to - y_at) {
			return -1;
		}
		else {
			return +1;
		}
	}
	while (x_at < x_to) {
		if (x_value.digits[x_to] != y_value.digits[y_to]) {
			return x_value.digits[x_to] - y_value.digits[y_to];
		}
		--x_to, --y_to;
	}
	return x_value.digits[x_at] - y_value.digits[y_at];
}

void subtract(BigInt& x_value, int x_at, const BigInt& y_value, int y_at, int y_to) {
	int overflow = 0;
	while (y_to >= y_at) {
		x_value.digits[x_at] = x_value.digits[x_at] - y_value.digits[y_at] - overflow;
		if (x_value.digits[x_at] < 0) {
			x_value.digits[x_at] += x_value.m_base;
			overflow = 1;
		}
		else {
			overflow = 0;
		}
		++y_at, ++x_at;
	}
	if (overflow) {
		x_value.digits[x_at] = x_value.digits[x_at] - overflow;
		if (x_value.digits[x_at] < 0) {
			x_value.digits[x_at] += x_value.m_base;
			overflow = 1;
		}
		else {
			overflow = 0;
		}
	}
}

std::ostream& operator<< (std::ostream& out, const BigInt& value) {
	auto i = value.digits.rbegin();
	auto j = value.digits.rend();
	out << *i++;
	while (i < j) {
		out << std::setfill('0') << std::setw(value.m_pow) << *i++;
	}
	return out;
}

BigInt operator+(const BigInt& x_value, const BigInt& y_value) {
	size_t overflow = 0;
	size_t x_value_size = x_value.digits.size();
	size_t y_value_size = y_value.digits.size();
	BigInt result;
	if (x_value_size < y_value_size) {
		result.digits.reserve(y_value_size + 1);
		result.digits.resize(y_value_size);
		for (size_t i = 0; i < x_value_size; ++i) {
			result.digits[i] = x_value.digits[i] + y_value.digits[i] + overflow;
			overflow = result.digits[i] / result.m_base;
			result.digits[i] = result.digits[i] % result.m_base;
		}
		for (size_t i = x_value_size; i < y_value_size; ++i) {
			result.digits[i] += y_value.digits[i] + overflow;
			overflow = result.digits[i] / result.m_base;
			result.digits[i] = result.digits[i] % result.m_base;
		}
	}
	else {
		result.digits.reserve(x_value_size + 1);
		result.digits.resize(x_value_size);
		for (size_t i = 0; i < y_value_size; ++i) {
			result.digits[i] = x_value.digits[i] + y_value.digits[i] + overflow;
			overflow = result.digits[i] / result.m_base;
			result.digits[i] = result.digits[i] % result.m_base;
		}
		for (size_t i = y_value_size; i < x_value_size; ++i) {
			result.digits[i] += x_value.digits[i] + overflow;
			overflow = result.digits[i] / result.m_base;
			result.digits[i] = result.digits[i] % result.m_base;
		}
	}
	if (overflow) {
		result.digits.push_back(overflow);
	}
	return result;
}


BigInt operator-(const BigInt& x_value, const BigInt& y_value) {
	size_t overflow = 0;
	BigInt result;
	size_t x_value_size = x_value.digits.size();
	size_t y_value_size = y_value.digits.size();
	result.digits.resize(x_value_size);
	for (size_t i = 0; i < y_value_size; ++i) {
		result.digits[i] = x_value.digits[i] - y_value.digits[i] - overflow;
		overflow = result.digits[i] < 0 ? (result.digits[i] += result.m_base, 1) : 0;
	}
	for (size_t i = y_value_size; i < x_value_size; ++i) {
		result.digits[i] = x_value.digits[i] - overflow;
		overflow = result.digits[i] < 0 ? (result.digits[i] += result.m_base, 1) : 0;
	}
	for (auto i = x_value_size - 1; i > 0 && result.digits[i] == 0; --i) {
		result.digits.pop_back();
	}
	return result;
}


BigInt operator*(const BigInt& x_value, const BigInt& y_value) {
	BigInt result(x_value.digits.size() + y_value.digits.size());
	memset(&result.digits.front(), 0, result.digits.size());
	for (size_t i = 0; i < x_value.digits.size(); ++i) {
		int overflow = 0;
		for (size_t j = 0; j < y_value.digits.size(); ++j) {
			long long unsigned ml = (long long unsigned)result.digits[i + j] + (long long unsigned)x_value.digits[i] * y_value.digits[j] + (long long unsigned)overflow;
			overflow = (int)(ml / result.m_base);
			result.digits[i + j] = (int)(ml - (long long unsigned)(overflow) * result.m_base);
		}
		for (size_t j = y_value.digits.size(); overflow; ++j) {
			long long unsigned ml = (long long unsigned)result.digits[i + j] + (long long unsigned)overflow;
			overflow = (int)(ml / result.m_base);
			result.digits[i + j] = (int)(ml - (long long unsigned) (overflow) * (long long unsigned)result.m_base);
		}
	}
	while (result.digits.size() > 1 && result.digits.back() == 0) {
		result.digits.pop_back();
	}
	return result;
}

BigInt operator*(const BigInt& x_value, const int y_value) {
	int overflow = 0;
	BigInt result(x_value.digits.size());
	memset(&result.digits.front(), 0, result.digits.size());
	for (size_t i = 0; i < x_value.digits.size(); ++i) {
		long long unsigned ml = (long long unsigned)x_value.digits[i] * y_value + overflow;
		overflow = (int)(ml / result.m_base);
		result.digits[i] = (int)(ml - (long long unsigned)(overflow) * result.m_base);
	}
	if (overflow) {
		result.digits.push_back(overflow);
	}
	return result;
}

BigInt operator^(BigInt x_value, size_t power) {
	BigInt result;
	result.digits.front() = 1;
	while (power) {
		if (power & 1) {
			result = result * x_value;
			--power;
		}
		else {
			x_value = x_value * x_value;
			power /= 2;
		}
	}
	return result;
}

BigInt operator/(BigInt x_value, BigInt y_value) {
	BigInt result;
	x_value = x_value * x_value.m_base;
	y_value = y_value * y_value.m_base;
	unsigned long long x_size = x_value.digits.size();
	unsigned long long y_size = y_value.digits.size();
	result.digits.resize(x_size - y_size + 1);
	unsigned long long norm = (unsigned long long)x_value.m_base / (y_value.digits.back() + 1);
	x_value = x_value * norm;
	y_value = y_value * norm;
	if (x_value.digits.size() == x_size) x_value.digits.push_back(0);
	for (int i = x_size - y_size; i > -1; --i) {
		unsigned long long sum = (unsigned long long)x_value.digits[i + y_size] * (unsigned long long)x_value.m_base + (unsigned long long)x_value.digits[i + y_size - 1];
		unsigned long long div = (unsigned long long)sum / (unsigned long long)y_value.digits[y_size - 1];
		unsigned long long mod = (unsigned long long)sum % (unsigned long long)y_value.digits[y_size - 1];
		while (mod < x_value.m_base && (div == x_value.m_base || (div * y_value.digits[y_size - 2] > ((unsigned long long)x_value.m_base * mod + x_value.digits[i + y_size - 2])))) {
			--div, mod += y_value.digits[y_size - 1];
		}
		BigInt multiply(y_value * div);
		if (compare(x_value, i, i + y_size, multiply, 0, multiply.digits.size() - 1) < 0) {
			--div;
			multiply = y_value * div;
		}
		subtract(x_value, i, multiply, 0, multiply.digits.size() - 1);
		result.digits[i] = div;
	}
	while (result.digits.size() > 1 && result.digits.back() == 0) {
		result.digits.pop_back();
	}
	return result;
}

bool operator<(const BigInt& x_value, const BigInt& y_value) {
	if (x_value.digits.size() < y_value.digits.size()) {
		return true;
	}
	if (x_value.digits.size() > y_value.digits.size()) {
		return false;
	}
	auto i = x_value.digits.crbegin();
	auto j = x_value.digits.crend();
	auto m = y_value.digits.crbegin();
	while (i < j && *i == *m) {
		++i, ++m;
	}
	if (i < j) {
		return *i < *m;
	}
	else {
		return false;
	}
}

bool operator>(const BigInt& x_value, const BigInt& y_value) {
	if (x_value.digits.size() > y_value.digits.size()) {
		return true;
	}
	if (x_value.digits.size() < y_value.digits.size()) {
		return false;
	}
	auto i = x_value.digits.crbegin();
	auto j = x_value.digits.crend();
	auto m = y_value.digits.crbegin();
	while (i < j && *i == *m) {
		++i, ++m;
	}
	if (i < j) {
		return *i > *m;
	}
	else {
		return false;
	}
}

bool operator<=(const BigInt& x_value, const BigInt& y_value) {
	if (x_value.digits.size() < y_value.digits.size()) {
		return true;
	}
	if (x_value.digits.size() > y_value.digits.size()) {
		return false;
	}
	auto i = x_value.digits.crbegin();
	auto j = x_value.digits.crend();
	auto m = y_value.digits.crbegin();
	while (i < j && *i == *m) {
		++i, ++m;
	}
	if (i < j) {
		return *i < *m;
	}
	else {
		return true;
	}
}

bool operator>=(const BigInt& x_value, const BigInt& y_value) {
	if (x_value.digits.size() > y_value.digits.size()) {
		return true;
	}
	if (x_value.digits.size() < y_value.digits.size()) {
		return false;
	}
	auto i = x_value.digits.crbegin();
	auto j = x_value.digits.crend();
	auto m = y_value.digits.crbegin();
	while (i < j && *i == *m) {
		++i, ++m;
	}
	if (i < j) {
		return *i > *m;
	}
	else {
		return true;
	}
}

bool operator==(const BigInt& x_value, const BigInt& y_value) {
	if (x_value.digits.size() != y_value.digits.size()) {
		return false;
	}
	auto i = x_value.digits.crbegin();
	auto j = x_value.digits.crend();
	auto m = y_value.digits.crbegin();
	while (i < j && *i == *m) {
		++i, ++m;
	}
	return i == j;
}

bool operator!=(const BigInt& x_value, const BigInt& y_value) {
	if (x_value.digits.size() != y_value.digits.size()) {
		return true;
	}
	auto i = x_value.digits.crbegin();
	auto j = x_value.digits.crend();
	auto m = y_value.digits.crbegin();
	while (i < j && *i == *m) {
		++i, ++m;
	}
	return i != j;
}

using namespace std;
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	std::string x; cin >> x;
	BigInt x_value(x);
	BigInt m_value(" 998244353");
	BigInt y_value = x_value / m_value;
	BigInt r_value = x_value - y_value * m_value;
	cout << r_value << "\n";
	return 0;

}
