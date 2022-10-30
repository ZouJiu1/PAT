update

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int m, cnt = 0;
int v[1001], level[1001];
void inorder(int ind) {
    if(ind >= m) return;
    inorder(2 * ind + 1);
    level[ind] = v[cnt++];
    inorder(2 * ind + 2);
}
int main(void){
    int i, j, k, n;
    cin>>m;
    for(i = 0; i < m; i++) scanf("%d", &v[i]);
    sort(v, v+m);
    inorder(0);
    printf("%d", level[0]);
    for(i = 1; i < m; i++) printf(" %d", level[i]);
    return 0;
}

old before
/*
完全二叉树和二叉搜索树，使用等比数列的计算公式，排序以后去掉最后一层的元素个数，其他的最middle的就是输出节点，不要构建树的，

i. 给出的数据是完全二叉树的，完全二叉树的节点都是满的，除了最后一层可以不满员

ii. 最后一层的最右侧节点只有一个值时，只能在左侧节点，因为题目说了要从左至右填充
*/
#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

struct nod{
    int l;
    int r;
    nod *nexted;
};
vector<int> v0;
void findroot(vector<int> v, int n, int cnt){
    vector<vector<int>> v00;
    int maxval;
    v00.push_back(v);
    while(v00.size()!=0){
        v = v00[0];
        n = v.size();
        v00.erase(v00.begin());
        if(n==2) {
            maxval = max(v[0], v[1]);
            v0.push_back(maxval);
            vector<int> ll;
            ll.push_back(min(v[0], v[1]));
            v00.push_back(ll);
            continue;
        }
        int layerceil, layerfloor;
        if(log2((float)n+1.0) - (int)log2((float)n+1.0)!=0.0){
            layerceil  = ceil(log2((float)n+1.0));
            layerfloor = floor(log2((float)n+1.0));
        }
        else{
            layerceil  = log2((float)n+1.0);
            layerfloor = log2((float)n+1.0);
        }
        int numceil = (int)pow(2, layerceil) - 1;
        int numfloor = (int)pow(2, layerfloor) - 1;
        int lastl = (int)pow(2, layerceil - 1);
        int ind;
        if(layerceil!=layerfloor){
            if(n - numfloor > lastl/2){
                ind = (numfloor-1)/2 + lastl/2;
            }else{
                ind = (numfloor-1)/2 + n - numfloor;
            }
        }else{
            ind = (numfloor-1)/2;
        }
        vector<int> l, r;
        l = v; 
        r = v;
        l.erase(l.begin() + ind, l.end());
        r.erase(r.begin(), r.begin() + ind + 1);
        v0.push_back(v[ind]);
        if(l.size()!=0)
            v00.push_back(l);
        if(r.size()!=0)
            v00.push_back(r);
    }
    for(int i = 0; i< v0.size(); i++){
        printf("%d", v0[i]);
        if(i!=v0.size() - 1) cout<<" ";
    }
}

int main(void){
    int i, j, m, n, x, y, k, w;
    cin>>n;
    vector<int> v;
    for(i = 0; i < n; i++){
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    findroot(v, n, 0);
    return 0;
}
