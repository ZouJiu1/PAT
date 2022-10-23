update
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int mat[600][600], status[600], dis[600], res[600], people[600];
vector<int> pre[600];
int inf = 999999999, cnt = 0, en, start;
void dfs(int end) {
    if(end==start) cnt++;
    for(int i =0; i < pre[end].size(); i++) 
        dfs(pre[end][i]);
}
int main(void){
    int i, j, k, m, n, city, road, minmin;
    cin>>city>>road>>start>>en;
    for(i = 0; i < city; i++) scanf("%d", &res[i]);
    fill(mat[0], mat[0]+600*600, inf);
    for(i = 0; i < road; i++) {
        cin>>m>>n>>k;
        mat[m][n] = mat[n][m] = k;
    }
    fill(status, status+600, 0);
    fill(dis, dis+600, inf);
    fill(people, people+600, inf);
    dis[start] = 0;
    people[start] = res[start];
    for(i = 0; i < city; i++) {
        minmin = inf;
        for(j = 0; j < city; j++) {
            if(status[j]==0&&dis[j] < minmin) {
                minmin = dis[j];
                k = j;
            }
        }
        status[k] = 1;
        for(j = 0; j < city; j++) {
            if(status[j]==0&&dis[j] > dis[k] + mat[k][j]) {
                dis[j] = dis[k] + mat[k][j];
                pre[j].clear();
                pre[j].push_back(k);
                people[j] = people[k] + res[j];
            }else if(status[j]==0&&dis[j] == dis[k] + mat[k][j]) {
                pre[j].push_back(k);
                if(people[j] < people[k] + res[j])
                    people[j] = people[k] + res[j];
            }
        }
    }
    dfs(en);
    cout<<cnt<<" "<<people[en];
    return 0;
}

old before
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>
/*
Dijkstra algorithm
*/
using namespace std;

int main(void){
    int i, j, n, m, a, c, num, num0, num2, min;
    cin>>n>>m>>a>>c;
    int ci[n];
    int infff = 2139062143;
    int mat[n][n]={infff};
    memset((void *)mat, infff, sizeof(int)*n*n);
    int dis[n], nu[n], w[n];
    bool final[n]={false};
    memset((void *)dis, infff, sizeof(int)*n);
    for(i=0; i<n; i++){
        cin>>num;
        ci[i] = num;
    }
    for(i=0; i<m; i++){
        cin>>num0>>num>>num2;
        mat[num][num0] = mat[num0][num] = num2;
    }
    dis[a] = 0;
    w[a] = ci[a];
    nu[a] = 1;
    for(i=0; i<n; i++){
        min = infff;
        int u = -1;
        for(j=0; j<n; j++) 
            if(final[j]==false&&dis[j]<min){
                u = j; 
                min = dis[j];
            }//closest point
        final[u] = true;
        if(u==-1) break;
        for(j=0; j<n; j++){   //closest point
            if(final[j]==true||mat[u][j]==infff) continue;
            if((min+mat[u][j])<dis[j]){
                dis[j] = min + mat[u][j];
                nu[j] = nu[u];
                w[j] = ci[j] + w[u];
            }else if((min+mat[u][j])==dis[j]){
                nu[j] = nu[j] + nu[u];
                if(w[j]<(w[u] + ci[j]))
                    w[j] = ci[j] + w[u];
            }
        }
    }
    cout<<nu[c]<<" "<<w[c];
    return 0;
}
