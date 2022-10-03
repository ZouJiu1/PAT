#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<bits/stdc++.h>

using namespace std;
int x, y, z;

struct nodees{
    struct nodees *left = NULL;
    struct nodees *right = NULL;
    int values = -9;
};

void gettree(nodees *nd, vector<int> v, vector<int> v0){
    if(v.size()==0||v0.size()==0) return;
    x = v[v.size()-1];
    nd->values = x;
    vector<int> left0, right0, tmp, left, right;
    tmp = v0;
    for(int i=0; i<v0.size(); i++){
        if(v0[i]==x){
            y = i;
            break;
        }
    }
    v.pop_back();
    v0.erase(v0.begin() + y, v0.end());
    left0 = v0;
    set<int> st;
    set<int>::iterator it;
    for(int i = 0; i < left0.size(); i++) st.insert(left0[i]);
    tmp.erase(tmp.begin(), tmp.begin() + y + 1);
    right0 = tmp;
    for(int i = 0; i < v.size(); i++){
        it = st.find(v[i]);
        if(it==st.end()){
            y = i;
            break;
        }
    }
    tmp = v;
    v.erase(v.begin() + y, v.end());
    left = v;
    tmp.erase(tmp.begin(), tmp.begin() + y);
    right = tmp;
    nd->left = (struct nodees *)malloc(sizeof(struct nodees));
    nd->right = (struct nodees *)malloc(sizeof(struct nodees));
    nd->left->values = -9;
    nd->right->values = -9;
    gettree(nd->left, left, left0);
    gettree(nd->right, right, right0);
}

int main(){
    int n, i, j, a, c;
    cin>>n;
    vector<int> v, v0;
    map<int, int> m, m0;
    struct nodees *nd = (struct nodees *)malloc(sizeof(struct nodees));
    for(i = 0; i < n; i++){
        cin>>a;
        v.push_back(a);
        m[a] = i;
    }
    for(i = 0; i < n; i++){
        cin>>a;
        v0.push_back(a);
        m0[a] = i;
    }
    gettree(nd, v0, v);
    queue<struct nodees*>q;
    queue<int> q_level;
    vector<vector<int>> level;
    q.push(nd);
    int lev;
    q_level.push(0);
    level.resize(100);
    while(q.size()!=0) {
        nodees *nd = q.front();
        lev = q_level.front();
        level[lev].push_back(nd->values);
        lev++;
        if(nd->left->values!=-9) {
            q.push(nd->left);
            q_level.push(lev);
        }
        if(nd->right->values!=-9) {
            q.push(nd->right);
            q_level.push(lev);
        }
        q.pop();
        q_level.pop();
    }
    vector<int> res;
    for(i = 0; i < 100; i++) {
        if(level.size()==0) continue;
        if(i%2==0) reverse(level[i].begin(), level[i].end());
        for(j = 0; j < level[i].size(); j++) {
            res.push_back(level[i][j]);
        }
    }
    for(i = 0; i < res.size(); i++) {
        cout<<res[i];
        if(i!=res.size()-1) cout<<" ";
    }
    return 0;
}
