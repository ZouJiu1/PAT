#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int i, j, n, m, alp, num;
    string s0, s2, s3;
    cin>>s0>>m;
    for(i=0; i<(m-1); i++){
        alp = 1;
        for(j=0; j<s0.size(); j++){
            if((j+1)<s0.size()&&s0[j]==s0[j+1]){
                alp++;
            }else if((j+1)<s0.size()&&s0[j]!=s0[j+1]){
                s2 += s0[j];
                s2 += to_string(alp);
                alp = 1;
            }else{
                s2 += s0[j];
                s2 += to_string(alp);
                alp = 1;
            }
        }
        s0 = s2;
        s2.erase(s2.begin(), s2.end());
    }
    cout<<s0<<endl;
    return 0;
}
