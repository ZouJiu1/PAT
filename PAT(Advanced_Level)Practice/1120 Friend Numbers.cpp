#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void) {
    int i, j, k, m, n;
    string t;
    cin>>n;
    vector<int> v;
    set<int> st;
    for(i = 0; i < n; i++) {
        cin>>t;
        k = 0;
        for(j = 0; j < t.length(); j++) 
            k += t[j] - '0';
        st.insert(k);
    }
    for(set<int>::iterator it=st.begin(); it!=st.end(); it++) 
        v.push_back(*it);
    sort(v.begin(), v.end());
    cout<<v.size()<<endl;
    for(i = 0; i < v.size(); i++) {
        cout<<v[i];
        if(i!=v.size() - 1) cout<<" ";
    }
    return 0;
}
