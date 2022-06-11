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
    set<int> st, st0, st2;
    map<int, double> mp0, mp2, sum;
    for(int i=0; i<n0; i++){
        cin>>n2>>d0;
        mp0[n2] = d0;
        st.insert(n2);
        st0.insert(n2);
    }
    cin>>n0;
    for(int i=0; i<n0; i++){
        cin>>n2>>d0;
        mp2[n2] = d0;
        st.insert(n2);
        st2.insert(n2);
    }
    set<int>::iterator itt, tti;
    for(set<int>::iterator it=st.begin(); it!=st.end(); it++) {
        itt = st0.find(*it);
        tti = st2.find(*it);
        if(itt!=st0.end() && tti != st2.end()) mp2[*it] = mp2[*it] + mp0[*it];
        else if(itt!=st0.end() && tti ==st2.end()) mp2[*it] = mp0[*it];
    }
    vector<samplex> vec;
    for(set<int>::iterator it=st.begin(); it!=st.end(); it++){
        samplex spl;
        spl.i0 = *it;
        spl.d0 = mp2[*it];
        if(spl.d0==0) continue;
        vec.push_back(spl);
    }
    
    sort(vec.begin(), vec.end(), compare_reverse);
    cout<<vec.size();
    for(int i = 0; i < vec.size(); i++) printf(" %d %.1f", vec[i].i0, vec[i].d0);
    return 0;
}
