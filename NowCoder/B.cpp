#include "bits/stdc++.h"
#define int long long
using namespace std;
const int N = 1e6 + 10;
int a[N];
signed main() {
// @address https://ac.nowcoder.com/acm/contest/38457/B
	int n, m;
	cin>>n>>m;
	int res = 0;
	for(int i = 1; i <= n; i++) {
		int l, r, s;
		cin>>l>>r>>s;
		a[l] += s;
		a[r + 1] -= s;
		res += s;
	}
	int mn = 0x7f7f7f7f;
	for(int i = 1; i <= m; i++) {
		
		a[i] += a[i - 1];
		if(mn > a[i]) mn = a[i];
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<res<<" "<<mn<<endl;
	cout<<res - mn<<endl;
	return 0;
}