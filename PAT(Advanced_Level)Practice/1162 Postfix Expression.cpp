#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
struct nod {string tk; int l, r;};
vector<nod> v;
string dfs(int root, string tj){
    if(root==-1) return "";
    if(v[root].l*v[root].r >= 1)
        return "("+dfs(v[root].l, tj) + dfs(v[root].r, tj) + v[root].tk+")";
    else
        return "("+dfs(v[root].l, tj) + v[root].tk + dfs(v[root].r, tj)+")";
}
int main(void) {
    int i, j, k, m, n, x1, x2, root = 1;
    unordered_map<int, int> mp;
    cin>>m;
    nod nd;
    string t, tj;
    v.resize(m + 1);
    for(i = 1; i <= m; i++) {
        cin>>nd.tk>>nd.l>>nd.r;
        mp[nd.l] = mp[nd.r] = 9;
        v[i] = nd;
    }
    while(mp[root]+0!=0) root++;
    tj = dfs(root, "");
    cout<<tj<<endl;
    return 0;
}
