#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

struct testes{
    string st;
    int a;
    int c;
};

int main(void){
    vector<testes> s0;
    int n, m;
    cin>>n;
    for(int i=0; i<n; i++){
        testes ts;
        cin>>ts.st>>ts.a>>ts.c;
        s0.push_back(ts);
    }
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>n;
        for(int j=0; j<s0.size(); j++){
            if(s0[j].a==n){
                cout<<s0[j].st<<" "<<s0[j].c<<endl;
            }
        }
    }
    return 0;
}
