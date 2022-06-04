#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, m, res, i, j;
    cin>>n;
    set<string> st0, st9;
    string tr0, tr6, tr9;
    vector<string> vt0, vt9;
    for(i = 0; i < n; i++){
        cin>>tr0;
        st0.insert(tr0);
        // vt0.push_back(tr0);
    }
    cin>>m;
    for(i = 0; i < m; i++){
        cin>>tr0;
        st9.insert(tr0);
        vt9.push_back(tr0);
    }
    set<string>::iterator it;
    int min0 = 666666666, min9 = 999999999, tmp, counts=0;
    for(i = 0; i < m; i++){
        it = st0.find(vt9[i]);
        tr0 = vt9[i].substr(6, 8);
        tmp = stoi(tr0);
        if(it != st0.end()){
            if(tmp<min9){
                min9 = tmp;
                tr9 = vt9[i];
            }
            counts++;
        }else{
            if(tmp<min0){
                min0 = tmp;
                tr6 = vt9[i];
            }
        }
    }
    cout<<counts<<endl;
    if(counts==0) cout<<tr6;
    else cout<<tr9;
    return 0;
}
