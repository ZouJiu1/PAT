#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, m, i, j, k;
    string s0, s2, s3, s6="000000", s9="999999", ss0, ss2;
    cin>>n;
    for(i = 0; i < n; i++){
        cin>>s0>>s2>>s3;
        s2.erase(s2.begin()+2);
        s2.erase(s2.begin()+4);
        s3.erase(s3.begin()+2);
        s3.erase(s3.begin()+4);
        if(s2<s9){
            s9 = s2;
            ss0 = s0;
        }
        if(s3>s6){
            s6 = s3;
            ss2 = s0;
        }
    }
    cout<<ss0<<" "<<ss2;
    return 0;
}
