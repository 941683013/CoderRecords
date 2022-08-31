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
		int x, y;
		cin>>x>>y;
		x = find(x);
		y = find(y);
		if(x > y) swap(x, y);
		if(x != y) f[x] = y;
	}
	int res = 0;
	for(int i = 1; i <= n; i++) {
		int x = find(i);
		while(i < x) {
			int y = find(i);
			if(x != y) {
				if(y > x) swap(x, y);
				f[y] = x;
				res++;
			}
			i++;
		}
	}
	
	cout<<res;
	
	return 0;
}