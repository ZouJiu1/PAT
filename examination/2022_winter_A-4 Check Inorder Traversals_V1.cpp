/*
考试之前没接触过不能产生树的条件，然后就不知道怎么做了，看了相应的内容，不能产生树的reason很多，主要是index越界、前序第一个和后序最后一个不相等；
而且对树不是unique也不太了解，不unique主要是子节点只有一个导致的，判断条件就是划开的index和左右边界的距离要>=2，也就是保证存在两个子节点，遍历顺序是前序：根左右，后序：左右根
*/
//通过后序的倒数第二个划开前序左右branch，倒数第二个给右branch
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
int pre[36], poster[36], in[36], m, n, que[36], notree=0, mustkid = 0;
vector<int> pv, chk, tmp;
void prepost(int prel, int prer, int potl, int potr) {
    if(pre[prel]!=poster[potr]){  //判断前序第一个和后序最后一个是否相等，来判断是否可以产生树，要放在最前面
        notree = 1;
        return;
    }
    if(prel==prer){
        // tmp.push_back(pre[prel]);    //保存inorder
        return;
    }
    int ll = prel, k = poster[potr - 1];   //通过后序的倒数第二个划开前序左右branch，倒数第二个给右branch
    while(ll<=prer && pre[ll]!=k) ll++;    //后序，左节点-右节点-根节点，
    if(ll>prer){
        notree = 1;
        return;
    }
    if(ll - prel > 1) {
        prepost(prel+1, ll-1, potl, potl + (ll - prel - 1) - 1); //左branch
    }else{//not unique，不是独一无二的树，可能存在某个节点只有一个子节点，该子节点可能在左也可能在右
    }
    // tmp.push_back(pre[prel]);    //保存inorder
    prepost(ll, prer, potl + (ll - prel - 1), potr - 1);    //右branch
}

// void prepost(int prel, int prer, int potl, int potr) {
//     if(prel>prer||potl>potr||notree==1){ //可能存在越界的情况
//         return;
//     }
//     if(pre[prel]!=poster[potr]){ //判断前序第一个和后序最后一个是否相等，来判断是否可以产生树，要放在最前面
//         notree = 1;
//         return;
//     }
//     if(prel==prer){                                            //要放到后面的
//         // if(prel==prer) tmp.push_back(pre[prel]);   //保存inorder
//         return;
//     }
//     //通过前序的第二个划开后序左右branch，第二个给左branch
//     int ll = potl, k = pre[prel + 1];
//     while(ll<=potr && poster[ll]!=k) ll++;
//     if(ll>potr){
//         notree = 1;
//         return;
//     }
//     if(potr - ll > 1) {
//         prepost(prel+1, prel+(ll - potl) + 1, potl, ll);  //左branch
//     }else{//not unique，不是独一无二的树，可能存在某个节点只有一个子节点，该子节点可能在左也可能在右
//         prepost(prel+1, prel+(ll - potl) + 1, potl, ll);
//     }
//     // tmp.push_back(pre[prel]);    //保存inorder
//     prepost(prel+(ll-potl)+2, prer, ll+1, potr-1);   //右branch
// }

void prein(int start, int l, int r) {
    if(l > r) return;
    int ll = l, k = pre[start];
    while(ll<=r && que[ll]!=k) ll++;
    if(ll<=r){
        prein(start + 1, l, ll - 1);
        prein(start + (ll - l) + 1, ll + 1, r);
        pv.push_back(k);
    }else{  //判断是否越界
        mustkid = 1;
        return;
    }
}

int main() {
    //1 2 3 4 6 7 5  preorder
    //2 6 7 4 5 3 1  postorder
    //2 1 6 4 7 3 5  inorder
    int i, j, k, y, z;
    cin >> m;
    for (i = 1; i <= m; i++) {
        cin >> pre[i];
    }
    for (i = 1; i <= m; i++) {
        cin >> poster[i];
        chk.push_back(poster[i]);
    }
    cin >> n;
    prepost(1, m, 1, m);
    if(notree) printf("Are you kidding me?\n");
    for (j = 1; j <= n; j++) {
        pv.clear();
        mustkid = 0;  //初始化
        for (i = 1; i <= m; i++) cin >> que[i];
        prein(1, 1, m);
        if(notree) {
            if(mustkid) {
                printf("You must be kidding me!\n");
                continue;
            }
            printf("%d", pv[0]);
            for(int ij = 1; ij < pv.size(); ij++) printf(" %d", pv[ij]);
            printf("\n");
        }else {
            if(pv==chk) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}

update20230226
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int pre[36], pot[36], in[36], tre = 9, tretwo = 9;
vector<int> postorder, posttwo;
void recursion(int pel, int per, int ptl, int ptr) {
    if(pel > per || ptl > ptr || tre < 0) return;
    if(pre[pel]!=pot[ptr]) {
        tre = -9;
        return;
    }
    if(pel == per) {
        //in.push_back(pre[pel]);
        return;
    }
    int ind = ptl;
    while(ind <= ptr && pot[ind]!=pre[pel+1]) ind++;
    if(ind > ptr) {
        tre = -9;
        return;
    }
    if(ind - ptl < 2) { //not unique
        recursion(pel + 1, pel + (ind - ptl) + 1, ptl, ind);
    } else {
        recursion(pel + 1, pel + (ind - ptl) + 1, ptl, ind);
    }
    //in.push_back(pre[pel]);
    recursion(pel + (ind - ptl) + 2, per, ind + 1, ptr-1);
}
void preinorder(int tat, int inl, int inr) {
    if(inl > inr || tretwo < 0) return;
    int ind = inl;
    while(ind <= inr && in[ind]!=pre[tat]) ind++;
    if(ind > inr) {
        tretwo = -9;
        return;
    }
    preinorder(tat + 1, inl, ind - 1);
    preinorder(tat + ind - inl +1, ind + 1, inr);
    posttwo.push_back(pre[tat]);
}
int main(void) {
    int i, j, k, n, m, M, N, K, x, y, z, endkk, start, cnt = 0;
    cin>>N;
    for(i = 0; i < N; i++) scanf("%d", &pre[i]);
    for(i = 0; i < N; i++) {
        scanf("%d", &pot[i]);
        postorder.push_back(pot[i]);
    }
    cin>>K;
    recursion(0, N-1, 0, N-1);
    if(tre < 0) printf("Are you kidding me?\n");
    for(i = 0; i < K; i++) {
        tretwo = 9;
        posttwo.clear();
        for(j = 0; j < N; j++) scanf("%d", &in[j]);
        preinorder(0, 0, N-1);
        if(tre < 0) {
            if(tretwo < 0) {
                printf("You must be kidding me!\n");
            } else {
                for(j = 0; j < N; j++) printf("%d%s", posttwo[j], j==N-1 ? "\n":" ");
            }
        } else {
            if(postorder==posttwo) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
