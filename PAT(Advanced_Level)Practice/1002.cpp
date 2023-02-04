update202302
#include<iostream>
#include<map>
using namespace std;
int N0[20], N1[20];
double a0[20], a1[20];
int main(void) {
    int i, j, k, N, M, K0, K1, y, z;
    double d0, d1;
    cin>>K0;
    map<int, double, greater<int>> mp, res;
    for(i = 0; i < K0; i++) {
        scanf("%d", &N0[i]);
        cin>>a0[i];
        mp[N0[i]] += a0[i];
    }
    cin>>K1;
    for(i = 0; i < K1; i++) {
        scanf("%d", &N1[i]);
        cin>>a1[i];
        mp[N1[i]] += a1[i];
    }
    for(auto it:mp) {
        if(it.second==0) continue;
        res[it.first] = it.second;
    }
    printf("%d", res.size());
    for(auto it:res)    printf(" %d %.1f", it.first, it.second);
    return 0;
}


old before
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
    map<int, double> mp0, mp2, sum;
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
    for(set<int>::iterator it=st.begin(); it!=st.end(); it++) {
        mp2[*it] = mp2[*it] + mp0[*it];
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
