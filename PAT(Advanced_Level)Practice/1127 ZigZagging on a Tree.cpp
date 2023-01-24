update202301
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int in[31], pot[31], cnt = 0;
vector<int> v[31], res;
struct nod {
    nod *l=NULL, *r = NULL;
    int val;
};
nod* gentree(nod *rot, int potright, int inl, int inr) {
    if(inl > inr) return NULL;
    if(rot==NULL) {
        rot = new(nod);
        rot->val = pot[potright];
    }
    int kk = inl;
    while(inl <= inr && pot[potright]!=in[kk]) kk++;
    rot->l = gentree(rot->l, potright - (inr - kk + 1), inl, kk-1);
    rot->r = gentree(rot->r, potright - 1, kk + 1, inr);
    return rot;
}
void width_firstly_search(nod *rot) {
    queue<nod*> q;
    queue<int> lev;
    nod *nd;
    q.push(rot);
    lev.push(0);
    int level;
    while(!q.empty()) {
        nd = q.front();
        level = lev.front();
        lev.pop();
        q.pop();
        if(nd->l!=NULL) {
            q.push(nd->l);
            lev.push(level + 1);
        }
        if(nd->r!=NULL) {
            q.push(nd->r);
            lev.push(level + 1);
        }
        if(level%2==1) v[level].push_back(nd->val);
        else v[level].insert(v[level].begin(), nd->val);
    }
}
int main(void) {
    int i, j, n, m, k;
    cin>>m;
    for(i = 0; i < m; i++) scanf("%d", &in[i]);
    for(i = 0; i < m; i++) scanf("%d", &pot[i]);
    nod *rot = NULL;
    rot = gentree(rot, m-1, 0, m-1);
    width_firstly_search(rot);
    for(i = 0; i < 31; i++) {
        for(j = 0; j < v[i].size(); j++) res.push_back(v[i][j]);
    }
    for(i = 0; i < res.size(); i++) {
        printf("%d", res[i]);
        if(i!=res.size() - 1) printf(" ");
    }
    return 0;
}

old before

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

update

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int m, in[31], post[31], tmple;
vector<int> lev[31], res;
struct nod{ struct nod *l=NULL, *r=NULL; int val; };
nod* recursion(nod *root, int start, int l, int r) {
    int k = l;
    if(l > r) return NULL;
    if(root==NULL) {
        root = new(nod);
        root->val = post[start];
    }
    while(in[k]!=post[start]) k++;
    root->l = recursion(root->l, start - (r - k) - 1, l, k - 1);
    root->r = recursion(root->r, start - 1, k + 1, r);
    return root;
}

void width_firstly_recursion(nod *root) {
    queue<nod *> q;
    queue<int> ll;
    q.push(root);
    ll.push(0);
    nod *tmp;
    while(q.size()!=0) {
        tmp = q.front();
        tmple = ll.front();
        lev[tmple].push_back(tmp->val);
        if(tmp->l!=NULL) {
            q.push(tmp->l);
            ll.push(tmple + 1);
        }
        if(tmp->r!=NULL) {
            q.push(tmp->r);
            ll.push(tmple + 1);
        }
        q.pop();
        ll.pop();
    }
}
int main(void) {
    int i, j, n, k;
    cin>>m;
    for(i = 0; i < m; i++) scanf("%d", &in[i]);
    for(i = 0; i < m; i++) scanf("%d", &post[i]);
    nod *root = NULL;
    root = recursion(root, m - 1, 0, m - 1);
    width_firstly_recursion(root);
    for(i = 0; i < 31; i++) if(i%2==0) reverse(lev[i].begin(), lev[i].end());
    for(i = 0; i < 31; i++) {
        for(j = 0; j < lev[i].size(); j++) res.push_back(lev[i][j]);
    }
    printf("%d", res[0]);
    for(i = 1; i < res.size(); i++) printf(" %d", res[i]);
    return 0;
}
