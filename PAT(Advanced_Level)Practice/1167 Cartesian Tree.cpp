已知是heaporder对inorder排序，然后gen树，要判断在inorder前一个节点的左右，就可以左右依次gen，得到相应的内容；
也可以不用gen树拿到最小值和index直接保存层序遍历，最小堆，最小值就是根节点划开左右branch，使用map自动排序的特点

不能使用数组存储res(10741824, -999)  res[index] = v[pot];    会越界，要使用map存储并自动排序
update1
#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int m, cnt = 0;
vector<int> arr, cp;
unordered_map<int, int> ump;
struct nod{nod *l=NULL, *r=NULL; int val=-99;};
nod *recursion(nod *root, int start) {
    if(root==NULL) {
        root = new(nod);
        root->val = cp[start];
    }
    if(ump[cp[start]] < ump[root->val]) root->l = recursion(root->l, start);
    if(ump[cp[start]] > ump[root->val]) root->r = recursion(root->r, start);
    return root;
}
int main(int argc, char **argv){
    int i, j, k, n;
    cin>>m;
    for(i = 0; i < m; i++){
        cin>>k;
        arr.push_back(k);
        ump[k] = i;
    }
    cp = arr;
    sort(cp.begin(), cp.end());
    nod *root = NULL;
    for(i = 0; i < m; i++)
        root = recursion(root, i);
    vector<int> lev;
    queue<nod *> q;
    q.push(root);
    while(q.size()!=0) {
        nod *tmp = q.front();
        if(tmp->l!=NULL) q.push(tmp->l);
        if(tmp->r!=NULL) q.push(tmp->r);
        lev.push_back(tmp->val);
        q.pop();
    }
    printf("%d", lev[0]);
    for(i = 1; i< lev.size(); i++) printf(" %d", lev[i]);
    return EXIT_SUCCESS;
}

old before
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>
using namespace std;
vector<int> v;
unordered_map<int, int> mp;
struct nod{nod *l=NULL, *r=NULL; int val;};
nod* generate(nod *root, int val) {
    int ind = mp[val];
    if(root==NULL){
        root = new(nod);
        root->val = val;
    }else if(ind < mp[root->val])
        root->l = generate(root->l, val);
    else if(ind > mp[root->val])
        root->r = generate(root->r, val);
    return root;
}
int main(void) {
    int i, j, k, m, n;
    cin>>m;
    for(i = 0; i < m; i++) {
        cin>>n;
        v.push_back(n);
        mp[n] = i;
    }
    sort(v.begin(), v.end());
    nod *nd, *root = NULL;
    for(i = 0; i < v.size(); i++)
        root = generate(root, v[i]);
    queue<nod *>q;
    q.push(root);
    while(q.size() > 0) {
        nd = q.front();
        if(nd->l!=NULL) q.push(nd->l);
        if(nd->r!=NULL) q.push(nd->r);
        cout<<nd->val;
        if(q.size()!=1) cout<<" ";
        q.pop();
    }
    return 0;
}

update2
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int m, lev[1000];
vector<int> arr;
map<int, int> mp;
//树的遍历和产生key是split 左右branch的条件，然后将根节点入栈
void recursion(int index, int l, int r) {//最小堆，最小值划开左右branch
    if(l >= r) return;
    int minmin = 999999999, id=l;
    for(int i = l; i < r; i++) {
        if(minmin > arr[i]) {
            minmin = arr[i];
            id = i;
        }
    }
    mp[index] = arr[id];
    recursion(index * 2, l, id);
    recursion(index * 2 + 1, id + 1, r);
}
int main(int argc, char **argv){
    int i, j, k, n, maxmax = -999999999;
    cin>>m;
    for(i = 0; i < m; i++){
        cin>>k;
        arr.push_back(k);
        if(maxmax < k) maxmax = k;
    }
    recursion(1, 0, m);
    for(map<int, int>::iterator it=mp.begin(); it!=mp.end(); it++) {
        printf("%d", it->second);
        if(it->second!=maxmax) printf(" ");
    }
    return EXIT_SUCCESS;
}
