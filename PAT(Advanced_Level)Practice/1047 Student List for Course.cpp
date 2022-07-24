#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<bits/stdc++.h>

using namespace std;

bool cmp1(string &a, string &b) {
    return a < b;
}

int main(void){
    int i, j, k, m, n, h, mm, nn;
    vector<string> v, v0;
    vector<vector<string>> mp;
    cin>>m>>n;
    mp.resize(n);
    string s;
    for(i = 0; i < n; i++) mp[i] = v;
    for(i = 0; i < m; i++){
        cin>>s>>mm;
        for(j = 0; j < mm; j++){
            cin>>k;
            mp[k - 1].push_back(s);
        }
    }
    for(i = 0; i < n; i++){
        sort(mp[i].begin(), mp[i].end(), cmp1);
        cout<<i+1<<" "<<mp[i].size()<<endl;
        for(j = 0; j < mp[i].size(); j++){
            cout<<mp[i][j]<<endl;
        }
    }
    return 0;
}
