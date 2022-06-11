
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
