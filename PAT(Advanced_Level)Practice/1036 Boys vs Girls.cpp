#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int i, j, k, m, n, minmin=999999, maxmax=-999999, FC, MC;
    cin>>m;
    char G;
    string s, s0, s00, s3, FS, FS0, MS, MS0;
    for(i = 0; i < m; i++){
        cin>>s>>G>>s0>>n;
        if(G=='M' && n < minmin){
            MS = s;
            MS0 = s0;
            minmin = MC = n;
        }
        if(G=='F' && n > maxmax){
            FS = s;
            FS0 = s0;
            maxmax = FC = n;
        }
    }
    if(maxmax < 0) cout<<"Absent"<<endl;
    else cout<<FS<<" "<<FS0<<endl;
    if(minmin > 101) cout<<"Absent"<<endl;
    else cout<<MS<<" "<<MS0<<endl;
    if(maxmax < 0 || minmin > 101) {
        cout<<"NA"<<endl;
        return 0;
    }
    cout<<(FC - MC)<<endl;

    return 0;
}
