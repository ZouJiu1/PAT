#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

struct samplex{
    int i0;
    double d0;
};

bool compare_reverse(const samplex &a, const samplex &b){
    return a.i0>b.i0;
}

int main(void){
    int n0, n2, n3, a, b, c;
    string s0, s9;
    double d0, d2, d3;
    cin>>n0;
    set<int> st;
    map<int, double> mp0, mp2, mul;
    for(int i=0; i<n0; i++){
        cin>>n2>>d0;
        mp0[n2] = d0;
        st.insert(n2);
    }
    cin>>n0;
    for(int i=0; i<n0; i++){
        cin>>n2>>d0;
        mp2[n2] = d0;
        st.insert(n2);
    }
    set<int>::iterator itt, tti;
    vector<int> vec;
    for(set<int>::iterator it=st.begin(); it!=st.end(); it++) vec.push_back(*it);
    for(int i = 0; i < vec.size(); i++){
        for(int j = 0; j < vec.size(); j++){
            a = vec[i] + vec[j];
            d0 = mp2[vec[i]]*mp0[vec[j]];
            mul[a] = d0 + mul[a];
        }
    }
    vector<samplex> ver;
    for(map<int, double>::iterator it = mul.begin(); it!=mul.end(); it++){
        samplex spl;
        spl.i0 = it->first;
        spl.d0 = it->second;
        if(spl.d0==0) continue;
        ver.push_back(spl);
    }
    
    sort(ver.begin(), ver.end(), compare_reverse);
    cout<<ver.size();
    for(int i = 0; i < ver.size(); i++) printf(" %d %.1f", ver[i].i0, ver[i].d0);
    return 0;
}
