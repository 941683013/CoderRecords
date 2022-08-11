#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    string reformat(string s) {
        string num;
        string alp;
        for(int i = 0; i < s.size(); i++) {
            if(isalpha(s[i])) alp += s[i];
            else num += s[i];
        }
        string res;
        if(abs((int)(num.size() - alp.size())) > 1) return res;
        int i = 0, j = 0;
        if(num.size() < alp.size()) swap(num, alp);
        while(i < num.size() || j < alp.size()) {
            if(i < num.size()) {
                res += num[i++];
            }
            else {
                break;
            }
            if(j < alp.size()) {
                res += alp[j++];
            }
            else {
                break;
            }
        }

        return res;
    }
};