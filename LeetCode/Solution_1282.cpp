#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& group) {
        vector<vector<int>> vec(group.size() + 1);
        for(int i = 0; i < group.size(); i++) {
            vec[group[i]].push_back(i);
        }
        vector<vector<int>> res;
        for(int i = 1; i <= group.size(); i++) {
            int j = 0;
            while(j < vec[i].size()) {
                vector<int> v;
                int t = i;
                while(t--) {
                    v.push_back(vec[i][j++]);
                }
                res.push_back(v);
            }
        }

        return res;
    }
};