#include "bits/stdc++.h"
#define int long long
using namespace std;

signed main() {
// @address https://ac.nowcoder.com/acm/contest/38457/A	
	int t;
	cin>>t;
	
	while(t--) {
		int n;
		cin>>n;
		priority_queue<int> q;
		for(int i = 1; i <= n; i++) {
			int d;
			cin>>d;
			q.push(d);
		}
		int res = 0;
		while(q.size() > 1) {
			int x = q.top(); q.pop();
			int y = q.top(); q.pop();
			res += (x + y);
			if(res < 0) {
				res -= (x + y);
				break;
			}
			q.push(x + y);
		}
		cout<<res<<endl;
	}
	
	
	return 0;
}