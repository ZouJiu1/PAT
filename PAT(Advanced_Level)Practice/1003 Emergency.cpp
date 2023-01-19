/*
堆优化迪杰特斯拉版本1 Dijkstra algorithm  
不用邻接表，节省了内存的
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int, int> p;
priority_queue<p, vector<p>, greater<p>> pq;
int status[505], dis[505], num[505], sam[505], rescue[505], inf = 999999999;
vector<p> v[505];


int main(void) {
    int i, j, k, m, n, z, x, y, c1, c2;
    cin>>n>>m>>c1>>c2;
    p x1, x2, x3, x4, x5, x6, t;
    for(i = 0; i < n; i++) {
        cin>>k;
        num[i] = k;
    }
    for(i = 0; i < m; i++) {
        cin>>y>>z>>k;
        x6.second = z;
        x6.first = k;
        v[y].push_back(x6);
        x6.second = y;
        v[z].push_back(x6);
    }
    fill(status, status + 505, 0);
    fill(dis,    dis    + 505, inf);
    fill(sam,    sam    + 505, 0);
    fill(rescue, rescue + 505, 0);
    t.first = 0;
    t.second = c1;
    dis[c1] = 0;
    sam[c1] = 1;
    rescue[c1] = num[c1];
    pq.push(t);
    int d1, d2;
    while(!pq.empty()) {
        x6 = pq.top();
        pq.pop();
        x = x6.second;
        d1 = x6.first; ///////////////////////
        if(status[x] > 0) continue;
        status[x] = 1;
        for(i = 0; i < v[x].size(); i++) {
            x2 = v[x][i];
            y = x2.second;
            d2 = x2.first;
            if(status[y]==0 && dis[y] > dis[x] + d2) {
                dis[y] = dis[x] + d2;
                pq.push({dis[y], y});
                sam[y] = sam[x];
                rescue[y] = rescue[x] + num[y];
            } else if(status[y]==0 && dis[y] == dis[x] + d2) {
                sam[y] = sam[x] + sam[y];
                if(rescue[y] < rescue[x] + num[y]) {
                    rescue[y] = rescue[x] + num[y];
                }
            }
        }
    }
    printf("%d %d\n", sam[c2], rescue[c2]);
    return EXIT_SUCCESS;
}

//堆优化迪杰特斯拉版本2 Dijkstra algorithm 
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int status[505], dis[505], num[505], rescue[505], inf = 999999999, cnt = 0, c1, c2;
typedef pair<int, int> p;
vector<p> v[505];
vector<int> pth[505];
priority_queue<p, vector<p>, greater<p>> pq;
void recursion(int end) {
    if(end==c1) cnt++;
    for(int i = 0; i < pth[end].size(); i++) {
        recursion(pth[end][i]);
    }
}
int main(void) {
    int i, j, k, m, n, z, x, y;
    cin>>n>>m>>c1>>c2;
    p x1, x2, x3, x4, x5, x6, t;
    for(i = 0; i < n; i++) {
        cin>>k;
        num[i] = k;
    }
    for(i = 0; i < m; i++) {
        cin>>x>>y>>z;
        x6.second = y;
        x6.first = z;
        v[x].push_back(x6);
        x6.second = x;
        v[y].push_back(x6);
    }
    fill(status, status + 505, 0);
    fill(dis,    dis    + 505, inf);
    fill(rescue, rescue + 505, 0);
    dis[c1] = 0;
    rescue[c1] = num[c1];
    x6.first = 0;
    x6.second = c1;
    pq.push(x6);
    int distance;
    while(!pq.empty()) {
        x6 = pq.top();
        pq.pop();
        x = x6.second;
        if(status[x]==1) continue;
        status[x] = 1;
        for(i = 0; i < v[x].size(); i++) {
            y = v[x][i].second;
            distance = v[x][i].first;
            if(status[y]==0 && dis[y] > dis[x] + distance) {
                dis[y] = dis[x] + distance;
                rescue[y] = rescue[x] + num[y];
                pq.push({dis[y], y});
                pth[y].clear();
                pth[y].push_back(x);
            } else if(status[y]==0 && dis[y] == dis[x] + distance) {
                pth[y].push_back(x);
                if(rescue[y] < rescue[x] + num[y]) {
                    rescue[y] = rescue[x] + num[y];
                }
            }
        }
    }
    recursion(c2);
    printf("%d %d\n", cnt, rescue[c2]);
    return EXIT_SUCCESS;
}

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
