update202301
#include<iostream> 
using namespace std;
int pre[31], pot[31], unique = 1, in[31], cnt=0;
struct nod {nod *l=NULL, *r=NULL; int val;};
void recursionv1(int prel, int prer, int potl, int potr) { //前序第二个划开  根左右
    if(prel > prer || potl > potr) return;
    if(pre[prel]!=pot[potr]){
        printf("can not gen\n");
        return;
    }
    if(prel==prer) {
        in[cnt++] = pre[prel];
        return;
    }
    int kk = potl;
    while(kk <= potr && pre[prel+1]!=pot[kk]) kk++;
    if(kk > potr) {
        printf("can not gen\n");
        return;
    }
    if(potr - kk > 1) {
        recursionv1(prel + 1, prel + (kk - potl + 1), potl, kk);
        in[cnt++] = pre[prel];
        recursionv1(prel + (kk - potl + 2), prer, kk+1, potr-1);
    }else {
        unique = -1;
        recursionv1(prel + 1, prel + (kk - potl + 1), potl, kk);
        in[cnt++] = pre[prel];
    }
}
// void recursionv2(int prel, int prer, int potl, int potr) { //前序第二个划开  根左右
//     if(prel > prer || potl > potr) return;
//     if(pre[prel]!=pot[potr]){
//         printf("can not gen\n");
//         return;
//     }
//     if(prel==prer) {
//         in[cnt++] = pre[prel];
//         return;
//     }
//     int kk = prel;
//     while(kk <= prer && pre[kk]!=pot[potr - 1]) kk++;
//     if(kk > prer) {
//         printf("can not gen\n");
//         return;
//     }
//     if(kk - prel > 1) {
//         recursionv2(prel+1, kk-1, potl, potl + (kk - prel - 2));
//         in[cnt++] = pre[prel];
//         recursionv2(kk, prer, potl + (kk-prel-1), potr - 1);
//     }else {
//         unique = -1;
//         recursionv2(kk, prer, potl + (kk-prel-1), potr - 1);
//         in[cnt++] = pre[prel];
//     }
// }
int main() {
    int i, j, k, m, n;
    cin>>m;
    for(i = 0; i < m; i++) cin>>pre[i];
    for(i = 0; i < m; i++) cin>>pot[i];
    recursionv1(0, m-1, 0, m-1);
    // recursionv2(0, m-1, 0, m-1);
    if(unique > 0) printf("Yes\n");
    else printf("No\n");
    for(i = 0; i < cnt; i++) {
        printf("%d", in[i]);
        if(i!=cnt-1) printf(" ");
    }
    printf("\n");
}

//输出层序遍历节点
//generate tree
#include<iostream> 
#include<queue>
#include<vector>
using namespace std;
int pre[31], pot[31], unique = 1, in[31], cnt=0;
struct nod {nod *l=NULL, *r=NULL; int val;};
nod *recursion(nod *rot, int prel, int prer, int potl, int potr) {
    if(prel>prer||potl>potr) return NULL;
    if(rot==NULL) {
        rot=new(nod);
        rot->val = pot[potr];
    }
    if(prel==prer) {
        // rot->val = pot[potr];
        return rot;
    }
    if(pre[prel]==pot[potr]){
        int k = pre[prel + 1], ll=potl;    
        while(ll <= potr && pot[ll]!=k) ll++; //前序第二个，划开左右子树(包括自身倒数第二个)
        if(potr - ll > 1) {
            rot->l = recursion(rot->l, prel+1, prer - (potr - ll - 1), potl, ll);
        }else{
            unique = 0;
            rot->l = recursion(rot->l, prel+1, prer - (potr - ll - 1), potl, ll);
        }
        rot->r = recursion(rot->r, prer - (potr - ll - 1) + 1, prer, ll+1, potr - 1);
    }else{
        //这两个序列不能产生一棵树
    }
    return rot;
}

int main() {
    int i, j, k, m, n;
    cin>>m;
    for(i = 0; i < m; i++) cin>>pre[i];
    for(i = 0; i < m; i++) cin>>pot[i];
    nod *rot=NULL;
    rot = recursion(rot, 0, m-1, 0, m-1);
    if(unique) printf("Yes\n");
    else printf("No\n");
    queue<nod *> q;
    q.push(rot);
    vector<int> v;
    while(q.size()!=0){
        nod *tmp = q.front();
        if(tmp->l!=NULL) q.push(tmp->l);
        if(tmp->r!=NULL) q.push(tmp->r);
        v.push_back(tmp->val);
        q.pop();
    }
    printf("%d", v[0]);
    for(i = 1; i < v.size(); i++) printf(" %d", v[i]);
    printf("\n");
    return EXIT_SUCCESS;
}

//方式二
