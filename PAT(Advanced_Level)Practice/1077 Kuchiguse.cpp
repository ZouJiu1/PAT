#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int i, j, m, n, k, w, q, xx, xy;
    cin>>m;
    cin.get();
    string s, s0, ss;
    vector<string> v;
    q = 999999999;
    for(i = 0; i < m; i++){
        getline(cin, s);
        reverse(s.begin(), s.end());
        v.push_back(s);
        if(s.length() < q) q = s.length();
    }
    
    for(i = 0; i < q; i++){
        xx = -999;
        char cr = v[0][i];
        for(j = 1; j < m; j++){
            if(cr!=v[j][i]) {
                xx = 999;
                break;
            }
        }
        if(xx < 0)
            ss += v[0][i];
        else
            break;
    }
    if(ss.length()==0) cout<<"nai";
    else {
        reverse(ss.begin(), ss.end());
        cout<<ss;
    }
    return 0;
}
