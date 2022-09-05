#include "bits/stdc++.h"
#define int long long
using namespace std;

const int N = 1e6 + 10;

bool primes[N];

void f() {
	for(int i = 2; i * i <= 1e12; i++) {
		if(!primes[i]) {
			for(int j = i * i; j < N; j += i) {
				primes[j] = true;
			}
		}
	}
}

signed main() {


	f();
	primes[1] = true;
	int t;
	cin>>t;
	unordered_map<int, bool> mp;
	for(int i = 1; i <= 1e6; i++) {
		mp[i * i] = true;
	}
	
	
	while(t--) {
		int n;
		cin>>n;
		int x = sqrt(n);
		if(mp[n] && !primes[x]) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
	}
	
	return 0;
}	