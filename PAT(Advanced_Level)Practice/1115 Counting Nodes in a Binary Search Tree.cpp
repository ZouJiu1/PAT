update
#include<iostream>
#include<vector>
using namespace std;
struct nod {
    nod *l=NULL, *r=NULL; 
    int val;
};
int maxmax = -9999999, level[1001];
nod *bstinsert(nod *root, int val, int lev) {
    if(root==NULL){
        root = new(nod);
        root->val = val;
        level[lev]++;
        if(maxmax < lev) maxmax = lev;
    }else if(val <= root->val) root->l = bstinsert(root->l, val, lev + 1);
    else root->r = bstinsert(root->r, val, lev + 1);
    return root;
}
int main(int argc, char **argv) {
    int m, n, i, j, k;
    cin>>m;
    nod *root = NULL;
    for(i = 0; i < m; i++) {
        cin>>n;
        root = bstinsert(root, n, 0);
    }
    printf("%d + %d = %d\n", level[maxmax], level[maxmax - 1], level[maxmax]+level[maxmax - 1]);
    return 0;
}

old before
#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>

using namespace std;

struct nod{
    struct nod *l=nullptr;
    struct nod *r=nullptr;
    int val = -999;
};

vector<int> depthcol;

void insertion_binary_search_tree(struct nod *root, int val,
        int depth) {
    if(root->val==-999) {
        root->val = val;
        depthcol.push_back(depth);
        return;
    }
    if(val <= root->val) {
        if(root->l==nullptr)
            root->l = new(struct nod);
        insertion_binary_search_tree(root->l, val, depth + 1);
    }
    else {
        if(root->r==nullptr)
            root->r = new(struct nod);
        insertion_binary_search_tree(root->r, val, depth + 1);
    }
}

int main(void) {
    int i, j, k, m, n;
    cin>>n;
    struct nod *root = new(struct nod);
    vector<int> v;
    for(i = 0; i < n; i++) {
        cin>>m;
        v.push_back(m);
        insertion_binary_search_tree(root, m, 0);
    }
    int maxmax = -999999;
    for(i = 0; i < depthcol.size(); i++) {
        if(depthcol[i] > maxmax) {
            maxmax = depthcol[i];
        }
    }
    int lowest = 0, pre_lowest = 0;
    for(i = 0; i < depthcol.size(); i++) {
        if(depthcol[i]==maxmax)
            lowest++;
        if(depthcol[i]==maxmax-1)
            pre_lowest++;
    }
    cout<<lowest<<" + "<<pre_lowest<<" = "<<(lowest + pre_lowest);
    return 0;
}
