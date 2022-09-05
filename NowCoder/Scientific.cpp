#include "bits/stdc++.h"
using namespace std;

int main() {
    
    string s;
    cin>>s;
    bool f = true;
    if(s[0] == '-') f = false;
    int d = s.find('E');
    int cnt = 0;
    for(int i = d + 2; i < s.size(); i++) {
        cnt = cnt * 10 + s[i] - '0';
    }
    if(s[d + 1] == '-') cnt = -cnt;
    string t;
    for(int i = 1; i < d; i++) {
        t.push_back(s[i]);
    }
    string res;
    if(!f) res += '-';
    if(cnt > 0) {
        for(int i = 0; i < cnt + 1 && i < t.size(); i++) {
            if(t[i] != '.') res.push_back(t[i]);
        }
        if(cnt + 2 < t.size()) {
            res.push_back('.');
            for(int i = cnt + 2; i < t.size(); i++) res.push_back(t[i]);
        }
        else {
        	for(int i = t.size(); i <= cnt + 1; i++) {
        		res.push_back('0');
			}
		}
    }
    else if(cnt < 0) {
        for(int i = 0; i < abs(cnt); i++) {
            res.push_back('0');
            if(i == 0) res.push_back('.');
        }
        for(int i = 0; i < t.size(); i++) {
        	if(t[i] != '.') res.push_back(t[i]);
		}
    }
    else {
        res.append(t);
    }
    
    cout<<res<<endl;
    
    return 0;
}