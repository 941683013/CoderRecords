#include "bits/stdc++.h"
#define P pair<int, int>
using namespace std;

const int N = 3e3 + 10;
bool vis[N][N];
P v[N];

int main() {
	
	
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		x += 1000;
		y += 1000;
		v[i] = {x, y};
		vis[x][y] = true;
	}
	
	int res = 0;
	
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			int x = v[i].first + v[j].first;
			int y = v[i].second + v[j].second;
			if(x % 2 == 0 && y % 2 == 0 && vis[x / 2][y / 2]) {
				res++;
			}
		}
	}
	
	printf("%d", res);
	
	return 0;
}