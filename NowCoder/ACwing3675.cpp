#include "bits/stdc++.h"
#define int long long
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

struct node {
	int dirCnt;
	int x;
	int y;
	int dir;
	bool operator<(const node &val) const {
		return dirCnt > val.dirCnt;
	}
};

signed main() {
	
	int t;
	cin>>t;
	int mx = 1e9;
	while(t--) {
		int m, n;
		cin>>m>>n;
		vector<string> s(m);
		vector<vector<int>> dis(m + 1, vector<int>(n + 1, mx));
		for(int i = 0; i < m; i++) cin>>s[i];
		int k, x1, y1, x2, y2;
		cin>>k>>y1>>x1>>y2>>x2;
		
		priority_queue<node> q;
		for(int i = 0; i < 4 ; i++) {
			q.push({0, x1, y1, i});	
		}
		
		while(q.size()) {
			node cur = q.top();
			q.pop();
			
			int x = cur.x, y = cur.y;
			int cnt = cur.dirCnt, dir = cur.dir;
			printf("(%d, %d) cnt = %d\n", x, y, cnt);
			
			for(int i = 0; i < 4; i++) {
				int a = x + dx[i];
				int b = y + dy[i];
				if(a >= 1 && a <= m && b >= 1 && b <= n && s[a - 1][b - 1] == '.') {
					if(i != dir) {
						if(cnt == k) {
							continue;
						}
						else {
							if(dis[a][b] >= cnt + 1) {
								dis[a][b] = cnt + 1;
								q.push({cnt + 1, a, b, i});
							}
						}
					}
					else if(dis[a][b] >= cnt) {
						dis[a][b] = cnt;
						q.push({cnt, a, b, i});
					}
				}
			}
		}
		cout<<dis[x2][y2]<<endl;
		if(dis[x2][y2] > k) {
			cout<<"no"<<endl;
		}
		else {
			cout<<"yes"<<endl;
		}
		
	}
	
	
	return 0;
}