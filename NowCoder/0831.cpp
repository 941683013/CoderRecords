#include "bits/stdc++.h"
#define int long long 
using namespace std;
signed main() {
	
	
	int t;
	cin>>t;
	
	while(t--) {
		
		int n;
		cin>>n;
		priority_queue<int> odd, even;
		for(int i = 0; i < n; i++) {
			int d;
			cin>>d;
			if(d & 1) odd.push(d);
			else even.push(d);
		}
		int a = 0, b = 0;
		while(odd.size() || even.size()) {
			
			if(odd.size() && even.size()) {
				if(even.top() > odd.top()) {
					a += even.top();
					even.pop();
				}
				else {
					odd.pop();
				}
			}
			else {
				if(even.size()) {
					a += even.top();
					even.pop();
				}
				else {
					odd.pop();
				}
			}
			
			if(even.size() && odd.size()) {
				if(odd.top() > even.top()) {
					b += odd.top();
					odd.pop();
				}
				else {
					even.pop();
				}
			}
			else {
				if(odd.size()) {
					b += odd.top();
					odd.pop();
				}
				else if(even.size()) {
					even.pop();
				}
			}
		}
		if(a > b) {
			cout<<"Alice"<<endl;
		}
		else if(a < b) {
			cout<<"Bob"<<endl;
		}
		else {
			cout<<"Tie"<<endl;
		}
	}
	
	return 0;
}