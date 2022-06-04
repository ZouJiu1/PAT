#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    string s0, s1, s2;
    int i, j, k, a, c, G0, SS0, K0, G1, SS1, K1;
    cin>>s0>>s1;
    i = s0.find('.');
    s2 = s0.substr(0, i);
    s0 = s0.substr(i+1, s0.size() - i);
    G0 = atoi(s2.c_str());

    i = s0.find('.');
    s2 = s0.substr(0, i);
    s0 = s0.substr(i+1, s0.size() - i);
    SS0 = atoi(s2.c_str());
    K0 = atoi(s0.c_str());

    s0=s1;
    i = s0.find('.');
    s2 = s0.substr(0, i);
    s0 = s0.substr(i+1, s0.size() - i);
    G1 = atoi(s2.c_str());

    i = s0.find('.');
    s2 = s0.substr(0, i);
    s0 = s0.substr(i+1, s0.size() - i);
    SS1 = atoi(s2.c_str());
    K1 = atoi(s0.c_str());
    
    i = G0*17*29+SS0*29+K0;
    j = G1*17*29+SS1*29+K1;
    k = j - i;
    a = k%29;
    k = k/29;
    c = k%17;
    k = k/17;
    cout<<k<<"."<<abs(c)<<"."<<abs(a)<<endl;
    return 0;
}
