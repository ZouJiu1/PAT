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
int in[] = {3, 2, 4, 1, 6, 5};
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
*/

vector<int> prearr;
void pre(int root, int start, int end) {
    if(start > end) return;
    int kk = start;
    while(post[root]!=in[kk]) kk++;
    if(kk > end) {
        printf("can not gen");
    } else {
        prearr.push_back(post[root]);
        pre(root - (end - kk + 1), start, kk-1);
        pre(root - 1, kk+1, end);
    }
}
nod* gentree(nod *root, int postroot, int start, int end) {
    if(start > end) return NULL;
    if(root==NULL) {
        root = new(nod);
        root->val = post[postroot];
    }
    int kk = start;
    while(post[postroot]!=in[kk]) kk++;
    root->l = gentree(root->l, postroot - (end - kk + 1), start, kk-1);
    root->r = gentree(root->r, postroot - 1, kk+1, end);
    return root;
}
void preorder(nod *root) {
    if(root==NULL) return;
    prearr.push_back(root->val);
    preorder(root->l);
    preorder(root->r);
}
void inorder(nod *root) {
    if(root==NULL) return;
    inorder(root->l);
    prearr.push_back(root->val);
    inorder(root->r);
}
void postorder(nod *root) {
    if(root==NULL) return;
    postorder(root->l);
    postorder(root->r);
    prearr.push_back(root->val);
}

// void pre(int root, int start, int end) {
//     if(start > end) return ;
//     int i = start;
//     while(i < end && in[i] != post[root]) i++;
//     printf("%d ", post[root]);
//     pre(root - 1 - end + i, start, i - 1);
//     pre(root - 1, i + 1, end);
// } 
int main() {
    pre(5, 0, 5); //5POST, 0INL, 5INR
    printvec(prearr, "generate prearr:");

    nod *root = NULL;
    root = gentree(root, 5, 0, 5);
    prearr.clear();
    preorder(root);
    printvec(prearr, "preorder:");

    prearr.clear();
    inorder(root);
    printvec(prearr, "inorder:");

    prearr.clear();
    postorder(root);
    printvec(prearr, "postorder:");
    return 0;
}
