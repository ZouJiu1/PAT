1、对priority排序，然后依次放入搜索树
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
struct nod{
    nod *l=NULL, *r=NULL;
    int key, pri;
};
nod nd;
int cnt = 0, maxmax = -999999999;
vector<nod> v;
map<int, int> levkey, levpri;
nod* recursion(nod val, nod *rot, int index) {
    if(rot==NULL) {
        rot = new(nod);
        rot->key = val.key;
        rot->pri = val.pri;
        levkey[index] = val.key;
        levpri[index] = val.pri;
        if(maxmax < index) maxmax = index;
    } else if(val.key <= rot->key) rot->l = recursion(val, rot->l, 2*index + 1);
    else rot->r = recursion(val, rot->r, 2*index + 2);
    return rot;
}
bool cmp(nod &a, nod &c) {
    return a.pri < c.pri;
}
int main(void) {
    int i, j, k, m, n, N, M, K, num;
    cin>>N;
    nod *rot = NULL;
    for(i = 0; i < N; i++) {
        cin>>nd.key>>nd.pri;
        v.push_back(nd);
    }
    sort(v.begin(), v.end(), cmp);
    for(i = 0; i < N; i++) {
        rot = recursion(v[i], rot, 0);
    }
    for(auto it:levkey) {
        printf("%d", it.second);
        if(it.first!=maxmax) printf(" ");
    }
    printf("\n");
    for(auto it:levpri) {
        printf("%d", it.second);
        if(it.first!=maxmax) printf(" ");
    }
    return 0;
}


2、对key排序，然后找最小的priority来gen树，主要是depth_first
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
struct nod{
    nod *l=NULL, *r=NULL;
    int key, pri;
};
nod nd;
int cnt = 0, maxmax = -999999999;
vector<nod> v;
map<int, int> levkey, levpri;
nod* recursion(int l, int r, nod *rot, int index) {
    if(l > r) return NULL;
    if(rot==NULL) {
        rot = new(nod);
    }
    int ind, minmin = 999999999;
    for(int i = l; i <= r; i++) {
        if(minmin > v[i].pri) {
            minmin = v[i].pri;
            ind = i;
        }
    }
    rot->l = recursion(l, ind - 1, rot->l, 2*index + 1);
    levkey[index] = v[ind].key;
    levpri[index] = v[ind].pri;
    if(maxmax < index) maxmax = index;
    rot->r = recursion(ind+1, r, rot->r, 2*index + 2);
    return rot;
}
bool cmp(nod &a, nod &c) {
    return a.key < c.key;
}
int main(void) {
    int i, j, k, m, n, N, M, K, num;
    cin>>N;
    nod *rot = NULL;
    for(i = 0; i < N; i++) {
        cin>>nd.key>>nd.pri;
        v.push_back(nd);
    }
    sort(v.begin(), v.end(), cmp);
    rot = recursion(0, N-1, rot, 0);
    for(auto it:levkey) {
        printf("%d", it.second);
        if(it.first!=maxmax) printf(" ");
    }
    printf("\n");
    for(auto it:levpri) {
        printf("%d", it.second);
        if(it.first!=maxmax) printf(" ");
    }
    return 0;
}
