#include "bits/stdc++.h"
using namespace std;

int main() {

    int n;
    while(cin>>n) {
        int f = false;
        for(int i = 2; i * i <= n; i++) {
            if(n % (i * i) == 0) {
                 f = true;
                 break;
            }
        }
        if(f) {
            cout<<"Yes"<<endl;
        }
        else {
            cout<<"No"<<endl;
        }
    }

    return 0;
}
