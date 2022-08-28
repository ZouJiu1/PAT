/*先产生颗树然后递归*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
struct nod{
    struct nod *before=NULL;
    struct nod *left=NULL;
    struct nod *right=NULL;
    int pop = 0;
    int val = 0;
};
vector<int> vec;

void postorder(struct nod *root){
    if(root->left!=NULL)
        postorder(root->left);
    if(root->right!=NULL)
        postorder(root->right);
    vec.push_back(root->val);
}

int main(void){
    int i, j, k, m, n, w, x, y;
    cin>>n;
    string s;
    struct nod *root, *rt;
    rt = new(struct nod);
    root = rt;
    w = 0;
    for(i = 0; i < 2 * n; i++){
        cin>>s;
        if(s[1]=='u'){
            cin>>m;
            if(root->val==0) root->val = m;
            else if(root->left!=NULL&&root->left->val==0) {
                root->left->val = m;
                root->left->before = root;
                root = root->left;
            }
            else if(root->right!=NULL&&root->right->val==0) {
                root->right->val = m;
                root->right->before = root;
                root = root->right;
            }else if(root->left==NULL){
                root->left = new(struct nod);
                root->left->before = root;
                root->left->val = m;
                root = root->left;
            }else if(root->right==NULL){
                root->right = new(struct nod);
                root->right->before = root;
                root->right->val = m;
                root = root->right;
            }
        }
        else if(s[1]=='o'){
            while(root->pop!=0){
                root = root->before;
            }
            root->pop = 9;
        }
    }
    postorder(rt);
    for(i = 0; i < vec.size(); i++){
        cout<<vec[i];
        if(i!=vec.size()-1) cout<<" ";
    }
    return 0;
}
