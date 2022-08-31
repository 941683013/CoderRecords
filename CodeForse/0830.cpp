#include "bits/stdc++.h"
#define int long long
using namespace std;

signed main() {
	
	
	int t;
	cin>>t;
	
	while(t--) {
		
		int a, s;
		cin>>a>>s;
		string res;
		bool f = true;
		while(a && s) {
			int sum = s % 10;
			s /= 10;
			int cur = a % 10;
			a /= 10;
			if(sum >= cur) {
				res += '0' + (sum - cur);
			}
			else {
				sum += (s % 10) * 10;
				s /= 10;
				if(sum >= cur && sum - cur < 10) {
					res += '0' + sum - cur;
				}
				else {
					f = false;
					break;
				}
			}
		}
		if(a) f = false;
		
		while(s) {
			int d = s % 10;
			res += '0' + d;
			s /= 10;
		}
		if(f) {
			reverse(res.begin(), res.end());
			cout<<stoll(res)<<endl;
		}
		else {
			cout<<-1<<endl;
		}
	}
	
	return 0;
}