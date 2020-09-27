#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair< pair< ll ,ll >, ll > max_cross(vector<int> &nums, ll low, ll mid, ll high){
	ll links = -1000000000000;
	ll sum = 0;
	ll maxLinks = -100;
	for(ll i = mid; i >= low; --i){
		sum += nums[i];
		if( sum > links ){
			links = sum;
			maxLinks = i;
		}
	}
	ll rechts = -1000000000000;
	sum = 0;
	ll maxRechts = -100;
	for(ll j = mid + 1; j <= high; ++j){
		sum += nums[j];
		if( sum > rechts ){
			rechts = sum;
			maxRechts = j;
		}
	}
	return {{maxLinks, maxRechts}, links + rechts};
}

pair< pair< ll ,ll >, ll > max_sub(vector<int> &nums, ll low, ll high){
	if( high == low){
		return {{low, high}, nums[low]};
	}
	else{
		long long mid = (low + high) / 2;
		ll leftLow, leftHigh, links;
		auto x = max_sub(nums, low, mid);
		leftLow = x.first.first;
		leftHigh = x.first.second;
		links = x.second;
		ll rightLow, rightHigh, rechts;
		auto y = max_sub(nums, mid + 1, high);
		rightLow = y.first.first;
		rightHigh = y.first.second;
		rechts = y.second;
		ll crossLow, crossHigh, crossSum;
		auto z = max_cross(nums, low, mid, high);
		crossLow = z.first.first;
		crossHigh = z.first.second;
		crossSum = z.second;
		if( links >= rechts && links >= crossSum ){
			return {{leftLow, leftHigh}, links};
		}
		else{
			if( crossSum >= links && crossSum >= rechts ){
				return {{crossLow, crossHigh}, crossSum};
			}
			else{
				return {{rightLow, rightHigh}, rechts};
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; ++i) cin >> nums[i];
	auto it = max_sub(nums, 0, n - 1);

	long long leftidx = it.first.first;
	long long links = 0;
	for(int i = it.first.first - 1; i >= 0; --i){
		links += nums[i];
		if( links == 0){
			leftidx = i;
		}
	}
	long long rightidx = it.first.second;
	long long rechts = 0;
	for(int i = it.first.second; i >= leftidx; --i){
		rechts += nums[i];
		if( rechts == 0){
			rightidx = i;
		}
	}
	cout << leftidx + 1 << ' ' << rightidx + 1 << '\n';
}
