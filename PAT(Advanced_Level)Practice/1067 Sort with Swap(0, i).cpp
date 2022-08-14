#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;


int main(void){
    int m, n, i, j, x, y;
    cin>>m;
    vector<int> v, v0;
    map<int, int> mp;
    y = 0;
    for(i = 0; i < m; i++){
        cin>>n;
        v.push_back(n);
        mp[n] = i;
        if(n==0) x = i;
    }
    v0 = v;
    int cnt = 0;
    for(i = 0; i < m; i++){
        if(v0[i]!=i){
            while(v0[0]!=0){
                y = mp[0];
                v0[y] = y;
                x = mp[mp[0]];
                v0[x] = 0;
                mp[y] = y;
                mp[0] = x;
                cnt++;
            }
        }
        if(v0[i]!=i){
            v0[0] = v0[i];
            mp[v0[i]] = 0;
            v0[i] = 0;
            mp[0] = i;
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
