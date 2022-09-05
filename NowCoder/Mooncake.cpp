#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 10;
struct node{
    double num;
    double prices;
    double avg;
};
bool cmp(node a, node b) {
    return a.avg > b.avg;
}
double num[N];
double prices[N];

int main() {
    
    int n, sum;
    cin>>n>>sum;
    vector<node> v(n);
    for(int i = 1; i <= n; i++) {
        cin>>num[i];
    }
    for(int j = 1; j <= n; j++) {
        cin>>prices[j];
        v[j - 1] = {num[j], prices[j], 1.0 * prices[j] / num[j]};
    }
    sort(v.begin(), v.end(), cmp);
    double cnt = 0.0;
    double res = 0.0;
    for(int i = 0; i < v.size(); i++) {
        if(cnt + v[i].num <= sum) {
        	res += v[i].prices;
        	cnt += v[i].num;
		}
        else {
            res += v[i].prices * (sum - cnt) / v[i].num;
            break;
        }
    }
    printf("%.2f", res);
    
    return 0;
}