#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long

using namespace std;

bool ispeak(int* a, const int& i){
  return (a[i-1]<a[i] && a[i]>a[i+1]);
}

int main(){
  ios_base::sync_with_stdio(false);
  int t, n, k, maxpeaks;
  cin >> t;
  while(t--)
  {
    cin>>n>>k;
    int a[n];
    std::vector<int> peaks(n-k+1, 0);
    cin>>a[0]>>a[1];
    for (int i = 2; i < k; ++i)
    {
      cin>>a[i];
      peaks[0] += ispeak(a, i-1);
    }
    maxpeaks=peaks[0];
    for (int i = k; i < n; ++i)
    {
      cin>>a[i];
      maxpeaks = max(maxpeaks,
      peaks[i-k+1]=peaks[i-k]-(ispeak(a, i-k+1))+ispeak(a, i-1));
    }
    for (int i = 0; i < peaks.size(); ++i)
    {
      if (maxpeaks == peaks[i])
      {
        cout<<maxpeaks+1<<' '<<i+1<<'\n';
        break;
      }
    }
  }
  return 0;
}
