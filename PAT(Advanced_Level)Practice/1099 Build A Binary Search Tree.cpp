二叉搜索树，左<根<=右，中序遍历是“左根右”，所以中序遍历一定是从小到大排列的
或者左>=根>右，从大到小排列

不能AC的codes仅作错误示例，层序用index会出错可能越界 > long long最大值，主要是2的100次方太大了，所以这题不能用index!!!，直接保存每层的数值

/*
不能AC的codes仅作错误示例，层序用index会出错可能越界 
> long long最大值，主要是2的100次方太大了，
所以这题不能用index!!!，直接保存每层的数值
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
map<long long, long long, less<long long>> lev;
int arr[200][2] = {0}, tmp[200]={0}, cnt = 0, N, ind = -999999999;
void inorder(int rot, long long index) {
    if(rot == -1) return;
    if(index > ind) ind = index;
    inorder(arr[rot][0], index * 2);
    lev[index] = tmp[cnt++];
    inorder(arr[rot][1], index * 2 + 1);
}
int main(void) {
    int i, j, m, n, k;
    cin>>N;
    for(i = 0; i < N; i++) {
        cin>>arr[i][0]>>arr[i][1];
    }
    for(i = 0; i < N; i++) scanf("%d", &tmp[i]);
    sort(tmp, tmp + N);
    inorder(0, 1);
    for(auto it:lev) printf("%d%s", it.second, it.first==ind? "\n":" ");
    return 0;
}
*/

update2

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int m, n, k, z, y, cnt = 0;
int arr[101];
vector<int> level[101], v;
struct rec{int l=0, r=0;};
rec tm[101] = {0};
void inorder(int a, int le) {
    if(tm[a].l!=-1) inorder(tm[a].l, le + 1);
    level[le].push_back(arr[cnt++]);
    if(tm[a].r!=-1) inorder(tm[a].r, le + 1);
}
int main(int argc, char **argv) {
    int i, j;
    cin>>m;
    rec rc;
    for(i = 0; i < m; i++) cin>>tm[i].l>>tm[i].r;
    for(i = 0; i < m; i++) scanf("%d", &arr[i]);
    sort(arr, arr + m);
    inorder(0, 0);
    for(i = 0; i < 101; i++) {
        for(j = 0; j < level[i].size(); j++) {
            v.push_back(level[i][j]);
        }
    }
    printf("%d", v[0]);
    for(i = 1; i < v.size(); i++) printf(" %d", v[i]);
    return 0;
}

update
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int m, n, k, z, y, cnt = 0;
int arr[101];
vector<int> level[101], v;
struct nod {
    nod *l=NULL, *r=NULL;
    int val;
};
struct rec{int l=0, r=0;};
rec tm[101] = {0};
void inorder(nod *root, int le) {
    if(root==NULL) return;
    inorder(root->l, le + 1);
    // root->val = arr[cnt++];
    level[le].push_back(arr[cnt++]);
    inorder(root->r, le + 1);
}
nod* generate(int th, nod *root) {
    if(root==NULL) root = new(nod);
    if(tm[th].l!=-1) root->l = generate(tm[th].l, root->l);
    if(tm[th].r!=-1) root->r = generate(tm[th].r, root->r);
    return root;
}
int main(int argc, char **argv) {
    int i, j;
    cin>>m;
    rec rc;
    for(i = 0; i < m; i++) 
    {
        cin>>tm[i].l>>tm[i].r;
    }
    nod *root=NULL;
    root = generate(0, root);
    for(i = 0; i < m; i++) scanf("%d", &arr[i]);
    sort(arr, arr + m);
    inorder(root, 0);
    for(i = 0; i < 101; i++) 
    {
        for(j = 0; j < level[i].size(); j++) 
        {
            v.push_back(level[i][j]);
        }
    }
    printf("%d", v[0]);
    for(i = 1; i < v.size(); i++) printf(" %d", v[i]);
    return 0;
}
