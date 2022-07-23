#include<iostream>
#include<vector>
#include<map>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    string s, s0, sub, sk;
    int i, j, k, m, n;
    cin>>m;
    vector<int> v;
    map<int, int> mp;
    for(i = 0; i < m; i++){
        cin>>n;
        v.push_back(n);
        mp[n] += 1;
    }
    j = -999;
    for(i = 0; i < m; i++){
        if(mp[v[i]]==1){
            cout<<v[i];
            j = 999;
            return 0;
        }
    }
    cout<<"None";
    return 0;
}
