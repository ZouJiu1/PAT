#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;

int main(void) {
    int i, j, k, m, n;
    cin>>m>>n;
    vector<vector<int>> v;
    v.resize(n);
    int x1, x2;
    for(i = 0; i < n; i++) v[i].resize(2);
    for(i = 0; i < n; i++) {
        cin>>x1>>x2;
        v[i][0] = x1;
        v[i][1] = x2;
    }
    int ww = n;
    cin>>ww;
    vector<vector<int>> v1;
    v1.resize(ww);
    for(i = 0; i < ww; i++) {
        cin>>k;
        v1[i].resize(k);
        for(j = 0; j < k; j++) {
            cin>>x1;
            v1[i][j] = x1;
        }
     }
     for(i = 0; i < ww; i++) {
        vector<int> status(n, 0);
        int mr = -9;
        for(j = 0; j < v1[i].size(); j++) {
            for(x1 = 0; x1 < n; x1++) {
                if(v[x1][0]==v1[i][j]||v[x1][1]==v1[i][j]) status[x1] = 1;
            }
        }
        for(j = 0; j < n; j++) {
            if(status[j]==0) {
                mr = 9;
                break;
            }
        }
        if(mr > 0) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
     }
    return 0;
}
