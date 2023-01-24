update202301
#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
int pre[31], mr;
struct nod {
    nod *l=NULL, *r = NULL;
    int val;
};
nod *gentree(nod *rot, int val) {
    if(rot==NULL) {
        rot = new(nod);
        rot->val = val;
    }
    else if(abs(val) <= abs(rot->val)) rot->l = gentree(rot->l, val);   //多次gentree，要用else if
    else if(abs(val) > abs(rot->val)) rot->r = gentree(rot->r, val);
    return rot;
}
void preorder(nod *rot) {
    if(rot==NULL) return;
    if(rot->val < 0) {
        if((rot->l!=NULL && rot->l->val < 0) || (rot->r!=NULL && rot->r->val < 0)) mr = -9;
    }
    preorder(rot->l);
    preorder(rot->r);
}
int getnum(nod *rot) {
    if(rot==NULL) return 0;
    int a = getnum(rot->l);
    int c = getnum(rot->r);
    return rot->val > 0? max(a, c) + 1 : max(a, c); //可能存在只有一个孩子节点，0, 1最大值
}
bool recursion(nod *rot) {
    if(rot==NULL) return true;
    int a = getnum(rot->l);
    int c = getnum(rot->r);
    if(a!=c) return false;
    return recursion(rot->l) && recursion(rot->r);
}
int main(int argc, char **argv) {
    int i, j, k, m, n, x, y, z;
    cin>>k;
    for(i = 0; i < k; i++) {
        cin>>n;
        nod *rot = NULL;
        for(j = 0; j < n; j++) {
            scanf("%d", &pre[j]);
            rot = gentree(rot, pre[j]);
        }
        mr = 9;
        preorder(rot);
        if(rot->val < 0 || mr < 0 || recursion(rot)==false) {
            printf("No\n");
            continue;
        }else printf("Yes\n");
    }
    return 0;
}

old before

#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<bits/stdc++.h>

using namespace std;

struct nod {
    struct nod *l=NULL, *r=NULL;
    int val;
};

struct nod* generate_redblack(struct nod *root, int val) {
    if(root==NULL) {
        root = new(struct nod);
        root->val = val;
        return root;
    }
    else if(abs(val) <= abs(root->val)) {
        root->l = generate_redblack(root->l, val);
    }else if(abs(val) > abs(root->val)) {
        root->r = generate_redblack(root->r, val);
    }
    return root;
}

set<int> black_st;

// void dfs(struct nod *root, int black) {
//     if(root==NULL) return;
//     if(root->l==NULL && root->r==NULL) { //leave
//         if(root->val > 0)
//             black_st.insert(black + 1);
//         else black_st.insert(black);
//     }
//     if(root->val > 0)
//         dfs(root->l, black + 1);
//     else dfs(root->l, black);
//     if(root->val > 0)
//         dfs(root->r, black + 1);
//     else dfs(root->r, black);
// }

int getnum(struct nod *root) {
    if(root==NULL) return 0;
    int l = getnum(root->l);
    int r = getnum(root->r);
    return root->val > 0 ? max(l, r) + 1:max(l, r);
}

bool dfs(struct nod *root) {
    if(root==NULL) return true;
    int l = getnum(root->l);
    int r = getnum(root->r);
    if(l!=r) return false;
    return dfs(root->l) && dfs(root->r);
}

int main(void) {
    int i, j, m, n, k;
    vector<vector<int>> v1;
    cin>>n;
    v1.resize(n);
    for(i = 0; i < n; i++) {
        cin>>m;
        for(j = 0; j < m; j++) {
            cin>>k;
            v1[i].push_back(k);
        }
    }
    for(i = 0; i < n; i++) {
        struct nod *root = NULL;
        for(j = 0; j < v1[i].size(); j++) {
            root = generate_redblack(root, v1[i][j]);
        }
        if(root->val < 0) {
            cout<<"No"<<endl;
            continue;
        }

        queue<struct nod*> q;
        q.push(root);
        int mr = -9;
        if(dfs(root)==false) mr = 9;
        while(q.size() > 0 && mr <0) {
            struct nod* nd = q.front();
            // dfs(nd, 0);
            // if(black_st.size()!=1) {
            //     mr = 9;
            //     break;
            // }
            // black_st.clear();
            if(nd->l!=NULL) q.push(nd->l);
            if(nd->r!=NULL) q.push(nd->r);
            if(nd->val < 0) {
                if(nd->l!=NULL && nd->l->val < 0) {
                    mr = 9;
                    break;
                }
                if(nd->r!=NULL && nd->r->val <0) {
                    mr = 9;
                    break;
                }
            }
            q.pop();
        }
        if(mr > 0) {
            cout<<"No"<<endl;
            continue;
        }
        cout<<"Yes"<<endl;
    }
    return 0;
}

update

#include<iostream>
#include<queue>
using namespace std;
int m, n, ll[31], status;
struct nod{nod *l=NULL, *r=NULL; int val;};
nod *generate(nod *root, int val) {
    if(root==NULL) {
        root = new(nod);
        root->val = val;
    } else if(abs(val) < abs(root->val)) root->l = generate(root->l, val);
    else if(abs(val) >= abs(root->val)) root->r = generate(root->r, val);
    return root;
}
int getnum(nod *root) {
    if(root==NULL) return 0;
    int l = getnum(root->l);
    int r = getnum(root->r);
    return root->val > 0? max(l, r) + 1 : max(l, r);
}
bool recursion(nod *root) {
    if(root==NULL) return true;
    int l = getnum(root->l);
    int r = getnum(root->r);
    if(l!=r) return false;
    return recursion(root->l) && recursion(root->r);
}
bool black(nod *root) {
    if(root==NULL) return true;
    if(root->val < 0) {
        if(root->l!=NULL && root->l->val < 0) return false;
        if(root->r!=NULL && root->r->val < 0) return false;
    }
    return black(root->l) && black(root->r);
}
int main(int argc, char **argv) {
    int i, j, k;
    cin>>m;
    for(i = 0; i < m; i++) {
        cin>>n;
        nod *root = NULL;
        for(j = 0; j < n; j++) {
            scanf("%d", &ll[j]);
            root = generate(root, ll[j]);
        }
        if(root->val < 0 ||recursion(root)==false || black(root)==false) {
            cout<<"No"<<endl;
        } else cout<<"Yes"<<endl;
    }
    return 0;
}
