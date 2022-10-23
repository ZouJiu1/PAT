update
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int mat[600][600], tim[600], status[600], bike[600], minmin, inf=999999999;
int minback=inf, minneed=inf, cap, ts, rn, sp, perfect;
vector<int> pre[600], tmppath, minpath;
void dfs(int p) {
    int i, j;
    tmppath.push_back(p);
    if(p==0) {
        int bac = 0, nee = 0;
        for(i = tmppath.size()-2; i >= 0; i--) {
            if(perfect - bike[tmppath[i]] < 0) {
                bac += -(perfect - bike[tmppath[i]]);
            }else{
                if(bac - (perfect - bike[tmppath[i]]) > 0)
                    bac = bac - (perfect - bike[tmppath[i]]);
                else {
                    nee += perfect - bike[tmppath[i]] - bac;
                    bac = 0;
                }
            }
        }
        if(minneed > nee || (minneed==nee && minback > bac)) {
            minneed = nee;
            minback = bac;
            minpath = tmppath;
        }
        tmppath.pop_back();
        return;
    }
    for(j = 0; j < pre[p].size(); j++)
        dfs(pre[p][j]);
    tmppath.pop_back();
}
int main(void) {
    int i, j, k, m, n, y, z;
    cin>>cap>>ts>>sp>>rn;
    perfect = cap/2;
    fill(mat[0], mat[0]+600*600, inf);
    for(i = 1; i <= ts; i++) scanf("%d", &bike[i]);
    for(i = 0; i < rn; i++) {
        scanf("%d %d %d", &m, &n, &z);
        mat[m][n] = mat[n][m] = z;
    }
    fill(tim, tim+600, inf);
    fill(status, status+600, 0);
    tim[0] = 0;
    for(i = 0; i < ts+1; i++) {
        minmin = inf;
        for(j = 0; j < ts+1; j++) {
            if(status[j]==0&&minmin > tim[j]) {
                minmin = tim[j];
                y = j;   
            }
        }
        status[y] = 1;
        for(j = 0; j < ts+1; j++) {
            if(status[j]==0 && tim[j] > tim[y] + mat[y][j]) {
                tim[j] = tim[y] + mat[y][j];
                pre[j].clear();
                pre[j].push_back(y);
            } else if (status[j]==0 && tim[j]==tim[y] + mat[y][j])
                pre[j].push_back(y);
        }
    }
    dfs(sp);
    cout<<minneed<<" ";
    for(i = minpath.size()-1; i >=0; i--) {
        cout<<minpath[i];
        if(i!=0) cout<<"->";
    }
    cout<<" "<<minback<<endl;
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

using namespace std;

int main(){
    int C, N, Sp, M, i, j, a, b , c, d, e, cap, minnum;
    cin>>C>>N>>Sp>>M;
    cap = C/2;
    int nowbikes[N + 1] = {0};
    int waypath[N+1][N+1];
    memset((void *)waypath, 9999999, sizeof(int) * (N+1) * (N+1));
    for(i = 0; i < N; i++) cin>>nowbikes[i + 1];
    for(i = 0; i < M; i++){
        cin>>a>>b>>c;
        waypath[b][a] = waypath[a][b] = c;
    }
    int mindis[N + 1] = {9999999};
    memset((void *)mindis, 9999999, sizeof(int) * (N + 1));
    int sumbike[N + 1];
    int visited[N + 1] = {0};
    int points[N + 1];
    mindis[0] = 0;
    sumbike[0] = 0;
    points[0] = 0;
    int vec[N + 1] = {0};
    for(i = 0; i < N + 1; i++){
        minnum = 9999999;
        for( j = i; j < N + 1; j++){
            if(mindis[j] < minnum && visited[j]==0){
                minnum = mindis[j];
                d = j;
            }
        }
        visited[d] = 1;
        for( j = 0; j < N + 1; j++){
            if((minnum + waypath[d][j]) < mindis[j] && visited[j]==0){
                mindis[j] = minnum + waypath[d][j];
                vec[j] = d;
                points[j] = points[d] + 1;
                sumbike[j] = sumbike[d] + nowbikes[j];
            }else if((minnum + waypath[d][j]) == mindis[j] && visited[j]==0){
                a = (points[d] + 1) * cap;
                if(a <= (sumbike[d] + nowbikes[j])){
                    if((sumbike[d] + nowbikes[j]) <= sumbike[j]){
                        sumbike[j] = sumbike[d] + nowbikes[j];
                        mindis[j] = minnum + waypath[d][j];
                        vec[j] = d;
                        points[j] = points[d] + 1;
                    }
                }else if(a > (sumbike[d] + nowbikes[j])){
                    if((sumbike[d] + nowbikes[j]) > sumbike[j]){
                        sumbike[j] = sumbike[d] + nowbikes[j];
                        mindis[j] = minnum + waypath[d][j];
                        vec[j] = d;
                        points[j] = points[d] + 1;
                    }
                }else{
                    sumbike[j] = sumbike[d] + nowbikes[j];
                    mindis[j] = minnum + waypath[d][j];
                    vec[j] = d;
                    points[j] = points[d] + 1;
                }
            }
        }
    }
    a = vec[Sp];
    vector<int> vr{Sp};
    vr.push_back(a);
    while(a!=0){
        a = vec[a];
        vr.push_back(a);
    }
    reverse(vr.begin(), vr.end());
    a = sumbike[Sp];
    b = points[Sp] * cap;
    if(a>=b) cout<<0<<" ";
    else cout<<(b-a)<<" ";
    for(i = 0; i < vr.size(); i++){
        cout<<vr[i];
        if(i!=(vr.size() - 1)) cout<<"->";
    }
    if(a>=b) cout<<" "<<(a-b);
    else cout<<" "<<0;
    return 0;
}
