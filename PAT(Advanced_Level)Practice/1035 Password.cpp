#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;

typedef struct _account{
    string s;
    string s0;
}account;

int main(void){
    int i, j, k, m, n;
    cin>>m;
    vector<account> v, v0;
    account acc;
    for(i = 0; i < m; i++){
        cin>>acc.s>>acc.s0;
        v.push_back(acc);
    }

    for(i = 0; i < m; i++){
        string s, s0;
        s0 = v[i].s0;
        k = 999;
        for(j = 0; j < s0.length(); j++){
            if(s0[j]=='l'){
                s += 'L';
                k = -999;
            }
            else if(s0[j]=='O'){
                s += 'o';
                k = -999;
            }
            else if(s0[j]=='0'){
                s += '%';
                k = -999;
            }
            else if(s0[j]=='1'){
                s += '@';
                k = -999;
            }
            else
                s += s0[j];
        }
        if(k < 0){
            acc.s = v[i].s;
            acc.s0 = s;
            v0.push_back(acc);
        }
    }
    if(v0.size()==0&&m==1){
        printf("There is 1 account and no account is modified");
        return 0;
    }
    if(v0.size()==0){
        printf("There are %d accounts and no account is modified", m);
        return 0;
    }
    cout<<v0.size()<<endl;
    for(i = 0; i < v0.size(); i++){
        cout<<v0[i].s<<" "<<v0[i].s0<<endl;
    }
    return 0;
}
