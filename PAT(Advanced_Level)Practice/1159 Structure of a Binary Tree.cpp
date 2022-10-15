#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
vector<int> post, in;
unordered_map<int, int> inmap;
int x1, x2, fulltr = -9;
struct nod{
    nod *l=NULL, *r=NULL, *p=NULL;
    int val = -9, level = 0;
};
unordered_map<int, nod *> udm;

nod* generate(nod *root, nod *parent, int level, int start, int end, int in_s, int in_e) {
    int ind = inmap[post[end]];
    int len = ind - in_s - 1;
    if((len < -1 && (start!=end))||start > end ||in_s > in_e) return root;
    if(root==NULL) {
        root = new(nod);
        root->val = post[end];
        root->p = parent;
        root->level = level;
        udm[post[end]] = root;
    }
    root->l = generate(root->l, root, level+1, start, start + len, in_s, in_s + len);
    root->r = generate(root->r, root, level+1, start + len + 1, end - 1, in_s + len + 2, in_e);
    if((root->l==NULL && root->r!=NULL)||(root->l!=NULL&&root->r==NULL)) fulltr = 9;
    return root;
}

int main(void) {
    int i, j, k, m, n, mr = -9;
    cin>>m;
    post.resize(m);
    in.resize(m);
    nod *root = NULL;
    for(i = 0; i < m; i++) scanf("%d", &post[i]);
    for(i = 0; i < m; i++) {
        scanf("%d", &in[i]);
        inmap[in[i]] = i;
    }
    root = generate(root, root, 0, 0, m-1, 0, m-1);
    cin>>n;
    string t;
    for(i = 0; i < n; i++) {
        cin>>t;
        if(t=="It") {
            printf("%s\n", fulltr>0? "No":"Yes");
            cin>>t>>t>>t;
        }else x1 = stoi(t);
        cin>>t;
        if(t=="and") {
            cin>>x2>>t>>t;
            if(t=="on") {
                cin>>t>>t>>t;
                printf("%s\n", udm[x1]->level==udm[x2]->level? "Yes":"No");
            }else if(t=="siblings") {
                printf("%s\n", (udm[x1]->p==udm[x2]->p&&udm[x1]->p!=NULL)? "Yes":"No");
            }
        } else if(t=="is"){
            cin>>t>>t;
            if(t=="root"){
                printf("%s\n", x1==post[post.size()-1]? "Yes":"No");
            }else if(t=="parent"){
                cin>>t>>x2;
                printf("%s\n", udm[x1]==udm[x2]->p? "Yes":"No");
            }else if(t=="left"){
                cin>>t>>t>>x2;
                printf("%s\n", udm[x1]==udm[x2]->l? "Yes":"No");
            }else if(t=="right"){
                cin>>t>>t>>x2;
                printf("%s\n", udm[x1]==udm[x2]->r? "Yes":"No");
            }
        }
    }
    return 0;
}
