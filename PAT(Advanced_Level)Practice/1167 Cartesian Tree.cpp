#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>
using namespace std;
vector<int> v;
unordered_map<int, int> mp;
struct nod{nod *l=NULL, *r=NULL; int val;};
nod* generate(nod *root, int val) {
    int ind = mp[val];
    if(root==NULL){
        root = new(nod);
        root->val = val;
    }else if(ind < mp[root->val])
        root->l = generate(root->l, val);
    else if(ind > mp[root->val])
        root->r = generate(root->r, val);
    return root;
}
int main(void) {
    int i, j, k, m, n;
    cin>>m;
    for(i = 0; i < m; i++) {
        cin>>n;
        v.push_back(n);
        mp[n] = i;
    }
    sort(v.begin(), v.end());
    nod *nd, *root = NULL;
    for(i = 0; i < v.size(); i++)
        root = generate(root, v[i]);
    queue<nod *>q;
    q.push(root);
    while(q.size() > 0) {
        nd = q.front();
        if(nd->l!=NULL) q.push(nd->l);
        if(nd->r!=NULL) q.push(nd->r);
        cout<<nd->val;
        if(q.size()!=1) cout<<" ";
        q.pop();
    }
    return 0;
}
