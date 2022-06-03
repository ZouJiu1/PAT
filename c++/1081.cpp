#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int alp, num, m, n, i, j, lua;
    set<char> st, st0;
    for(char c = 'a'; c <= 'z'; c++) st.insert(c);
    for(char c = 'A'; c <= 'Z'; c++) st.insert(c);
    for(char c = '0'; c <= '9'; c++) st0.insert(c);
    cin>>n;
    string s0;
    cin.get();
    for(i=0; i<n; i++){
        getline(cin, s0);
        if(s0.size()<6) {cout<<"Your password is tai duan le."<<endl; continue;}
        alp = -666;
        num = -666;
        lua = -666;
        for(j=0; j<s0.size(); j++){
            if(s0[j]=='.') continue;
            set<char>::iterator it = st.find(s0[j]);
            set<char>::iterator it0 = st0.find(s0[j]);
            if(it==st.end()&&it0==st0.end()&&s0[j]!='.') {
                cout<<"Your password is tai luan le."<<endl; lua=666; break;}
            if(it!=st.end()) alp = 666;
            if(it0!=st0.end()) num = 666;
        }
        if(lua>0) continue;
        if(alp>0&&num<0) {cout<<"Your password needs shu zi."<<endl;}
        else if(alp<0&&num>0) {cout<<"Your password needs zi mu."<<endl;}
        else {cout<<"Your password is wan mei."<<endl;}
    }
    return 0;
}
