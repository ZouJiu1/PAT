#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<bits/stdc++.h>

using namespace std;

int main(void) {
    int i, j, k, m, n;
    string s, s0;
    cin>>m;
    cin>>s;
    vector<char> v;
    set<int> st;
    for(i = 0; i < s.length(); i++) {
        if(st.find(s[i])==st.end()){
            v.push_back(s[i]);
        }
        st.insert(s[i]);
    }
    string keepit;
    for(j = 0; j < v.size(); j++){
        string s1;
        int mr = -9;
        for(k = 0; k < m; k++) s1 += v[j];
        for(i = 0; i < s.length();) {
            if(s[i]!=v[j]) {
                i++;
                continue;
            }
            s0 = s.substr(i, m);
            if(s0!=s1) {
                mr = 9;
                break;
            }else i+=m;
        }
        if(mr < 0) keepit += v[j];
    }
    map<char, int> mp;
    for(i = 0; i < keepit.length(); i++) {
        mp[keepit[i]] = 1;
    }
    string out;
    int cnt = 0;
    for(i = 0; i < s.length();) {
        out += s[i];
        if(mp[s[i]]+0==1) {
            i += m;
            cnt++;
        } else i++;
    }
    cout<<keepit<<endl<<out;
    return 0;
}
