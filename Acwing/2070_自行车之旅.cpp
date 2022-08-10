#include "bits/stdc++.h"

using namespace std;

int main() {

    int t;
    cin>>t;

    for(int Case = 1; Case <= t; Case++) {

        int n;
        cin>>n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin>>v[i];

        int res = 0;
        for(int i = 1; i < n - 1; i++) {
            if(v[i] > v[i - 1] && v[i] > v[i + 1]) {
                res++;
            }
        }
        printf("Case #%d: %d\n", Case, res);

    }

    return 0;
}