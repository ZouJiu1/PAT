update
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int i, j, k, z1, z2, mat[505][505], cw[505][505], status[505], dis[505], cost[505], pre[505];
int inf = 999999999, cities, highway, start, en, minmin, sum1 = 0, sum2 = 0;
int main(void) {
    cin>>cities>>highway>>start>>en;
    fill(mat[0], mat[0] + 505 * 505, inf);
    fill(cw[0], cw[0] + 505 * 505, inf);
    fill(status, status + 505, 0);
    fill(dis, dis+505, inf);
    fill(cost, cost+505, inf);
    dis[start] = 0;
    cost[start] = 0;
    for(i = 0; i < highway; i++) {
        cin>>j>>k>>z1>>z2;
        mat[j][k] = mat[k][j] = z1;
        cw[j][k] = cw[k][j] = z2;
    }
    for(i = 0; i < cities; i++) {
        minmin = inf;
        for(j = 0; j < cities; j++) {
            if(status[j]==0&&minmin > dis[j]) {
                minmin = dis[j];
                k = j;
            }
        }
        status[k] = 1;
        for(j = 0; j < cities; j++) {
            if(status[j]==0&&dis[j] > dis[k] + mat[k][j]){
                pre[j] = k;
                dis[j] = dis[k] + mat[k][j];
                cost[j] = cost[k] + cw[k][j];
            }else if(status[j]==0&&dis[j] == dis[k] + mat[k][j]&& cost[j] > cost[k] + cw[k][j]) {
                pre[j] = k;
                dis[j] = dis[k] + mat[k][j];
                cost[j] = cost[k] + cw[k][j];
            }
        }
    }
    k = en;
    vector<int> v;
    while(pre[k]!=start){
        v.push_back(k);
        k = pre[k];
    }
    v.push_back(k);
    v.push_back(start);
    reverse(v.begin(), v.end());
    for(i = 0; i < v.size()-1; i++) {
        cout<<v[i]<<" ";
        sum1 += mat[v[i]][v[i+1]];
        sum2 += cw[v[i]][v[i+1]];
    }
    cout<<v[v.size()-1]<<" "<<sum1<<" "<<sum2<<endl;
    return 0;
}

old before
/*迪杰特斯拉方式，要注意距离相同时，要判断costes并保存相应的路径 */
#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char **argv){
    int N, M, S, D, i, j, k, m, n, minmin;
    cin>>N>>M>>S>>D;
    int INFINF = 999999;
    int cityhighway[N][N];
    int costes[N][N];
    memset((void *)cityhighway, INFINF,  sizeof(int) * N * N);
    memset((void *)costes,      INFINF,  sizeof(int) * N * N);
    int status[N];
    int way[N];
    int dis[N];
    int cos[N];
    memset((void *)cos, INFINF, sizeof(int) * N);
    memset((void *)dis, INFINF, sizeof(int) * N);
    memset((void *)status, 0, sizeof(int) * N);
    for(i = 0; i < M; i++){
        cin>>m>>n>>k>>j;
        cityhighway[m][n]=cityhighway[n][m]=k;
        costes[n][m]=costes[m][n]=j;
    }
    dis[S] = 0;
    cos[S] = 0;
    way[S] = S;
    status[S] = 0;
    for(i = 0; i < N; i++){
        minmin = 999998;
        for(j = 0; j < N; j++){
            if(minmin > dis[j] && status[j]==0){
                minmin = dis[j];
                k = j;
            }
        }
        status[k] = 1;
        for(j = 0; j < N; j++){
            if((minmin + cityhighway[k][j]) < dis[j] && status[j]==0){
                dis[j] = minmin + cityhighway[k][j];
                cos[j] = cos[k] + costes[k][j];
                way[j] = k;
            }else if((minmin + cityhighway[k][j]) == dis[j] && status[j]==0){
                if((cos[k] + costes[k][j]) < cos[j]){
                    dis[j] = minmin + cityhighway[k][j];
                    cos[j] = cos[k] + costes[k][j];
                    way[j] = k;
                }
            }
        }
    }
    vector<int> pth;
    k = way[D];
    pth.push_back(D);
    while(k!=S){
        pth.push_back(k);
        k = way[k];
    }
    pth.push_back(S);
    reverse(pth.begin(), pth.end());
    for(i = 0; i < pth.size(); i++) cout<<pth[i]<<" ";
    cout<<dis[D]<<" "<<cos[D];
    return EXIT_SUCCESS;
}
