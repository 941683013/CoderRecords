#include "bits/stdc++.h"
#define int long long
#define P pair<int, int>
using namespace std;

signed main() {
// @address https://ac.nowcoder.com/acm/contest/38457/C
	int n, h, m, q;
	cin>>n>>h>>m>>q;
	vector<P> v(n), res;
	for(int i = 0; i < n; i++) {
		
		int hl, ml, hr, mr;
		cin>>hl>>ml>>hr>>mr;
		v.push_back({hl * m + ml, hr * m + mr});	
	}
	sort(v.begin(), v.end());
	int x = 0, y = 0;
	for(int i = 0; i < v.size(); i++) {
		int l = v[i].first, r = v[i].second;
		if(l <= y) {
			y = max(y, r);
		}
		else {
			res.push_back({x, y});
			x = l;
			y = r;
		}
		if(i == v.size() - 1) {
			res.push_back({x, y});
		}
	}
	
	vector<int> vec(res.size());
	for(int i = 0; i < res.size(); i++) {
		vec[i] = res[i].first;
	}
	
	while(q--) {
		int hl, ml;
		cin>>hl>>ml;
		int l = hl * m + ml;
		int d = upper_bound(vec.begin(), vec.end(), l) - vec.begin() - 1;
		if(d >= 0 && res[d].second >= l) {
			cout<<"No"<<endl;
		}
		else {
			cout<<"Yes"<<endl;
		}
	}
	
	return 0;
}