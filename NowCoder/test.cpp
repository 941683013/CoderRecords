#include "bits/stdc++.h"
#define int long long
using namespace std;

const int N = 2e5 + 10;
int f[N];

int find(int x) {
	if(f[x] == 0) return x;
	return f[x] = find(f[x]); 
}

signed main() {
	
	int n, m;
	cin>>n>>m;
	
	for(int i = 0; i < m; i++) {
		int a, b;
		cin>>a>>b;
		a = find(a), b = find(b);
		if(a > b) swap(a, b);
		if(a != b) f[a] = b;
	}
	
	int res = 0;
	for(int i = 1; i <= n; i++) {
		int t = find(i);
		while(i < t) {
			int x = find(i);
			if(t < x) swap(t, x);
			if(t != x) {
				f[x] = t;
				res++;
				cout<<i<<" "<<t<<" "<<x<<endl;
			}
			i++;
		}
	}
	
	cout<<res;
	
	
	return 0;
}