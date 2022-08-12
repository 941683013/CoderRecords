#include "bits/stdc++.h"

using namespace std;

int main() {
	
	string s;
	cin>>s;
	
	stack<char> sk;
	int cnt = 0;
	for(int i = 0; i < s.size(); i++) {
		if(sk.size()) {
			if(sk.top() == s[i]) {
				cnt++;
				sk.pop();
			}
			else {
				sk.push(s[i]);
			}
		}
		else {
			sk.push(s[i]);
		}
	}
	if(cnt & 1) {
		cout<<"Yes"<<endl;
	}
	else {
		cout<<"No"<<endl;
	}
	
	return 0;
}