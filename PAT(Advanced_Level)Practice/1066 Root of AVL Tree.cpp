/*
二叉搜索平衡树或者二叉排序平衡树，要同时满足两个条件，二叉平衡树、二叉搜索树；

当存在任一节点的平衡因子的绝对值大于或等于2时，要通过旋转来平衡左右子树，使其平衡因子绝对值小于或者等于1，这里旋转的意思是将“根节点”左侧或者右侧的节点作为“根节点”，并保证是搜索树或者排序树，平衡因子的定义是该节点左子树深度减去右子树深度

由于当左侧或者右侧添加节点时，可能导致平衡因子绝对值>=2，所以此时要根据情况，将挨着“根节点”的左节点或者右节点作为根节点，来平衡，为了保证是排序树，还要将左节点的右侧子树连到“根节点”的左侧， 或者将右节点的左侧子树连到“根节点”的右侧。
————————————————
版权声明：本文为CSDN博主「九是否非随机的称呼」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/m0_50617544/article/details/126331717
*/
#include<iostream>
#include<vector>
#include<set>
#include<bits/stdc++.h>

using namespace std;
struct nodes{
    int val;
    struct nodes *left, *right;
};

nodes *rotateRight(nodes *root){
    nodes *t = root->left;
    root->left = t->right;
    t->right = root;
    return t;
}

nodes *rotateLeft(nodes *root){
    nodes *t = root->right;
    root->right = t->left;
    t->left = root;
    return t;
}

nodes *rotateRightLeft(nodes *root){
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}

nodes *rotateLeftRight(nodes *root){
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}

int getheight(nodes *root){
    if(root==NULL) return 0;
    else return max(getheight(root->left), getheight(root->right)) + 1;
}

nodes *insertnode(nodes *root, int val){
    if(root==NULL){
        root = new nodes();
        root->val = val;
        root->left=root->right=NULL;
    }else if(val < root->val){
        root->left = insertnode(root->left, val);
        if(getheight(root->left) - getheight(root->right)==2)
            return val < root->left->val ? rotateRight(root):rotateLeftRight(root);
    }else if(val > root->val){
        root->right = insertnode(root->right, val);
        if(getheight(root->left) - getheight(root->right)==-2)
            return val > root->right->val ?  rotateLeft(root):rotateRightLeft(root);
    }
    return root;
}

int main(void){
    int i, j, m, n, x, y, k, w;
    cin>>n;
    nodes *nd = NULL;
    for(i = 0; i < n; i++){
        cin>>m;
        nd = insertnode(nd, m);
    }
    cout<<nd->val;
    return 0;
}
