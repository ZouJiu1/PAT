#include <cstdio>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct nod {
    int val = -9;
    nod *l=NULL, *r=NULL;
};
int post[] = {3, 4, 2, 6, 5, 1};
int pre[] = {1, 2, 3, 4, 5, 6};
void printvec(vector<int> a, string t){
    cout<<t<<"\t";
    for(int i=0; i<a.size();i++){
        cout<<a[i];
        if(i!=(a.size()-1))
            cout<<" ";
    }
    cout<<endl;
}
/*
       1
   2         5
3    4    6
or
       1
   2         5
3    4            6
*/

vector<int> inarr;
string not_unique_LeftRight;
void prepost_inorder_v1(int prel, int prer, int postl, int postr) {
    if(prel > prer || postl > postr) return;
    if(pre[prel]!=post[postr]) { //判断前序第一个和后序最后一个是否相等，来判断是否可以产生树要放在最前面, 树不全
        printf("not tree pre[prel]!=post[postr]\n");
        return;
    }
    if(prel==prer && postl==postr) {//保存inorder
        inarr.push_back(pre[prel]);
        return;
    }
    int kk = postl;
    //通过前序的第二个划开后序左右branch，第二个给左branch，主要是：前序：根左 右
    while(kk <= postr && pre[prel + 1]!=post[kk]) kk++;
    if(kk > postr) {//来判断是否可以产生树
        printf("not tree kk > postr\n");
        return;
    } else {
        if(postr - kk > 1) {
            prepost_inorder_v1(prel + 1, prel + (kk - postl+1), postl, kk);   //左branch
            inarr.push_back(pre[prel]);
            prepost_inorder_v1(prel + (kk - postl+2), prer, kk+1, postr-1);   //右branch
        } else {//not unique，不是独一无二的树，可能存在某个节点只有一个子节点，该子节点可能在左也可能在右
            /* reason:
            pre[prel]=post[postr]必然是根节点； 不管是否存在branch，pre:根左右，post：左右根
            (postr -kk <=1)含义是：根节点index - “左|右”节点index
            <=1就是孩子节点个数<=1
            */

           //默认将这个孩子节点划到左branch, 左根右，前序是：根左 右
            if(not_unique_LeftRight=="Left") {
                prepost_inorder_v1(prel + 1, prel + (kk - postl+1), postl, kk);   //左branch
                inarr.push_back(pre[prel]); //根
            }

            //将这个孩子节点划到右branch, 左根右，前序是：根左 右
            if(not_unique_LeftRight=="Right") {
                inarr.push_back(pre[prel]); //根
                prepost_inorder_v1(prel + 1, prel + (kk - postl+1), postl, kk); //右branch
            }
        }
    }
}
nod* gentree_v1(nod *root, int prel, int prer, int postl, int postr) {
    if(prel > prer || postl > postr) return NULL;
    if(root==NULL) {
        root = new(nod);
        root->val = pre[prel];
    }
    if(pre[prel]!=post[postr]) { //判断前序第一个和后序最后一个是否相等，来判断是否可以产生树要放在最前面, 树不全
        printf("not tree pre[prel]!=post[postr]\n");
        return NULL;
    }
    if(prel==prer && postl==postr) {//保存inorder
        inarr.push_back(pre[prel]);
        return root;
    }
    int kk = postl;
    //通过前序的第二个划开后序左右branch，第二个给左branch，主要是：前序：根左 右
    while(kk <= postr && pre[prel + 1]!=post[kk]) kk++;
    if(kk > postr) {//来判断是否可以产生树
        printf("not tree kk > postr\n");
        return NULL;
    } else {
        if(postr - kk > 1) {
            root->l = gentree_v1(root->l, prel + 1, prel + (kk - postl+1), postl, kk);   //左branch
            // inarr.push_back(pre[prel]);
            root->r = gentree_v1(root->r, prel + (kk - postl+2), prer, kk+1, postr-1);   //右branch
        } else {//not unique，不是独一无二的树，可能存在某个节点只有一个子节点，该子节点可能在左也可能在右
            /* reason:
            pre[prel]=post[postr]必然是根节点； 不管是否存在branch，pre:根左右，post：左右根
            (postr -kk <=1)含义是：根节点index - “左|右”节点index
            <=1就是孩子节点个数<=1
            */

           //默认将这个孩子节点划到左branch, 左根右，前序是：根左 右
            if(not_unique_LeftRight=="Left") {
                root->l = gentree_v1(root->l, prel + 1, prel + (kk - postl+1), postl, kk);   //左branch
                // inarr.push_back(pre[prel]); //根
            }

            //将这个孩子节点划到右branch, 左根右，前序是：根左 右
            if(not_unique_LeftRight=="Right") {
                // inarr.push_back(pre[prel]); //根
                root->r= gentree_v1(root->r, prel + 1, prel + (kk - postl+1), postl, kk); //右branch
            }
        }
    }
    return root;
}

void prepost_inorder_v2(int prel, int prer, int postl, int postr) {
    if(prel > prer || postl > postr) return;
    if(pre[prel]!=post[postr]) { //判断前序第一个和后序最后一个是否相等，来判断是否可以产生树要放在最前面, 树不全
        printf("not tree pre[prel]!=post[postr]\n");
        return;
    }
    if(prel==prer && postl==postr) {//保存inorder
        inarr.push_back(pre[prel]);
        return;
    }
    int kk = prel;
    //通过后序的倒数第二个划开前序左右branch，倒数第二个给右branch，主要后序是：左 右根
    while(kk <= prer && pre[kk]!=post[postr - 1]) kk++;
    if(kk > prer) {//来判断是否可以产生树
        printf("not tree kk > postr\n");
        return;
    } else {
        if(kk - prel > 1) {
            prepost_inorder_v2(prel + 1, kk-1, postl, postr - (prer - kk + 2));   //左branch
            inarr.push_back(pre[prel]);
            prepost_inorder_v2(kk, prer, postr - (prer - kk + 1), postr - 1);   //右branch
        } else {//not unique，不是独一无二的树，可能存在某个节点只有一个子节点，该子节点可能在左也可能在右
            /* reason:
            pre[prel]=post[postr]必然是根节点； 不管是否存在branch，pre:根左右，post：左右根
            (kk - prel <=1)含义是：“左|右”节点index - 根节点index
            <=1就是孩子节点个数<=1
            */

           //将这个孩子节点划到左branch, 左根右，后序是：左 右根
            if(not_unique_LeftRight=="Left") {
                prepost_inorder_v2(kk, prer, postr - (prer - kk + 1), postr - 1);   //左branch
                inarr.push_back(pre[prel]); //根
            }

            //默认将这个孩子节点划到右branch, 左根右，后序是：左 右根
            if(not_unique_LeftRight=="Right") {
                inarr.push_back(pre[prel]); //根
                prepost_inorder_v2(kk, prer, postr - (prer - kk + 1), postr - 1); //右branch
            }
        }
    }
}
nod* gentree_v2(nod *root, int prel, int prer, int postl, int postr) {
    if(prel > prer || postl > postr) return NULL;
    if(root==NULL) {
        root = new(nod);
        root->val = pre[prel];
    }
    if(pre[prel]!=post[postr]) { //判断前序第一个和后序最后一个是否相等，来判断是否可以产生树要放在最前面, 树不全
        printf("not tree pre[prel]!=post[postr]\n");
        return NULL;
    }
    if(prel==prer && postl==postr) {//保存inorder
        inarr.push_back(pre[prel]);
        return root;
    }
    int kk = prel;
    //通过后序的倒数第二个划开前序左右branch，倒数第二个给右branch，主要后序是：左 右根
    while(kk <= prer && pre[kk]!=post[postr - 1]) kk++;
    if(kk > prer) {//来判断是否可以产生树
        printf("not tree kk > postr\n");
        return NULL;
    } else {
        if(kk - prel > 1) {
            root->l = gentree_v2(root->l, prel + 1, kk-1, postl, postr - (prer - kk + 2));   //左branch
            // inarr.push_back(pre[prel]);
            root->r = gentree_v2(root->r, kk, prer, postr - (prer - kk + 1), postr - 1);   //右branch
        } else {//not unique，不是独一无二的树，可能存在某个节点只有一个子节点，该子节点可能在左也可能在右
            /* reason:
            pre[prel]=post[postr]必然是根节点； 不管是否存在branch，pre:根左右，post：左右根
            (kk - prel <=1)含义是：“左|右”节点index - 根节点index
            <=1就是孩子节点个数<=1
            */

           //将这个孩子节点划到左branch, 左根右，后序是：左 右根
            if(not_unique_LeftRight=="Left") {
                root->l = gentree_v2(root->l, kk, prer, postr - (prer - kk + 1), postr - 1);   //左branch
                // inarr.push_back(pre[prel]); //根
            }

            //默认将这个孩子节点划到右branch, 左根右，后序是：左 右根
            if(not_unique_LeftRight=="Right") {
                // inarr.push_back(pre[prel]); //根
                root->r= gentree_v2(root->r, kk, prer, postr - (prer - kk + 1), postr - 1); //右branch
            }
        }
    }
    return root;
}

void preorder(nod *root) {
    if(root==NULL) return;
    inarr.push_back(root->val);
    preorder(root->l);
    preorder(root->r);
}
void inorder(nod *root) {
    if(root==NULL) return;
    inorder(root->l);
    inarr.push_back(root->val);
    inorder(root->r);
}
void postorder(nod *root) {
    if(root==NULL) return;
    postorder(root->l);
    postorder(root->r);
    inarr.push_back(root->val);
}

int main() {
    //通过前序的第二个划开后序左右branch，第二个给左branch，主要是：前序：根左 右
    not_unique_LeftRight = "Left";
    prepost_inorder_v1(0, 5, 0, 5); //0prel 5prer, 0postl, 5postr
    printvec(inarr, "v1 not_unique_LeftRight: Left, inarr:");
    not_unique_LeftRight = "Right";
    inarr.clear();
    prepost_inorder_v1(0, 5, 0, 5); //0prel 5prer, 0postl, 5postr
    printvec(inarr, "v1 not_unique_LeftRight: Right, inarr:");

    nod *root = NULL;
    root = gentree_v1(root, 0, 5, 0, 5);
    inarr.clear();
    preorder(root);
    printvec(inarr, "preorder:");

    inarr.clear();
    inorder(root);
    printvec(inarr, "inorder:");

    inarr.clear();
    postorder(root);
    printvec(inarr, "postorder:");


    //通过后序的倒数第二个划开前序左右branch，倒数第二个给右branch，主要后序是：左 右根
    not_unique_LeftRight = "Left";
    inarr.clear();
    prepost_inorder_v2(0, 5, 0, 5); //0prel 5prer, 0postl, 5postr
    printvec(inarr, "v2 not_unique_LeftRight: Left, inarr:");
    not_unique_LeftRight = "Right";
    inarr.clear();
    prepost_inorder_v2(0, 5, 0, 5); //0prel 5prer, 0postl, 5postr
    printvec(inarr, "v2 not_unique_LeftRight: Right, inarr:");

    root = NULL;
    root = gentree_v2(root, 0, 5, 0, 5);
    inarr.clear();
    preorder(root);
    printvec(inarr, "preorder:");

    inarr.clear();
    inorder(root);
    printvec(inarr, "inorder:");

    inarr.clear();
    postorder(root);
    printvec(inarr, "postorder:");
    return 0;
}
