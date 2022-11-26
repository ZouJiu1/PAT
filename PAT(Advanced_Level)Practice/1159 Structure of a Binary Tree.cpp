old before

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

//update 1
#include<iostream>
#include<string>
using namespace std;
struct nod {nod *l=NULL, *r=NULL, *p=NULL; int level, val = -9;};
int postorder[31], inorder[31], fulltree=9;
nod *nd[1001];
nod* gentree(nod *rot, int start, int left, int right, int lev, nod *rot_pre) {
    int k = left, now = postorder[start];
    if(left > right) return NULL;
    if(rot==NULL) {
        rot = new(nod);
        rot->val = now;
        rot->p   = rot_pre;
        rot->level = lev;
    }
    while(inorder[k]!=now) k++;
    rot->l = gentree(rot->l, start - (right - k) - 1, left, k - 1, lev + 1, rot);
    rot->r = gentree(rot->r, start - 1, k + 1, right, lev + 1, rot);
    nd[now] = rot;
    if((rot->r==NULL&&rot->l!=NULL)||(rot->r!=NULL&&rot->l==NULL)) fulltree=-9;
    return rot;
}
int main(int argc, char **argv) {
    int i, j, k, m, n, y, z;
    cin>>m;
    for(i = 0; i < m; i++) scanf("%d", &postorder[i]);
    for(i = 0; i < m; i++) scanf("%d", &inorder[i]);
    nod *rot = NULL;
    rot = gentree(rot, m - 1, 0, m - 1, 0, NULL);
    cin>>y;
    string t, t1;
    for(i = 0; i < y; i++) {
        cin>>t;
        if(t=="It"){
            printf("%s\n", fulltree > 0? "Yes":"No");
            cin>>t>>t>>t>>t;
            continue;
        }
        z = stoi(t);
        cin>>t;
        if(t=="is") {
            cin>>t>>t;
            if(t=="root"){
                printf("%s\n", postorder[m-1]==z? "Yes":"No");
            }else if(t=="parent"){
                cin>>t>>n;
                printf("%s\n", nd[n]->p==nd[z]? "Yes":"No");
            }else if(t=="left"){
                cin>>t>>t>>n;
                printf("%s\n", nd[n]->l==nd[z]? "Yes":"No");
            }else if(t=="right"){
                cin>>t>>t>>n;
                printf("%s\n", nd[n]->r==nd[z]? "Yes":"No");
            }
        }else if(t=="and"){
            cin>>n>>t1>>t1;
            if(t1=="siblings"){
                printf("%s\n", nd[z]->p==nd[n]->p&&nd[z]!=NULL? "Yes":"No");
            }else if(t1=="on"){
                cin>>t1>>t1>>t1;
                printf("%s\n", nd[n]->level==nd[z]->level? "Yes":"No");
            }
        }
    }
    return EXIT_SUCCESS;
}

//update 2
#include<iostream>
#include<string>
using namespace std;
struct nod {int l=-9, r=-9, p=-9, level;};
int postorder[31], inorder[31], fulltree=9;
nod nd[1001];
void gentree(int start, int left, int right, int lev, int pre_start, int l_r) {
    int k = left, now = postorder[start];
    if(left > right) return;
    nd[now].level = lev;
    if(pre_start > 0) nd[now].p = pre_start;
    if(l_r > 0) nd[pre_start].r = now;
    if(l_r < 0) nd[pre_start].l = now;
    while(inorder[k]!=now) k++;
    gentree(start - (right - k) - 1, left, k - 1, lev + 1, now, -1);
    gentree(start - 1, k + 1, right, lev + 1, now, 1);
    if(nd[now].r * nd[now].l < 0) fulltree = -9;
}
int main(int argc, char **argv) {
    int i, j, k, m, n, y, z;
    cin>>m;
    for(i = 0; i < m; i++) scanf("%d", &postorder[i]);
    for(i = 0; i < m; i++) scanf("%d", &inorder[i]);
    gentree(m - 1, 0, m - 1, 0, -1, 0);
    cin>>y;
    string t, t1;
    for(i = 0; i < y; i++) {
        cin>>t;
        if(t=="It"){
            printf("%s\n", fulltree > 0? "Yes":"No");
            cin>>t>>t>>t>>t;
            continue;
        }
        z = stoi(t);
        cin>>t;
        if(t=="is") {
            cin>>t>>t;
            if(t=="root"){
                printf("%s\n", postorder[m-1]==z? "Yes":"No");
            }else if(t=="parent"){
                cin>>t>>n;
                printf("%s\n", nd[n].p==z? "Yes":"No");
            }else if(t=="left"){
                cin>>t>>t>>n;
                printf("%s\n", nd[n].l==z? "Yes":"No");
            }else if(t=="right"){
                cin>>t>>t>>n;
                printf("%s\n", nd[n].r==z? "Yes":"No");
            }
        }else if(t=="and"){
            cin>>n>>t1>>t1;
            if(t1=="siblings"){
                printf("%s\n", nd[z].p==nd[n].p? "Yes":"No");
            }else if(t1=="on"){
                cin>>t1>>t1>>t1;
                printf("%s\n", nd[n].level==nd[z].level? "Yes":"No");
            }
        }
    }
    return EXIT_SUCCESS;
}
