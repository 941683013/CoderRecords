#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    string orderlyQueue(string s, int k) {
        
        if(k == 1) {
            string res = s;
            for(int i = 0; i < s.size(); i++) {
                string t = s.substr(i) + s.substr(0, i);
                res = min(t, res);
            }
            return res;
        }
        else {
            sort(s.begin(), s.end());
            return s;
        }

    }
};