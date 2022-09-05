#include "bits/stdc++.h"
#define P pair<char, int>
using namespace std;

int main() {
    
    int r1, r2, n;
    cin>>r1>>r2>>n;
    unordered_map<int, P> mp;
    for(int i = 1; i <= n; i++) {
        int cur, next;
        char ch;
        cin>>cur>>ch>>next;
        mp[cur] = {ch, next};
    }
    vector<int> v1(1, r1), v2(1, r2);
    while(r1 != -1) {
        r1 = mp[r1].second;
        v1.push_back(r1);
    }
    while(r2 != -1) {
        r2 = mp[r2].second;
        v2.push_back(r2);
    }
    int res = 0;
    for(int i = v1.size() - 1, j = v2.size() - 1; i >= 0 && j >= 0; i--, j--) {
        if(v1[i] == v2[j]) res = v1[i];
        else {
            break;
        }
    }
    printf("%05d", res);
    
    return 0;
}