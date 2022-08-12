#include "bits/stdc++.h"
#define int long long
using namespace std;

signed main() {
// @address https://ac.nowcoder.com/acm/contest/38457/D
	int n, m;
	cin>>n>>m;
	
	vector<string> a(n);
	for(int i = 0; i < n; i++) cin>>a[i];
	
	string s, t;
	cin>>s>>t;
	if(s == t) {
		cout<<0<<endl;
		cout<<s<<endl;
		cout<<t<<endl;
		return 0;
	}
	a.push_back(t);
	a.push_back(s);
	unordered_map<string, vector<string>> edge;
	for(int i = 0; i < a.size(); i++) {
		for(int j = 0; j < a.size(); j++) {
			if(i == j) continue;
			int cnt = 0;
			for(int l = 0; l < m; l++) {
				if(a[i][l] != a[j][l]) {
					cnt++;
				}
			}
			if(cnt == 1) {
				edge[a[i]].push_back(a[j]);
			}
		}
	}
	queue<vector<string>> q;
	unordered_map<string, bool> vis;
	vis[s] = true;
	vector<string> temp(1, s);
	q.push(temp);
	
	vector<string> res;
	while(q.size()) {
		vector<string> v = q.front(); q.pop();
		
		string str = v.back();
		if(str == t) {
			res = v;
			break;
		}
		
		for(auto stri : edge[str]) {
			if(!vis[stri]) {
				vis[stri] = true;
				v.push_back(stri);
				q.push(v);
				v.pop_back();
			}
			
		}
	}
	
	if(res.size() == 0) {
		cout<<-1<<endl;
	}
	else {
		cout<<res.size() - 2<<endl;
		for(int i = 0; i < res.size(); i++) {
			cout<<res[i]<<endl;
		}
	}
	
	
	return 0;
}