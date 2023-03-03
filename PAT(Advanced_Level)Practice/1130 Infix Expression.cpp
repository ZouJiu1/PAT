update202303
#include<iostream>
#include<string>
using namespace std;
struct nod {
    string t;
    int l, r;
};

nod arr[26];
int tat[26], y = 1;
string recursion(int kk) {
    if(arr[kk].l==-1 && arr[kk].r==-1) return arr[kk].t;
    string ti = "";
    if(arr[kk].l!=-1) ti += recursion(arr[kk].l);
    ti += arr[kk].t;
    if(arr[kk].r!=-1) ti += recursion(arr[kk].r);
    return ti = "(" + ti + ")";
    // if(arr[kk].l==-1 && arr[kk].r==-1) return arr[kk].t;
    // if(arr[kk].l==-1 && arr[kk].r!=-1) return "(" + arr[kk].t + recursion(arr[kk].r) + ")";
    // if(arr[kk].l!=-1 && arr[kk].r!=-1) return "(" +recursion(arr[kk].l)+ arr[kk].t + recursion(arr[kk].r) + ")";
}
int main(void) {
    int i, j, k, n, m, N, M, K, x, z;
    string t0, t1, t2;
    cin>>N;
    for(i = 1; i <= N; i++) {
        cin>>arr[i].t>>arr[i].l>>arr[i].r;
        if(arr[i].l > 0) tat[arr[i].l] = 1;
        if(arr[i].r > 0) tat[arr[i].r] = 1;
    }
    while(tat[y]==1) y++;
    t1 = recursion(y);
    if(t1[0]=='(') t1 = t1.substr(1, t1.length() - 2);
    cout<<t1<<endl;
    return 0;
}

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
