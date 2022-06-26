/*
数值可能越界long long，要用string保存并计算的 
*/
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

string add(string &s, string &s0){
    string st;
    int x, y, z, tmp, h = 0;
    reverse(s.begin(), s.end());
    reverse(s0.begin(), s0.end());
    for(int i=0; i<s.length(); i++){
        x = s[i] - '0';
        y = s0[i] - '0';
        z = (x + y + h)/10;
        tmp = (x + y + h)%10;
        h = z;
        st += to_string(tmp);
        if(i==(s.length() - 1) && z > 0) st += to_string(z);
    }
    reverse(st.begin(), st.end());
    return st;
}

int main(void){
    string s, s0, sk;
    long long a, c, f, i, j, k;
    cin>>s>>k;
    for(i=0; i<k; i++){
        s0 = s;
        reverse(s0.begin(), s0.end());
        if(s0==s) break;
        s = add(s, s0);
    }
    cout<<s<<endl;
    cout<<i;
    return 0;
}
