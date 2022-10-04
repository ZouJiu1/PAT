#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;

int main(void) {
    long long i, j, k, m, n;
    cin>>m;
    string t, x1, x2;
    for(i = 0; i < m; i++) {
        cin>>n;
        t = to_string(n);
        k = t.length()/2;
        x1 = t.substr(0, k);
        x2 = t.substr(k, k);
        k  = stoll(x1)*stoll(x2);
        if(k!=0 && n%k==0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
