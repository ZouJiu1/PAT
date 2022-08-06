#include<iostream>
#include<vector>
#include<map>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int i, j, k, m, n, h, mm, nn;
    map<int, int> mp;
    cin>>m>>n;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cin>>h;
            mp[h] += 1;
        }
    }
    mm = -999999;
    for(map<int, int>::iterator it = mp.begin(); it!=mp.end(); it++){
        if(mm < it->second){
            nn = it->first;
            mm = it->second;
        }
    }
    cout<<nn;
    return 0;
}
