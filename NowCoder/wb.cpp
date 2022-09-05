#include "bits/stdc++.h"
#define P pair<int, int>
using namespace std;
vector<vector<int>> edge;
int n, l;
int bfs(int s) {
	
	queue<P> q;
	q.push({s, 0});
	vector<bool> vis(n + 1, false);
	vis[s] = true;
	int cnt = 0;
	while(q.size()) {
		P cur = q.front();
		q.pop();
		int t = cur.first;
		int layer = cur.second;
		for(auto next : edge[t]) {
			if(!vis[next] && layer + 1 <= l) {
				vis[next] = true;
				cnt++;
				q.push({next, layer + 1});
			}
			
		}
	}
	return cnt;
}

int main() {
	
	
	cin>>n>>l;
	edge.resize(n + 1);
	for(int i = 1; i <= n; i++) {
		int k;
		cin>>k;
		for(int j = 1; j <= k; j++) {
			int u;
			cin>>u;
			edge[u].push_back(i);
		}
	}
	int q;
	cin>>q;
	while(q--) {
		int x;
		cin>>x;
		cout<<bfs(x)<<endl;
	}
	
	
	return 0;
}