#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, m, res;
    string s0, s2;
    getline(cin, s0);
    getline(cin, s2);
    set<char> st;
    set<char>::iterator it;
    for(int i=0; i<s0.length(); i++){
        it = st.find(s0[i]);
        if(it==st.end()){
            cout<<s0[i];
        }
        st.insert(s0[i]);
    }
    for(int i=0; i<s2.length(); i++){
        it = st.find(s2[i]);
        if(it==st.end()){
            cout<<s2[i];
        }
        st.insert(s2[i]);
    }
    return 0;
}
