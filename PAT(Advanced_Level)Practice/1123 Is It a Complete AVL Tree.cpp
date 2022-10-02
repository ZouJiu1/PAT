#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<bits/stdc++.h>

using namespace std;

struct nod {
    int val;
    struct nod *l, *r;
};

nod *rotate_to_Right(nod *root) {
    nod *tmp = root->l;
    root->l = tmp->r;
    tmp->r = root;
    return tmp;
}

nod *rotate_to_Left(nod *root) {
    nod *tmp = root->r;
    root->r = tmp->l;
    tmp->l = root;
    return tmp;
}

nod *rotate_to_Right_to_Left(nod *root) {
    root->r = rotate_to_Right(root->r);
    return rotate_to_Left(root);
}

nod *rotate_to_Left_to_Right(nod *root) {
    root->l = rotate_to_Left(root->l);
    return rotate_to_Right(root);
}

int getHeight(nod *root) {
    if(root==NULL) return 0;
    else return max(getHeight(root->l), getHeight(root->r)) + 1;
}

nod *insertion_self_balancing_binary_search_tree(nod *root, int value) {
    if(root==NULL) {
        root = new(struct nod);
        root->val = value;
        root->l = NULL;
        root->r = NULL;
    }
    else if(value <= root->val) {
        root->l = insertion_self_balancing_binary_search_tree(root->l, value);
        if(abs(getHeight(root->l) - getHeight(root->r)) >= 2) {
            return value < root->l->val? rotate_to_Right(root) : rotate_to_Left_to_Right(root);
        }
    }
    else if(value > root->val) {
        root->r = insertion_self_balancing_binary_search_tree(root->r, value);
        if(abs(getHeight(root->l) - getHeight(root->r)) >= 2) {
            return value > root->r->val? rotate_to_Left(root) : rotate_to_Right_to_Left(root); 
        }
    }
    return root;
}

int main(void) {
    int i, j, k, m, n;
    cin>>n;
    struct nod *root = NULL;
    for(i = 0; i < n; i++) {
        cin>>m;
        root = insertion_self_balancing_binary_search_tree(root, m);
    }
    queue<struct nod*>q;
    queue<int> q_level;
    vector<int> level;
    q.push(root);
    int lev;
    q_level.push(0);
    int height = getHeight(root);
    vector<int> vec, lastlayer;
    nod *pre = root;
    int maxmax = -9999999;
    while(q.size()!=0) {
        nod *nd = q.front();
        vec.push_back(nd->val);
        lev = q_level.front();
        level.push_back(lev);
        lev++;
        if(lev==height-1 && nd->l==NULL) {
            lastlayer.push_back(-1);
        }else if(lev==height-1 && nd->l!=NULL) {
            lastlayer.push_back(1);
            maxmax = lastlayer.size();
        }
        if(lev==height-1 && nd->r==NULL) {
            lastlayer.push_back(-1);
        }else if(lev==height-1 && nd->r!=NULL) {
            lastlayer.push_back(1);
            maxmax = lastlayer.size();
        }
        if(nd->l!=NULL) {
            q.push(nd->l);
            q_level.push(lev);
        }
        if(nd->r!=NULL) {
            q.push(nd->r);
            q_level.push(lev);
        }
        pre = nd;
        q.pop();
        q_level.pop();
    }
    map<int, int> mp;
    for(i = 0; i < level.size(); i++) {
        mp[level[i]]++;
    }
    int ww, fin = -9;
    for(i = 0; i < height - 1; i++) {
        ww = (int)pow(2, i);
        if(mp[i]!=ww) {
            fin = 9;
            break;
        }
    }
    for(i = 0; i < vec.size(); i++) {
        cout<<vec[i];
        if(i!=vec.size() - 1) cout<<" ";
    }
    cout<<endl;
    int res = 1;
    for(i = 0; i < maxmax; i++) {
        if(lastlayer[i] < 0) {
            fin = 9;
            break;
        }
    }
    if(fin > 0) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}
