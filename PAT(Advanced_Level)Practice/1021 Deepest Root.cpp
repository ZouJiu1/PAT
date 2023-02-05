update202302   存在两端的最深节点个数都>1的情况
/*
6
1 2
1 3
1 4
2 5
2 6
*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
vector<int> v[10006];
bool status[10006];
int level[10006], maxmax = -999999999, ind;
void recursion(int ta, int lev) {
    status[ta] = true;
    level[ta] = lev;
    if(maxmax < lev) {
        ind = ta;
        maxmax = lev;
    }
    for(int i = 0; i < v[ta].size(); i++) {
        if(status[v[ta][i]]==false) recursion(v[ta][i], lev + 1);
    }
}
int main(void) {
    int i, j, k, m, n, N, M, K, y, z, sum=0;
    cin>>N;
    for(i = 0; i < N - 1; i++) {
        scanf("%d %d", &y, &z);
        v[y].push_back(z);
        v[z].push_back(y);
    }
    set<int> te;
    for(i = 1; i <= N; i++) {
        if(status[i]==false) {
            recursion(i, 1);  //找到一个相对“最深”的vertex 和 是否connected，找到某些最深的点
            sum++;
        }
    }
    if(sum!=1) {
        printf("Error: %d components\n", sum);
        return 0;
    }
    for(i = 1; i <= N; i++) {   //先放入某一端“最深”的点
        if(maxmax==level[i]) te.insert(i);
    }
    fill(status, status+10006, false);
    k = ind;
    maxmax = -999999999;
    recursion(k, 1);     //从相对“最深”的遍历，就可以拿到其他最深的点，然后拿到并集
    level[k] = maxmax;
    vector<int> v;
    for(i = 1; i <= N; i++) {
        if(maxmax==level[i]) te.insert(i);
    }
    for(auto it:te) printf("%d\n", it);
    return 0;
}


update
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int status[10001], maxmax = -999999999;
vector<int> v0[10001], tmp, res;
void recursion(int start, int depth) {
    if(maxmax < depth) {
        tmp.clear();
        tmp.push_back(start);
        maxmax = depth;
    } else if(maxmax==depth){
        tmp.push_back(start);
    }
    status[start] = 1;
    for(int i = 0; i < v0[start].size(); i++) {
        if(status[v0[start][i]]==0) {
            recursion(v0[start][i], depth + 1);
        }
    }
}
int main(void) {
    int i, j, k, m, N, y, z, cnt = 0;
    cin>>N;
    for(i = 0; i < N-1; i++) {
        cin>>y>>z;
        v0[y].push_back(z);
        v0[z].push_back(y);
    }
    fill(status, status + 10001, 0);
    set<int> kt;
    for(i = 1; i <= N; i++) {
        if(status[i]==0) {
            recursion(i, 1);
            cnt++;
            if(i==1) {
                if(tmp.size()!=0) z = tmp[0];
                for(j = 0; j < tmp.size(); j++)
                    kt.insert(tmp[j]);
            }
        }
    }
    if(cnt > 1) {
        printf("Error: %d components\n", cnt);
        return 0;
    }
    fill(status, status + 10001, 0);
    tmp.clear();
    maxmax = -999999999;
    recursion(z, 1);
    for(i = 0; i < tmp.size(); i++) {
        kt.insert(tmp[i]);
    }
    for(set<int>::iterator it=kt.begin(); it!=kt.end(); it++) {
        res.push_back(*it);
    }
    sort(res.begin(), res.end());
    printf("%d\n", res[0]);
    for(i = 1; i < res.size(); i++) printf("%d\n", res[i]);
    return 0;
}

old before
/*
并查集查看树的棵树；迪杰特斯拉方式寻找最远的路径
*/
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int finder(int *unionfind, int x){
    while(x!=unionfind[x]) x = unionfind[x];
    return x;
}

void unioner(int *unionfind, int x, int y){
    int a = finder(unionfind, x);
    int c = finder(unionfind, y);
    if(a > c)
        unionfind[y] = unionfind[x] = c;
    else
        unionfind[y] = unionfind[x] = a;
}

int main(void){
    int m, n, a, b, c, d, e, f;
    int INFINF = -999999;
    cin>>n;
    f = n + 1;
    int matrix[f][f];
    int unionsz[f];          //并查集查看树的棵数
    for(int i=0; i<f; i++) unionsz[i] = i;
    memset((void *)matrix, INFINF, sizeof(int) * f * f);
    for(int i = 0; i < (n - 1); i++){
        cin>>a>>b;
        matrix[b][a] = matrix[a][b] = 1;
        unioner(unionsz, a, b);
    }
    e = 0;
    for(int i = 1; i < f; i++){
        if(unionsz[i]==i) e++;
    }
    if(e!=1){
        printf("Error: %d components", e);
        return 0;
    }
    int maxdis[f][f];
    int visited[f][f];
    memset((void *)visited, 0, sizeof(int) * f * f);
    memset((void *)maxdis, INFINF, sizeof(int) * f * f);
    int maxval;
    for(c = 1; c < f; c++){ //迪杰特斯拉方式
        for(int i = 0; i < f; i++){
            maxval = -9999999;
            maxdis[c][c] = 0;
            m = 0;
            for(int j = 0; j < f; j++){
                if(maxdis[c][j] > maxval && visited[c][j]==0){
                    maxval = maxdis[c][j];
                    m = j;
                }
            }
            visited[c][m] = 1;
            for(int j = 0; j < f; j++){
                if((maxval + matrix[m][j]) > maxdis[c][j] && visited[c][j]==0){
                    maxdis[c][j] = maxval + matrix[m][j];
                }
            }
        }
    }
    maxval = -999999;
    for(int i = 0; i < f; i++){
        for(int j = 0; j < f; j++){
            if(maxdis[i][j] > maxval){
                maxval = maxdis[i][j];
            }
        }
    }
    vector<int> vr;
    for(int i = 0; i < f; i++){
        for(int j = 0; j < f; j++){
            if(maxdis[i][j] == maxval){
                vr.push_back(j);
            }
        }
    }
    vr.push_back(999999);
    sort(vr.begin(), vr.end());
    for(int i = 0; i < vr.size() - 1; i++){
        if(vr[i+1]==vr[i]) continue;
        else cout<<vr[i]<<endl;
    }
    return 0;
}
