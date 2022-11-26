old before

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

update

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct nod{string kk; int l, r;};
bool bl[21];
nod arr[21];
string recursion(int rot) {
    if(rot==-1) return "";
    if(arr[rot].l * arr[rot].r > 0) 
        return "(" + recursion(arr[rot].l) + recursion(arr[rot].r) + arr[rot].kk + ")";
    else
        return "(" + recursion(arr[rot].l) + arr[rot].kk + recursion(arr[rot].r) + ")";
}
void recursion_version(int rot) {
    if(rot==-1) return;
    printf("(");
    recursion_version(arr[rot].l);
    if(arr[rot].l * arr[rot].r > 0) {
        recursion_version(arr[rot].r);
        cout<<arr[rot].kk;
    } else {
        cout<<arr[rot].kk;
        recursion_version(arr[rot].r);
    }
    printf(")");
}
int main(int argc, char **argv) {
    int i, j, k, m, n, y, z, rot = 1;
    string t;
    cin>>m;
    nod nd;
    fill(bl, bl+21, false);
    for(i = 1; i <= m; i++) {
        cin>>nd.kk>>nd.l>>nd.r;
        arr[i] = nd;
        bl[nd.l] = true;
        bl[nd.r] = true;
    }
    while(bl[rot]==true) rot++;
    // t = recursion(rot);
    // cout<<t<<endl;
    recursion_version(rot);
    return EXIT_SUCCESS;
}
