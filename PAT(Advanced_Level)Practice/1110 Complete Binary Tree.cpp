/*
5
- -
- -
- -
0 1
2 3



6
- -
- -
- 5
0 1
2 3
- -


4
- -
- -
- 0
1 2


6
- -
0 4
- 5
1 2
- -
- -

*/
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<bits/stdc++.h>

using namespace std;

int main(void) {
    int i, j, k, m, n, x, y;
    cin>>m;
    vector<vector<int>> v;
    v.resize(m);
    string s, s0;
    set<int> st;
    bool status[m];
    memset((void *)status, false, sizeof(bool) * m);
    for(i = 0; i < m; i++) v[i].resize(2);
    for(i = 0; i < m; i++) {
        cin>>s>>s0;
        if(s[0]!='-') {
            v[i][0] = stoi(s);
            status[stoi(s)] = true;
        }
        else v[i][0] = -9;
        if(s0[0]!='-') {
            v[i][1] = stoi(s0);
            status[stoi(s0)] = true;
        }
        else v[i][1] = -9;
    }
    int root;
    for(i = 0; i < m; i++) {
        if(status[i]==false) {
            root = i;
            break;
        }
    }
    queue<int> q, layer;
    vector<int> alllayer, parent, ele;
    q.push(root);
    layer.push(1);
    alllayer.push_back(1);
    parent.push_back(0);
    int cnt = 0, add, l, r = -9;
    while(q.size() > 0) {
        k = q.front();
        l = layer.front();
        ele.push_back(k);
        add = -9;
        if(v[k][0] >= 0) {
            q.push(v[k][0]);
            if(add < 0) {
                cnt++;
                add = 9;
            }
            layer.push(l + 1);
            alllayer.push_back(l + 1);
            parent.push_back(k);
        }
        if(v[k][1] >= 0) {
            q.push(v[k][1]);
            if(add < 0) {
                cnt++;
            }
            layer.push(l + 1);
            alllayer.push_back(l + 1);
            parent.push_back(k);
        }
        q.pop();
        layer.pop();
    }
    vector<int> vt;
    vt.push_back(0);
    for(i = 1; i < ele.size(); i++) {
        vt.push_back(ele[(i-1)/2]);
    }
    int lastlayer = 0; 
    for(i = 0; i < alllayer.size(); i++) {
        if(alllayer[i]==l) lastlayer++;
    }
    int las = parent[parent.size() - 1];
    if(las<0) las = 0;
    if(v[las][1] >= 0 && v[las][0] < 0) vt.clear();
    int all = (int)(pow(2, l-1)) + lastlayer - 1;
    if(all==m && vt==parent) cout<<"YES "<<k;
    else cout<<"NO "<<root;
    return 0;
}
