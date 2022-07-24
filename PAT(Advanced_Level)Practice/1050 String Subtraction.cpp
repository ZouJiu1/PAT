#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int i, j, k;
    string s, s0, res;
    getline(cin, s);
    getline(cin, s0);
    map<char, int> mp;
    for(i = 0; i<s0.length(); i++){
        mp[s0[i]] = 9;
    }
    for(i = 0; i < s.length(); i++){
        if(mp[s[i]]+0==0)
            res += s[i];
    }
    cout<<res;
    return 0;
}
