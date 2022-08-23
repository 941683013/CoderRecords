#include "bits/stdc++.h"
#define int long long
using namespace std;

const int N = 2e18 + 10;

signed main() {
	
	vector<int> (3, 1);
	v[0] = 0;
	int a = 1;
	int b = 1;
	while(true) {
		int c = a + b;
		if(c > N) break;
		v.push_back(c);
		a = b;
		b = c;
	}
	
	int t;
	cin>>t;
	
	while(t--) {
		
		
		int n;
		cin>>n;
		int d = lower_bound(v.begin() + 1, v.end()) - v.begin();
		int res = 0;
		if(abs(v[d - 1] - n) <= abs(v[d] - n)) {
			res = d - 1;
		}
		else {
			res = d;
		}
		cout<<res<<endl;
		
	}
	
	return 0;
}