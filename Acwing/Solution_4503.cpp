#include "bits/stdc++.h"

using namespace std;

int main() {
	
	int a, b, n;
	cin>>a>>b>>n;
	int res = 0;
	for(int i = 0; i <= a; i++) {
		int y = n - i;
		if(y >= 0 && y <= b) res++;
	}
	
	cout<<res<<endl;
	
	return 0;
}