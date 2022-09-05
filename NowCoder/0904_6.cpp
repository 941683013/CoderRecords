#include "bits/stdc++.h"
#define int long long
using namespace std;

const int N = 1e6 + 10;
int a[N];
int v[N];

signed main() {
	
	int n, m;
	cin>>n>>m;
	int mx = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		mx = max(mx, a[i]);
		v[i] = v[i - 1] + a[i] * mx;
		cout<<i<<" "<<v[i]<<endl;
	}
	
	while(m--) {
		int l, r;
		cin>>l>>r;
		printf("%d\n", v[r] - v[l - 1]);
	}
	
	
	
	return 0;
}