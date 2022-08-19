#include "bits/stdc++.h"

using namespace std;

int main() {
	
	int n, m;
	cin>>n>>m;
	
	vector<int> v(n), cnt(m + 1, 0);
	
	queue<int> q, q1;
	for(int i = 1; i <= m; i++) q.push(i);
	int res = 0;
	for(int i = 0; i < n; i++) {
		int d;
		cin>>d;
		q1.push(d);
		cnt[d]++;
		while(q.size() && cnt[q.front()] > 0) {
			q.pop();
		}
		if(q.size() == 0) {
			res += (n - i);
			int x = q1.front();
			q1.pop();
			cnt[x]--;
			if(cnt[x] == 0) q.push(x);
		}
	}
	
	while(q.size() == 0) {
		res++;
		int x = q1.front();
		q1.pop();
		cnt[x]--;
		if(cnt[x] == 0) q.push(x);
	}
	
	cout<<res<<endl;
	
	return 0;
}