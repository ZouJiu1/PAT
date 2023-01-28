perfect binary tree是完全满二叉树，complete binary tree是完全二叉树，都是层序遍历的最后index和节点的个数相等
perfect binary tree最后一层的个数=pow(2, 最后一层层数)；
complete binary tree最后一层的个数<pow(2, 最后一层层数)
  
pseudo-complete binary tree层序遍历最后index > 节点的个数，最后一层不是依次从左到右填充的；
others从根节点到倒数第二层，存在不满的的情况，也就是pow(2，第几层)!=该层节点数

#include<iostream>
#include<cmath>
using namespace std;
int in[2006], pre[2006], pot[2006], lev[2006], maxind = -999999999, cnt = 0, maxlev = -999999999;
void recursion(int prel, int inl, int inr, int index, int level) {
    if(inl > inr) return;
    lev[level]++;
    if(maxind < index) maxind = index;
    if(maxlev < level) maxlev = level;
    int kk = inl;
    while(kk <= inr && pre[prel]!=in[kk]) kk++;
    recursion(prel + 1, inl, kk - 1, index * 2 + 1, level + 1);
    recursion(prel + (kk - inl + 1), kk+1, inr, index * 2 + 2, level + 1);
    pot[cnt++] = pre[prel];
}
int main(void) {
    int i, j, k, m, n;
    cin>>n;
    for(i = 0; i < n; i++) scanf("%d", &in[i]);
    for(i = 0; i < n; i++) scanf("%d", &pre[i]);
    recursion(0, 0, n - 1, 0, 0);
    if(maxind==n-1) { //2 or 1
        if((int)pow(2, maxlev)==lev[maxlev]) printf("1\n");
        else printf("2\n");
    }else{ //3 or 0
        int mr = -9;
        for(i = 0; i < maxlev; i++) {
            if((int)pow(2, i)!=lev[i]){
                mr = 9;
                break;
            }
        }
        if(mr<0) printf("3\n");
        else printf("0\n");
    }
    for(i = 0; i < cnt; i++) {
        printf("%d", pot[i]);
        if(i!=cnt - 1) printf(" ");
    }
    return 0;
}
