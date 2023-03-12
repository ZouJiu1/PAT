/*
考试的时候最后一题花了近两个小时，然后最后一个测试点3分没有做出来，后来又花了一个上午的时间，
还是没找到reason。判断是否对称要层序遍历，存在节点就vec保存1，不存在vec保存0，若是该层的vec在reverse前后都相等，就是对称的。
判断是否是tree of love，要depth_first保存叶子节点，然后进行判断。
输出的Outer contour，保存叶子节点要放在最前面，然后是最左侧的节点，最后是后序遍历的最右侧节点。
最左侧和最右侧使用节点的地址是否是该层层序遍历的第一个和最后一个来判断，以及不要重复使用unordered_map来记录是否访问过。
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>
using namespace std;
int in[100006], pot[100006], pre[100006], nextlevel;
struct nod{
    nod *l = NULL, *r = NULL;
    int val;
};
nod *recursion(nod *rot, int postroot, int inl, int inr) {
    if(inl > inr) return NULL;
    if(rot==NULL) {
        rot = new(nod);
        rot->val = pot[postroot];
    }
    int ind = inl;
    while(ind <= inr && in[ind]!=pot[postroot]) ind++;
    rot->l = recursion(rot->l, postroot - (inr - ind+1), inl, ind - 1);
    rot->r = recursion(rot->r, postroot - 1, ind + 1, inr);
    return rot;
}
struct nod2{
    nod *nd;
    int level;
};
vector<int> v[100006], v0[100006];
vector<nod *> vk[100006];
unordered_map<int, int> ump;
unordered_map<nod *, int> rev;
bool width_first_symmetric(nod *rot){
    queue<nod2> q;
    q.push({rot, 0});
    nod2 nd2;
    v[0].push_back(1);
    v0[0].push_back(1);
    vk[0].push_back(rot);
    ump[rot->val] = 0;
    rev[rot] = 0;
    while(!q.empty()) {
        nd2 = q.front();
        ump[nd2.nd->val] = nd2.level;
        rev[nd2.nd] = nd2.level;
        nextlevel = nd2.level+1;
        q.pop();
        if(nd2.nd->l!=NULL) {
            v[nextlevel].push_back(1);
            v0[nextlevel].insert(v0[nextlevel].begin(), 1);
            vk[nextlevel].push_back(nd2.nd->l);
            q.push(nod2{nd2.nd->l, nextlevel});
        }else{
            v[nextlevel].push_back(0);
            v0[nextlevel].insert(v0[nextlevel].begin(), 0);
            vk[nextlevel].push_back(NULL);
        }
        if(nd2.nd->r!=NULL) {
            v[nextlevel].push_back(1);
            v0[nextlevel].insert(v0[nextlevel].begin(), 1);
            vk[nextlevel].push_back(nd2.nd->r);
            q.push(nod2{nd2.nd->r, nextlevel});
        }else{
            v[nextlevel].push_back(0);
            v0[nextlevel].insert(v0[nextlevel].begin(), 0);
            vk[nextlevel].push_back(NULL);     
        }
    }
    int kk = 9;
    for(int i = 0; i < 100006; i++) {
        if(v0[i]!=v[i]) {
            kk = -9;
            break;
        }
    }
    if(kk < 0) return false;
    else return true;
}
vector<int> vec, leaves, lev;
unordered_map<nod *, bool> tat;
void depth_first(nod* rot) {
    int level = rev[rot];
    if(rot->l==NULL && rot->r==NULL) {
        if(tat[rot]==false) {
            vec.push_back(rot->val);
            lev.push_back(level);
        }
        tat[rot] = true;
        return;
    }
    if(rot==vk[level][0]) {
        if(tat[rot]==false) vec.push_back(rot->val);
        tat[rot] = true;
    }
    if(rot->l!=NULL) depth_first(rot->l);
    if(rot->r!=NULL) depth_first(rot->r);
    if(rot==vk[level][vk[level].size() - 1]) {
        if(tat[rot]==false) vec.push_back(rot->val);
        tat[rot] = true;
    }
}
bool judge_treelove(){
    int ll = 0, y, z, w, len = lev.size(), kl = 9;
    if(ll+1 < len && lev[ll+1] < lev[ll]) kl = -9;
    while(ll < len && lev[ll] >= lev[ll-1]) ll++;
    y = ll;
    if(y < len && lev[y] > lev[y-1]) kl = -9;
    while(y < len && lev[y] <= lev[y-1]) y++;
    z = y;
    if(z < len && lev[z] < lev[z-1]) kl = -9;
    while(z < len && lev[z] >= lev[z-1]) z++;
    w = z;
    if(w < len && lev[w] > lev[w-1]) kl = -9;
    while(w < len && lev[w] <= lev[w-1]) w++;
    if(w <= len && kl > 0) return true;
    else return false;
}
int main(void) {
    int i, N;
    cin>>N;
    nod nd, *rot=NULL;
    for(i = 0; i < N; i++) scanf("%d", &in[i]);
    for(i = 0; i < N; i++) scanf("%d", &pot[i]);
    rot = recursion(rot, N-1, 0, N-1);
    bool symmetric = width_first_symmetric(rot);
    depth_first(rot);
    bool treelove = judge_treelove();
    if(treelove==true && symmetric==true) printf("Yes\n");
    else printf("No\n");
    for(i = 0; i < vec.size(); i++) printf("%d%s", vec[i], i==(vec.size()-1)?"":" ");
    return 0;
}
