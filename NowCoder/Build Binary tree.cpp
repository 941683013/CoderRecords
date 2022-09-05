#include "bits/stdc++.h"
using namespace std;

struct node{
	int lchild;
	int rchild;
};
const int N = 110;
node tree[N];
int val[N];
int idx;
void dfs(int root, vector<int> &v) {
	if(root == -1) return;
	dfs(tree[root].lchild, v);
	val[root] = v[idx++];
	dfs(tree[root].rchild, v);
	
}

int main() {
	
	int n;
	cin>>n;
	for(int i = 0; i < n; i++) {
		int l, r;
		cin>>l>>r;
		tree[i] = {l, r};
	}
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin>>v[i];
	sort(v.begin(), v.end());
	dfs(0, v);
	vector<int> res;
	queue<int> q;
	q.push(0);
	while(q.size()) {
		int size = q.size();
		for(int i = 0; i < size; i++) {
			int cur = q.front(); q.pop();
			res.push_back(val[cur]);
			if(tree[cur].lchild != -1) q.push(tree[cur].lchild);
			if(tree[cur].rchild != -1) q.push(tree[cur].rchild);
		}
	}
	printf("%d", res[0]);
	for(int i = 1; i < res.size(); i++) {
		printf(" %d", res[i]);
	}
	
	
	return 0;
}