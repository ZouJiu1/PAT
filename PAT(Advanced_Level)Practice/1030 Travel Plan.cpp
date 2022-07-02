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
