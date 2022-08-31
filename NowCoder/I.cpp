#include "bits/stdc++.h"

using namespace std;

main() {
	
	int n, m;
	cin>>n>>m;
	string s;
	cin>>s;
	int cnt = 0;
	int res = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '.') {
			cnt++;
		}
		else {
			if(cnt)
				res += cnt - 1;
			cnt = 0;
		}
	}
	if(cnt) res += cnt - 1;
	while(m--) {
		int x;
		char ch;
		cin>>x>>ch;
		x--;
		if(s[x] == '.' && ch == '.') {
			cout<<res<<endl;
		}
		else if(s[x] != '.' && ch != '.') {
			cout<<res<<endl;
		}
		else if(s[x] == '.'){
			s[x] = ch;
			int l = 0, r = 0;
			for(int i = x - 1; i >= 0; i--) {
				if(s[i] == '.') {
					l++;
				}
				else break;
			}
			for(int i = x + 1; i < s.size(); i++) {
				if(s[i] == '.')r++;
				else break;
			}
			res -= (l + r);
			if(l) res += l - 1;
			if(r) res += r - 1;
			cout<<res<<endl;
		}
		else if(ch == '.') {
			s[x] = ch;
			int l = 0, r = 0;
			for(int i = x - 1; i >= 0; i--) {
				if(s[i] == '.') l++;
				else break;
			}
			for(int i = x + 1; i < s.size(); i++) {
				if(s[i] == '.')r++;
				else break;
			}
			res += (l + r);
			if(l) res -= l - 1;
			if(r) res -= r - 1;
			cout<<res<<endl;
		}
	}
	
	return 0;
}