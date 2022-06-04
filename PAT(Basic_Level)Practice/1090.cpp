#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, m, i, j, k, res, kk;
    cin>>n>>m;
    map<string, vector<string>> mp0, mp2;
    string s0, s2, s3, s6;
    vector<string> vec[101], vec0, vec2, tmp;
    set<string> st[101], setall, set0, set2;
    for(i = 0; i < n; i++){
        cin>>s0>>s2;
        mp0[s0] = tmp;
        mp2[s2] = tmp;
        vec0.push_back(s0);
        vec2.push_back(s2);
        setall.insert(s0);
        setall.insert(s2);
        set0.insert(s0);
        set2.insert(s2);
    }
    for(i = 0; i < n; i++){
        mp0[vec0[i]].push_back(vec2[i]);
        mp2[vec2[i]].push_back(vec0[i]);
    }
    for(i = 0; i < m; i++){
        cin>>k;
        for(j = 0; j < k; j++){
            cin>>s0;
            vec[i].push_back(s0);
            st[i].insert(s0);
        }
    }
    set<string>::iterator it, it0;
    for(i = 0; i < m; i++){
        kk = -666;
        for(j = 0; j < vec[i].size(); j++){
            s0 = vec[i][j];
            it = setall.find(s0);
            if(it==setall.end()) continue;
            it = set0.find(s0);
            it0 = set2.find(s0);
            if(it==set0.end()&&it0!=set2.end()) tmp = mp2[s0];
            else if(it!=set0.end()&&it0==set2.end()) tmp = mp0[s0];
            else if(it!=set0.end()&&it0!=set2.end()) {
                tmp = mp0[s0];
                for(k = 0; k < mp2[s0].size(); k++) tmp.push_back(mp2[s0][k]);
            }

            it = st[i].find(s0);
            for(k = 0; k < tmp.size(); k++){
                s2 = tmp[k];
                it0 = st[i].find(s2);
                if(it!=st[i].end()&&it0!=st[i].end()){
                    cout<<"No"<<endl;
                    kk = 666;
                    break;
                }
            }
            if(kk>0) break;
        }
        if(kk>0) continue;
        else{
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}
