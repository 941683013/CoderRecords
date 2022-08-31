#include "bits/stdc++.h"

using namespace std;

main() {
	
	int t;
	cin>>t;
	
	while(t--) {
		int n, k;
		cin>>n>>k;
		string s;
		cin>>s;
		unordered_map<char, int> mp;
		for(int i = 0; i < s.size(); i++) {
			mp[s[i]]++;
		}
		int pair = 0, cnt = 0;
		for(char ch = 'a'; ch <= 'z'; ch++) {
			if(mp[ch] & 1) {
				cnt++;
			}
			pair += mp[ch] / 2;
		}
		int d = pair / k;
		
		if(pair % k == 0) {
			if(cnt >= k) {
				cout<<2 * d + 1<<endl;
			}
			else {
				cout<<2 * d<<endl;
			}
		}
		else {
			if(2 * (pair % k) + cnt >= k) {
				cout<<2 * d + 1<<endl;
			}
			else {
				cout<<2 * d<<endl;
			}
		}
	}
	
	return 0;
}