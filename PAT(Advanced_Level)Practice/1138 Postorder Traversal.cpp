#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<bits/stdc++.h>

using namespace std;

int x, y, z;

struct nodees{
    struct nodees *left;
    struct nodees *right;
    int values;
};

vector<int> v, v0;
map<int, int> ind0;

void gettree(nodees *nd, 
            int begin_l, int end_l, int begin_r0, int end_r0){
    if((end_l - begin_l!=end_r0-begin_r0)||
        begin_l>end_l||begin_r0>end_r0||
        end_l<0||end_r0<0) return;
    x = v[begin_l];
    nd->values = x;
    int b_l0, e_l0, b_l1, e_l1, b_r0, e_r0, b_r1, e_r1;
    y = ind0[x];
    begin_l++;
    b_r0 = begin_r0;
    e_r0 = y - 1;
    b_r1 = y+1;
    e_r1 = end_r0;
    y = min(end_l + 1, end_l - (end_r0 - y) + 1);
    b_l0 = begin_l;
    e_l0 = y-1;
    b_l1 = y;
    e_l1 = end_l;

    nd->left = (struct nodees *)malloc(sizeof(struct nodees));
    nd->right = (struct nodees *)malloc(sizeof(struct nodees));
    nd->left->values = 2147483630;
    nd->right->values = 2147483630;
    gettree(nd->left, b_l0, e_l0, b_r0, e_r0);
    gettree(nd->right, b_l1, e_l1, b_r1, e_r1);
}

void postorder(struct nodees *root) {
    if(root->values >= 2147483630) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->values<<endl;
    exit(0);
}

int main(void){
    int n, i, j, a, c;
    cin>>n;
    struct nodees *nd = (struct nodees *)malloc(sizeof(struct nodees));
    for(i = 0; i < n; i++) {
        cin>>a;
        v.push_back(a);
    }
    for(i = 0; i < n; i++) {
        cin>>a;
        v0.push_back(a);
        ind0[a] = i;
    }
    gettree(nd, 0, v.size()-1, 0, v0.size() - 1); 
    postorder(nd);
    return 0;
}
