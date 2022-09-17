#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;
vector<vector<int>> nodes;
vector<int> in;

void inmiddle_traverse(int root) {
    if(nodes[root][0] >= 0)
        inmiddle_traverse(nodes[root][0]);
    in.push_back(root);
    if(nodes[root][1] >= 0)
        inmiddle_traverse(nodes[root][1]);
}

int main(void) {
    int i, j, k, m, n;
    string s0, s1;
    cin>>m;
    vector<vector<int>> nod;
    nod.resize(m);
    for(i = 0; i < m; i++) nod[i].resize(2);
    int findroot[m];
    for(i = 0; i < m; i++) findroot[i] = -999;
    for(i = 0; i < m; i++) {
        cin>>s0>>s1;
        if(s0[0]=='-') nod[i][1] = -9;
        else {
            k = stoi(s0);
            nod[i][1] = k;
            findroot[k] = 9;
        }
        if(s1[0]=='-') nod[i][0] = -9;
        else {
            k = stoi(s1);
            nod[i][0] = k;
            findroot[k] = 9;
        }
    }
    int rt;
    for(i = 0; i < m; i++) {
        if(findroot[i] < 0) {
            rt = i;
            break;
        }
    }
    vector<vector<int>> vec;
    vector<int> res, vtr;
    res.push_back(rt);
    vec.push_back(nod[rt]);
    while(vec.size() > 0) {
        vtr = vec[0];
        vec.erase(vec.begin(), vec.begin() + 1);
        if(vtr[0] >= 0) {
            res.push_back(vtr[0]);
            vec.push_back(nod[vtr[0]]);
        } 
        if(vtr[1] >= 0) {
            res.push_back(vtr[1]);
            vec.push_back(nod[vtr[1]]);
        }
    }
    for(i = 0; i < res.size(); i++) {
        cout<<res[i];
        if(i!=res.size() - 1) cout<<" ";
    }
    cout<<endl;
    nodes = nod;
    inmiddle_traverse(rt);
    for(i = 0; i < in.size(); i++) {
        cout<<in[i];
        if(i!=in.size() - 1) cout<<" ";
    }
    return 0;
}
