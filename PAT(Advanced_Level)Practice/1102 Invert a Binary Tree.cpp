update202301
//map层序遍历自动排序，ind保存index的最大值 
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;
string arr[20][2], t0, t1;
map<int, int> lev;
int inord[20], status[20], innum = 0, ind;
void inorder(string rot, int index) {
    if(rot=="-") return;
    int kk = stoi(rot);
    lev[index] = kk;
    ind = index;
    inorder(arr[kk][0], index * 2 + 1);
    inord[innum++] = kk;
    inorder(arr[kk][1], index * 2 + 2);
}
int main(void){
    int i, j, k, m, n, N, M, rot=0;
    cin>>N;
    for(i = 0; i < N; i++) {
        cin>>t0>>t1;
        arr[i][0] = t1;
        arr[i][1] = t0;
        if(t1!="-") status[stoi(t1)] = 1;
        if(t0!="-") status[stoi(t0)] = 1;
    }
    while(status[rot]!=0) rot++;
    inorder(to_string(rot), 0);
    for(auto it:lev) printf("%d%s", it.second, it.first==ind? "\n":" ");
    for(i = 0; i < innum; i++) {
        printf("%d", inord[i]);
        if(i!=innum-1) printf(" ");
    }
}

update
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
struct nod{string l, r;};
nod ar[11];
vector<int> in, le;
void recursion(int start) {
    if(ar[start].l!="-") recursion(stoi(ar[start].l));
    in.push_back(start);
    if(ar[start].r!="-") recursion(stoi(ar[start].r));
}
void level(int start) {
    queue<int> q;
    q.push(start);
    int i, j;
    while(!q.empty()){
        i = q.front();
        le.push_back(i);
        if(ar[i].l!="-") q.push(stoi(ar[i].l));
        if(ar[i].r!="-") q.push(stoi(ar[i].r));
        q.pop();
    }
}
void printvec(vector<int> v){
    printf("%d", v[0]);
    for(int i = 1; i < v.size(); i++) printf(" %d", v[i]);
    printf("\n");
}
int main(int argc, char **argv) {
    int m, n, i, j, k = 0;
    nod nd;
    cin>>m;
    bool exist[11];
    fill(exist, exist+11, false);
    for(i = 0; i < m; i++) {
        cin>>nd.r>>nd.l;
        ar[i] = nd;
        if(nd.r!="-") exist[stoi(nd.r)] = true;
        if(nd.l!="-") exist[stoi(nd.l)] = true;
    }
    while(exist[k]!=false) k++;
    recursion(k);
    level(k);
    printvec(le);
    printvec(in);
    return 0;
}

old before
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
