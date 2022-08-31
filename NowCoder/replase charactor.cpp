#include "bits/stdc++.h"

using namespace std;

int main() {
	
	int n, m;
	cin>>n>>m;
	string s;
	cin>>s;
	
	int res = 0;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '.') cnt++;
		else {
			if(cnt != 0) {
				res += cnt - 1;
				cnt = 0;
			}
		}
	}
	
	if(cnt != 0) res += cnt - 1;
	
	while(m--) {
		int x;
		char ch;
		cin>>x>>ch;
		x--;
		if(ch != '.') {
			if(s[x] == '.') {
				if(x - 1 >= 0 && s[x - 1] == '.') {
					res--;
				}
				if(x + 1 < n && s[x + 1] == '.') {
					res--;
				}
			}
		}
		else {
			if(s[x] != '.') {
				if(x - 1 >= 0 && s[x - 1] == '.') {
					res++;
				}
				if(x + 1 < n && s[x + 1] == '.') {
					res++;
				}
			} 
		}
		s[x] = ch;
		cout<<res<<endl;
		
	}
	
	return 0;
}