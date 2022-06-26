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
