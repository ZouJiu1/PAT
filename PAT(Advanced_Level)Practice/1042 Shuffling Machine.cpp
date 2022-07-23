#include<iostream>
#include<vector>
#include<map>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    string s, s0, sub, sk;
    int i, j, k, m, n;
    cin>>m;
    vector<int> v;
    vector<string> ori{"S1", "S2", "S3", "S4", "S5", "S6", "S7", 
                    "S8", "S9", "S10", "S11", "S12", "S13",
                    "H1", "H2", "H3", "H4", "H5", "H6", "H7", 
                    "H8", "H9", "H10", "H11", "H12", "H13",
                    "C1", "C2", "C3", "C4", "C5", "C6", "C7", 
                    "C8", "C9", "C10", "C11", "C12", "C13",
                    "D1", "D2", "D3", "D4", "D5", "D6", "D7", 
                    "D8", "D9", "D10", "D11", "D12", 
                    "D13", "J1", "J2"
                  };
    for(i = 0; i < 54; i++){
        cin>>n;
        v.push_back(n);
    }
    vector<string> vs[54], vst[54];
    for(i = 0; i < m; i++){
        for(j = 0; j < 54; j++){
            vs[v[j] - 1].push_back(ori[j]);
        }
        if(i==m-1){
            for(j = 0; j < 54; j++){
                cout<<vs[j][0];
                if(j!=53) cout<<" ";
            }
            return 0;
        }
        for(j = 0; j < 54; j++){
            ori[j] = vs[j][0];
            vs[j].clear();
        }
    }
    return 0;
}
