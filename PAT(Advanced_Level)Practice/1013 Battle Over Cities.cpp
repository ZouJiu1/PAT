/*
共存在N个城市，这里存在了M条highway，求K个城市任何一个失陷以后，要使得N个城市互相连通，不是两两连通，所以是图的问题，图的某一个节点失效以后，求让其他节点连通，最少要连几条边

这里可以使用并查集解决，也可以使用DFS解决，或者BFS来解决，核心在于找出某一个节点失效以后，其他的节点能组成多少颗树，对于并查集，只要看根节点的个数就可以了；DFS则是看树的个数，也可以说是根节点个数，两者相等的

连通集的最少连通边数是节点数 - 1，这里就是根节点个数（树个数）- 1 
*/
update202302   depth_first
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v[100006];
bool status[100006];
void recursion(int tat, int no) {
    if(tat==no||status[tat]==true) return;
    status[tat] = true;
    for(int i = 0; i < v[tat].size(); i++) {
        recursion(v[tat][i], no);
    }
}
int main(void) {
    int i, j, k, m, n, N, M, K, y, z, sum;
    cin>>N>>M>>K;
    for(i = 0; i < M; i++) {
        cin>>y>>z;
        v[y].push_back(z);
        v[z].push_back(y);
    }
    for(i = 0; i < K; i++) {
        cin>>y;
        fill(status, status + 100006, false);
        sum = 0;
        for(j = 1; j <= N; j++) {
            if(j==y) continue;
            if(status[j]==false) {
                recursion(j, y);
                sum++;
            }
        }
        printf("%d\n", sum-1);
    }
    return 0;
}

update202302 并查集
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[1000006], v[1000006][2];
int findfather(int a) {
    int tmp = a;
    while(a!=arr[a]) a=arr[a];
    arr[tmp] = a;
    return a;
}
void unionjoin(int a, int c) {
    int aa = findfather(a);
    int cc = findfather(c);
    if(aa > cc) arr[aa] = cc;    //correct
    else arr[cc] = aa;
    /*
    if(aa > cc) arr[a] = cc;     //wrong
    else arr[c] = aa;
    11 2    unionjoin(11, 2)
    11 --> 2
    11 3    unionjoin(11, 3)
    11 --> 2 <-- 3
    1 3     unionjoin(1 , 3)
    1 <-- 3  and    11 --> 2
    */
}
int main(void) {
    int i, j, k, m, n, N, M, K, y, z, sum;
    cin>>N>>M>>K;
    for(i = 0; i < M; i++) cin>>v[i][0]>>v[i][1];
    for(i = 0; i < K; i++) {
        cin>>y;
        for(j = 0; j < 1000006; j++) arr[j] = j;
        sum = 0;
        for(j = 0; j < M; j++) {
            if(v[j][0] == y || v[j][1] == y) continue;
            unionjoin(v[j][0], v[j][1]);
        }
        for(j = 1; j <= N; j++) {
            if(j==y) continue;
            if(j==arr[j]) sum++;
        }
        printf("%d\n", sum - 1);
    }
    return 0;
}


old before
并查集：
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int joinfind[1003]={0};
vector<int> g[1003];

int getfather(int a){
    int tmp = a;
    while(joinfind[a]!=a) a = joinfind[a]; //表的路径压缩
    joinfind[tmp] = a;
    return a;
}

void uniones(int a, int b){
    int x = getfather(a);
    int y = getfather(b);
    if(x==y) return;
    joinfind[x] = y;
}

//并查集
int main(void){
    int a, b, c, d, e, f;
    cin>>a>>b>>c;
    for(int i=0; i<b; i++){
        cin>>d>>e;
        g[d].push_back(e);
        g[e].push_back(d);
    }
    vector<int> vr;
    for(int i=0; i<c; i++){
        cin>>f;
        vr.push_back(f);
    }
    int sit[a+1], cnt;
    for(int i=0; i<c; i++){
        f = vr[i];
        cnt = 0;
        for(int j = 1; j < a + 1; j++){  //initialization
            joinfind[j] = j;
        }
        for(int d=0; d<a; d++){
            if(d==f) continue;
            for(int j = 0; j < g[d].size(); j++){
                if(g[d][j]==f) continue;
                uniones(d, g[d][j]);
            }
        }
        set<int> st;
        for(int j=1; j<a+1; j++){
            if(j==f) continue;
            e = getfather(j);
            st.insert(e);
        }
        cout<<st.size()-1<<endl;
    }
    return 0;
}
=======================================================================================================================
DFS：

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int joinfind[1003][1003]={0};
int visited[1003]={0};
int a;

void dfs(int x){
    visited[x] = 1;
    for(int i=1; i<a+1; i++){
        if(visited[i]==0&&joinfind[x][i]==1) dfs(i);
    }
}

//DFS
int main(void){
    int b, c, d, e, f;
    cin>>a>>b>>c;
    for(int i=0; i<b; i++){
        cin>>d>>e;
        joinfind[d][e] = 1;
        joinfind[e][d] = 1;
    }
    int cnt;
    for(int i=0; i<c; i++){
        cin>>f;
        cnt = 0;
        memset((void *)visited, 0, sizeof(int)*1003);
        visited[f] = 1;
        for(int j=1; j<a+1; j++){
            if(visited[j]==0){
                dfs(j);
                cnt++;
            }
        }
        cout<<cnt-1<<endl;
    }
    return 0;
}
=======================================================================================================================
BFS

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int joinfind[1003][1003]={0};
int visited[1003]={0};
int a;

void BFS(int x){
    vector<int> vt;
    vt.push_back(x);
    int i;
    while(vt.size()>0){
        i = vt[0];
        visited[i] = 1;
        vt.erase(vt.begin());
        for(int j=1; j<a+1; j++){
            if(visited[j]==0&&joinfind[i][j]==1){
                vt.push_back(j);
            }
        }
    }
}

//BFS
int main(void){
    int b, c, d, e, f;
    cin>>a>>b>>c;
    for(int i=0; i<b; i++){
        cin>>d>>e;
        joinfind[d][e] = 1;
        joinfind[e][d] = 1;
    }
    int cnt;
    for(int i=0; i<c; i++){
        cin>>f;
        cnt = 0;
        memset((void *)visited, 0, sizeof(int)*1003);
        visited[f] = 1;
        for(int j=1; j<a+1; j++){
            if(visited[j]==0){
                BFS(j);
                cnt++;
            }
        }
        cout<<cnt-1<<endl;
    }
    return 0;
}
