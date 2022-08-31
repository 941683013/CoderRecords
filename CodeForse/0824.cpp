#include "bits/stdc++.h"
#define int long long
#define P pair<int, int>
using namespace std;

signed main() {
	
	int t;
//	cin>>t;
	t = 1;
	while(t--) {
		int n, x;
		cin>>n>>x;
		vector<vector<int>> edge(n + 1);
		vector<int> dis(n + 1, 0);
		vector<int> col(n + 1, 0);
		for(int i = 1; i < n; i++) {
			int u, v;
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		
		queue<int> q;
		q.push(x);
		q.push(1);
		col[1] = 1;
		col[x] = 2;
		int maxDeep = 0;
		while(q.size()) {
			int cur = q.front();
			q.pop();
			
			for(int i = 0; i < edge[cur].size(); i++) {
				int next = edge[cur][i];
				if(col[next] == 1) continue;
				if(col[cur] == 1) {
					dis[next] = dis[cur] + 1;
					if(col[next] == 2) {
						maxDeep = max(maxDeep, dis[next]);
					}
					col[next] = 1;
					q.push(next);
				}
				else {
					if(col[next] == 2) continue;
					col[next] = col[cur];
					q.push(next);
				}
			}
		}
		
		cout<<maxDeep * 2<<endl;
		
	}
	
	return 0;
}