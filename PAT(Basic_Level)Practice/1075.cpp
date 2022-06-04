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
    int address[100001];
    for(i = 0; i < n; i++){
        linked lkd;
        cin>>lkd.adr>>lkd.val>>lkd.nex;
        vec.push_back(lkd);
        address[stoi(lkd.adr)] = i;
    }
    vector<linked> vec3;
    for(i=0; i<n; i++){
        j = address[stoi(s0)];
        if(vec[j].val<0){
            vec3.push_back(vec[j]);
        }
        s0 = vec[j].nex;
    }
    s0 = s6;
    for(i=0; i<n; i++){
        j = address[stoi(s0)];
        if(vec[j].val<=m&&vec[j].val>=0){
            vec3.push_back(vec[j]);
        }
        s0 = vec[j].nex;
    }
    s0 = s6;
    for(i=0; i<n; i++){
        j = address[stoi(s0)];
        if(vec[j].val>m){
            vec3.push_back(vec[j]);
        }
        s0 = vec[j].nex;
    }
    for(i=0; i<n; i++){
        cout<<vec3[i].adr<<" "<<vec3[i].val<<" ";
        if(i==(n-1)) cout<<-1;
        else cout<<vec3[i+1].adr<<endl;
    }
    return 0;
}
