#include "bits/stdc++.h"
#define int  long long
using namespace std;
const int mod = 1e9 + 7;

int f(int a, int b) {
	int res = 1;
	while(b) {
		if(b & 1) res = res * a % mod;
		b /= 2;
		a = a * a % mod;
	}
	return res;
}

signed main() {
	
	cout<<(-1) % mod<<endl;
	
//	int n, q;
//	cin>>n>>q;
//	vector<int> cnt(n + 1, 0);
//	
//	string s;
//	cin>>s;
//	for(int i = 0; i < s.size(); i++) {
//		if(s[i] == '1') {
//			
//			cnt[i + 1] = cnt[i] + 1;
//		}
//		else {
//			cnt[i + 1] = cnt[i];
//		}
//	}
//	
//	while(q--) {
//		int l, r;
//		cin>>l>>r;
//		int x = cnt[r] - cnt[l - 1];
//		int y = r - l + 1 - x;
//		if(x == 0) cout<<0<<endl;
//		else {
//			int d = f(2, x) - 1;
//			int m = f(2, y);
//			cout<<d * m % mod<<endl;
//		}
//		
//	}

	
	return 0;
}