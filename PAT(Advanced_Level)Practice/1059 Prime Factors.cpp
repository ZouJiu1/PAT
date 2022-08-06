#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;
vector<int> v;

bool isprime(long int x, long int y){
    if(x==2||x==3||x==5||x==7||x==11) {
        v.push_back(x);
        return true;
    }
    for(long int i = 2; i <= y; i++){
        if(x%i==0){
            isprime(i, sqrt(i) + 3);
            isprime(x/i, sqrt(x/i) + 3);
            return false;
        }
    }
    v.push_back(x);
    return true;
}

int main(void){
    long int i, j, x, y, cnt;
    cin>>x;
    y = sqrt(x) + 3;
    isprime(x, y);
    sort(v.begin(), v.end());
    vector<int> v0, exp;
    v0.push_back(v[0]);
    y = 1;
    cnt = 0;
    for(i = 1; i < v.size(); i++){
        if(v0[cnt]==v[i]){           
            y++;
            continue;
        }else{
            v0.push_back(v[i]);
            exp.push_back(y);
            y = 1;
            cnt++;
        }
    }
    if(exp.size()!=v0.size()) exp.push_back(y);
    cout<<x<<"=";
    for(i = 0; i<v0.size(); i++){
        cout<<v0[i];
        if(exp[i]>1){
            cout<<"^"<<exp[i];
        }
        if(i!=v0.size()-1) cout<<"*";
    }
    return 0;
}
