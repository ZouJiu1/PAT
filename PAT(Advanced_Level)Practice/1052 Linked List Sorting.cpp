#include<iostream>
#include<vector>
#include<map>
#include<bits/stdc++.h>

using namespace std;
typedef struct {
    string address;
    string nextes;
    int val;
} linked;

bool compare(const linked& lhs, const linked& rhs){
    if(lhs.val <= rhs.val) return true;
    else return false;
}

int main(void){
    int i, j, k, m, n, h, mm, nn;
    string s;
    cin>>m>>s;
    linked lkd;
    vector<linked> v, v0;
    map<string, int> mp;
    h = -9999999;
    for(i = 0; i < m; i++){
        cin>>lkd.address>>lkd.val>>lkd.nextes;
        if(lkd.address==s) h = i;
        mp[lkd.address] = i;
        v.push_back(lkd);
    }
    if(h < 0){
        cout<<"0 -1"<<endl;
        return 0;
    }
    lkd = v[h];
    v0.push_back(lkd);
    string con = "-1";
    while(lkd.nextes!=con){
        lkd = v[mp[lkd.nextes]];
        v0.push_back(lkd);
    }
    v=v0;
    sort(v.begin(), v.end(), compare);
    cout<<v.size()<<" "<<v[0].address<<endl;
    for(i=0; i<v.size()-1; i++){
        cout<<v[i].address<<" "<<v[i].val<<" "<<v[i+1].address<<endl;
    }
    cout<<v[v.size()-1].address<<" "<<v[v.size()-1].val<<" "<<"-1";
    return 0;
}
