#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<bits/stdc++.h>

using namespace std;

struct nod{
    string t;
    int l;
    int r;
};
int rt;
//from internal to out
string dfs(int start, vector<struct nod> &v) {
    if(start==-1) return "";
    start--;
    v[start].t = dfs(v[start].l, v) + v[start].t + dfs(v[start].r, v);
    if(v[start].r!=-1 && start+1!=rt) v[start].t = "(" + v[start].t + ")";
    return v[start].t;
}

int main(void) {
    int i, j, k, m, n;
    cin>>m;
    string s;
    int x1, x2;
    struct nod nd;
    vector<struct nod> v;
    set<int> st;
    for(i = 0; i < m; i++) {
        cin>>nd.t>>nd.l>>nd.r;
        v.push_back(nd);
        st.insert(nd.l);
        st.insert(nd.r);
    }
    int start;
    for(i = 1; i <= m; i++) {
        if(st.find(i)==st.end()) {
            start = i; 
            break;
        }
    }
    rt = start;
    string tr = dfs(start, v);
    cout<<tr<<endl;
    return EXIT_SUCCESS;
}
