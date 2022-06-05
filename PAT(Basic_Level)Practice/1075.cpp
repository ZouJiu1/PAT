#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

struct linked{
    string adr;
    int val;
    string nex;
};

int main(void){
    string s0,s3,s6;
    int n, m, i, j, num;
    cin>>s0>>n>>m;
    s6=s0;
    vector<linked> vec;
    map<string, linked> mp;
    for(i = 0; i < n; i++){
        linked lkd;
        cin>>lkd.adr>>lkd.val>>lkd.nex;
        mp[lkd.adr] = lkd;
    }
    vector<linked> vec3;
    linked lkd;
    for(i=0; i<n; i++){
        lkd = mp[s0];
        if(lkd.val<0) vec3.push_back(lkd);
        s0 = lkd.nex;
    }
    s0 = s6;
    for(i=0; i<n; i++){
        lkd = mp[s0];
        if(lkd.val<=m&&lkd.val>=0) vec3.push_back(lkd);
        s0 = lkd.nex;
    }
    s0 = s6;
    for(i=0; i<n; i++){
        lkd = mp[s0];
        if(lkd.val>m) vec3.push_back(lkd);
        s0 = lkd.nex;
    }
    for(i=0; i<n; i++){
        cout<<vec3[i].adr<<" "<<vec3[i].val<<" ";
        if(i==(n-1)) cout<<-1;
        else cout<<vec3[i+1].adr<<endl;
    }
    return 0;
}
