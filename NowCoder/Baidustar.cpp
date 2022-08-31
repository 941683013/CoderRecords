#include<bits/stdc++.h> 
#define int long long
using namespace std;
const int mod = 998244353;
signed main( )
{
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<bool>> graph(n + 1, vector<bool>(m + 1, false));
    for(int i = 0; i < k; i++) {
        int x, y;
        cin>>x>>y;
        graph[x][y] = 1;
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[0][0] = 1;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            dp[i][j] = (i - 1 >= 0 && !graph[i - 1][j] ? dp[i - 1][j] : 0) + 
            (j - 1 >= 0 && !graph[i][j - 1] ? dp[i][j - 1] : 0);
        }
    }
    int res = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(graph[i][j]) {
                res = (res + dp[n][m] * dp[i][j]) % mod;
            }
        }
    }
    cout<<res<<endl;
    
    return 0;
}