#include "bits/stdc++.h"
using namespace std;

unordered_map<string, int> len;
unordered_map<string, string> f;

string find(string x) {
    if(f.find(x) == f.end()) return x;
    return f[x] = find(f[x]);
}

void add(string a, string b) {
    a = find(a);
    b = find(b);
    if(a != b) {
        f[a] = b;
    }
}


int main() {
    
    int n, k;
    cin>>n>>k;
    unordered_set<string> st;
    
    while(n--) {
        string a, b;
        int d;
        cin>>a>>b>>d;
        st.insert(a);
        st.insert(b);
        len[a] += d;
        len[b] += d;
        add(a, b);
    }
    unordered_map<string, int> num;
    unordered_map<string, int> cnt;
    for(auto x : st) {
        string head = find(x);
        num[head]++;
        cnt[head] += len[x];
    }
    vector<pair<string, int>> res;
    for(auto x : num) {
        string str = x.first;
        if(x.second <= 2) continue;
        string name;
        int mx = 0;
        int t = 0;
        if(cnt[str] >= 2 * k) {
            for(auto y : st) {
                if(find(y) == str) {
                    if(len[y] > mx) {
                        mx = len[y];
                        name = y;
                    }
                    t++;
                }
            }
            res.push_back({name, t});
        }
    }
    sort(res.begin(), res.end());
    printf("%d\n", res.size());
    for(int i = 0; i < res.size(); i++) {
        cout<<res[i].first<<" "<<res[i].second<<endl;
    }
    return 0;
}