#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<string>
using namespace std;
struct nodes{
    string s;
    int num;
};
bool compare(const nodes&a, const nodes&c){
    if(a.s < c.s) return true;
    else return false;
}
int main(void){
    int i, j, m, n, k;
    string s0, s1, s;
    vector<nodes> v;
    nodes nd;
    map<string, int> mp;
    getline(cin, s);
    k = -999999;
    for(i = 0; i < s.length(); i++){
        if(isdigit(s[i])||isalpha(s[i])) s0 += tolower(s[i]);
        else if(s0.length()>0){
            mp[s0] += 1;
            if(mp[s0] > k) k = mp[s0];
            s0.clear();
        }
    }
    if(s0.length() > 0){
        mp[s0] += 1;
        if(mp[s0] > k) k = mp[s0];
    }
    for(map<string, int>::iterator it=mp.begin(); it!=mp.end(); it++){
        if(it->second==k){
            nd.s = it->first;
            nd.num = it->second;
            v.push_back(nd);
        }
    }
    sort(v.begin(), v.end(), compare);
    cout<<v[0].s<<" "<<v[0].num;
    return 0;
}
