#include "bits/stdc++.h"
#define int long long

using namespace std;
int n, m, p, a, b, c;


inline __int128 read(){
    __int128 x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
inline void print(__int128 x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

signed main() {
	
	int t;
	cin>>t;
	
	while(t--) {
		__int128 x;
		cin>>n>>m>>p;
		x = read();
		cin>>a>>b>>c;
		
		unordered_map<int, int> mp;
		for(int i = 0; i < n; i++) {
			x = (a * x * x + b * x + c) % p;
			if(mp.find(x) == mp.end()) {
				mp[x] = i;
			}
		}
		int res = 0;
		for(int i = 0; i < m; i++) {
			x = (a * x * x + b * x + c) % p;
			if(mp.find(x) != mp.end()) {
				res = min(n - mp[x], m - i);
				break;
			}
		}
		cout<<res<<endl;
		
	}
	
	
	return 0;
}
