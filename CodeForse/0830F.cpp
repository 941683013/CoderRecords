#include "bits/stdc++.h"
#define int long long
using namespace std;
const int mod = 1e9 + 7;

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

int f(__int128 a, __int128 b) {
	__int128 res = 1;
	while(b) {
		if(b & 1) res = res * a % mod;
		b /= 2;
		a = a * a % mod;
	}
	return res % mod;
	
}
signed main() {
	__int128 n;
	n = read();
	if(n == 0) {
		printf("1");
	}
	else {
		print((f(2, n - 1) + f(2, 2 * n - 1)) % mod);
	}
	
	
	
	return 0;
}