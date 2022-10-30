update
#include<stack>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
//1 2 3 4 5 6
//3 2 4 1 6 5
int m, array[60];
vector<int> in, pre, post;
unordered_map<int, int> mp, inp;
void postorder(int root, int start, int end) {
    if(start > end) return;
    int i = inp[pre[root]];
    postorder(root + 1, start, i - 1);
    postorder(root + i - start + 1, i + 1, end);
    post.push_back(pre[root]);
}
int main(int argc, char **argv) {
    int i, j, n, k, y, z = 0;
    cin>>m;
    stack<int> t;
    char cr[6];
    while(~scanf("%s", cr)) {
        if(strlen(cr)==4){
            scanf("%d", &k);
            mp[z] = k;
            pre.push_back(z);
            t.push(z++);
        } else {
            inp[t.top()] = in.size();
            in.push_back(t.top());
            t.pop();
        }
    }
    postorder(0, 0, m - 1);
    printf("%d", mp[post[0]]);
    for(i = 1; i < post.size(); i++) printf(" %d", mp[post[i]]);
    return 0;
}


old before
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
