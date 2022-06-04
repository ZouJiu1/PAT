#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    string s0, s1, s2;
    int i, j;
    vector<char> st;
    cin>>s0>>s1;
    for(i=0; i<s0.size(); i++){
        if(s1.find(s0[i])==string::npos&&s2.find(toupper(s0[i]))==string::npos)
            s2 += toupper(s0[i]);
    }
    cout<<s2<<endl;
    return 0;
}
