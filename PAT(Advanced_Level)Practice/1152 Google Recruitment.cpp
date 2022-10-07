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
    cin>>n>>m;
    string s0, s2, s3, s6, s9;
    cin>>s0;
    long long l0, l6;
    for(int i=0; i<(s0.length()-m+1); i++){
        s9 = s0.substr(i, m);
        l0 = (long long)stoll(s9);
        if(l0==1) continue;
        l6 = sqrt(l0) + 10;
        res = -666;
        for(int j=2; j<l6; j++){
            if(l0%j==0){
                res = 666;
                break;
            }
        }
        if(l0==2||l0==3||l0==5){res=-666;};
        if(res<0){
            cout<<s9;
            return 0;
        }
    }
    cout<<"404";
    return 0;
}
