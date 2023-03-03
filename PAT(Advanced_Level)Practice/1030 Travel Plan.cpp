堆优化2
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
using namespace std;
typedef pair<int, int> p;
priority_queue<p, vector<p>, greater<p>> pq;
p r0, r1, r2;
unordered_map<int, int> ump;
int main(void) {
    int i, j, k, m, n, x, y, z, N, M, S, D, sum = 0, status[505], dit[505], cot[505], inf = 999999999;
    cin>>N>>M>>S>>D;
    int tmpend = D;
    vector<p> v[505];
    for(i = 0; i < M; i++) {
        cin>>x>>y>>z>>m;
        r0.first = z;
        r0.second = y;
        v[x].push_back(r0);
        r0.second = x;
        v[y].push_back(r0);
        ump[x * 1000 + y] = ump[y * 1000 + x] = m;
    }
    fill(status, status + 505, 0);
    fill(cot, cot + 505, 0);
    fill(dit, dit + 505, inf);
    dit[S] = 0;
    r0.first = 0;
    r0.second = S;
    pq.push(r0);
    vector<int> pth[505], res;
    while(!pq.empty()) {
        r0 = pq.top();
        pq.pop();
        x = r0.second;
        if(status[x]==1) continue;
        status[x] = 1;
        for(i = 0; i < v[x].size(); i++) {
            r1 = v[x][i];
            y = r1.second;
            z = r1.first;
            if(status[y]==0 && dit[y] > dit[x] + z) {
                dit[y] = dit[x] + z;
                pq.push({dit[y], y});
                cot[y] = cot[x] + ump[x*1000 + y];
                pth[y].clear();
                pth[y].push_back(x);
            }else if(status[y]==0 && dit[y] == dit[x] + z && cot[y] > cot[x] + ump[x*1000 + y]) {
                cot[y] = cot[x] + ump[x*1000 + y];
                pth[y].clear();
                pth[y].push_back(x);
            }
        }
    }
    while(true) {
        res.push_back(D);
        if(D==S) break;
        D = pth[D][0];
    }
    for(int i = res.size() - 1; i >= 0; i--) {
        printf("%d ", res[i]);
        if(i!=0) sum += ump[res[i]*1000 + res[i-1]];
    }
    printf("%d %d\n", dit[tmpend], sum);
    return 0;
}

堆优化1
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
using namespace std;
typedef pair<int, int> p;
priority_queue<p, vector<p>, greater<p>> pq;
p r0, r1, r2;
vector<int> pth[505], res, tmp;
unordered_map<int, int> ump;
int minmin = 999999999;
void recursion(int start, int end) {
    tmp.push_back(end);
    if(end==start) {
        int cot = 0;
        for(int i = tmp.size() - 1; i > 0; i--) {
            cot += ump[tmp[i] * 1000 + tmp[i-1]];
        }
        if(cot < minmin) {
            minmin = cot;
            res = tmp;
        }
        tmp.pop_back();
        return;
    }
    for(int i = 0; i < pth[end].size(); i++) {
        recursion(start, pth[end][i]);
    }
    tmp.pop_back();
}
int main(void) {
    int i, j, k, m, n, x, y, z, N, M, S, D, status[505], dit[505], inf = 999999999;
    cin>>N>>M>>S>>D;
    vector<p> v[505];
    for(i = 0; i < M; i++) {
        cin>>x>>y>>z>>m;
        r0.first = z;
        r0.second = y;
        v[x].push_back(r0);
        r0.second = x;
        v[y].push_back(r0);
        ump[x * 1000 + y] = ump[y * 1000 + x] = m;
    }
    fill(status, status + 505, 0);
    fill(dit, dit + 505, inf);
    dit[S] = 0;
    r0.first = 0;
    r0.second = S;
    pq.push(r0);
    while(!pq.empty()) {
        r0 = pq.top();
        pq.pop();
        x = r0.second;
        if(status[x]==1) continue;
        status[x] = 1;
        for(i = 0; i < v[x].size(); i++) {
            r1 = v[x][i];
            y = r1.second;
            z = r1.first;
            if(status[y]==0 && dit[y] > dit[x] + z) {
                dit[y] = dit[x] + z;
                pq.push({dit[y], y});
                pth[y].clear();
                pth[y].push_back(x);
            }else if(status[y]==0 && dit[y] == dit[x] + z) {
                pth[y].push_back(x);
            }
        }
    }
    recursion(S, D);
    for(int i = res.size() - 1; i >= 0; i--) printf("%d ", res[i]);
    printf("%d %d\n", dit[D], minmin);
    return 0;
}

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

update202303
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
typedef pair<int, int> p;
priority_queue<p, vector<p>, greater<p>> pq;
unordered_map<int, int> ump0, ump1;
p p0, p1, p2;
vector<p> v[600], v1[600];
int tat[600], dit[600], cot[600], inf = 999999999, pre[600];
int main(void) {
    int i, j, k, n, m, N, M, K, x, z, y, S, D;
    cin>>N>>M>>S>>D;
    fill(dit, dit + 600, inf);
    fill(cot, cot + 600, inf);
    for(i = 0; i < M; i++) {
        cin>>m>>n>>y>>z;
        v[m].push_back({y, n});
        v[n].push_back({y, m});
        v1[m].push_back({z, n});
        v1[n].push_back({z, m});
    }
    dit[S] = 0;
    cot[S] = 0;
    pq.push({0, S});
    while(!pq.empty()) {
        p0 = pq.top();
        pq.pop();
        x = p0.second;
        if(tat[x]==1) continue;
        tat[x] = 1;
        for(i = 0; i < v[x].size(); i++) {
            p1 = v[x][i];
            y = p1.second;
            z = p1.first;
            if(tat[y]==0 && dit[y] > dit[x] + z) {
                dit[y] = dit[x] + z;
                pq.push({dit[y], y});
                cot[y] = cot[x] + v1[x][i].first;
                pre[y] = x;
            } else if(tat[y]==0 && dit[y] == dit[x] + z) {
                if(cot[y] > cot[x] + v1[x][i].first) {
                    dit[y] = dit[x] + z;
                    cot[y] = cot[x] + v1[x][i].first;
                    pre[y] = x;
                }
            }
        }
    }
    vector<int> v;
    m = D;
    while(true) {
        v.push_back(m);
        if(m==S) break;
        m = pre[m];
    }
    reverse(v.begin(), v.end());
    for(i = 0; i < v.size(); i++) printf("%d ", v[i]);
    printf("%d %d\n", dit[D], cot[D]);
    return 0;
}


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int mat[600][600], mat0[600][600], tat[600], dit[600], cot[600], inf = 999999999, pre[600];
int main(void) {
    int i, j, k, n, m, N, M, K, x, z, y, S, D;
    fill(mat[0], mat[0] + 600 * 600, inf);
    fill(mat0[0], mat0[0] + 600 * 600, inf);
    cin>>N>>M>>S>>D;
    fill(dit, dit + 600, inf);
    fill(cot, cot + 600, inf);
    dit[S] = 0;
    cot[S] = 0;
    for(i = 0; i < M; i++) {
        cin>>m>>n>>y>>z;
        mat[m][n] = mat[n][m] = y;
        mat0[m][n] = mat0[n][m] = z;
    }
    for(i = 0; i < N; i++) {
        int minmin = inf;
        for(j = 0; j < N; j++) {
            if(tat[j]==0 && minmin > dit[j]) {
                n = j;
                minmin = dit[j];
            }
        }
        tat[n] = 1;
        for(j = 0; j < N; j++) {
            if(tat[j]==0 && dit[j] > dit[n] + mat[n][j]) {
                dit[j] = dit[n] + mat[n][j];
                cot[j] = cot[n] + mat0[n][j];
                pre[j] = n;
            } else if(tat[j]==0 && dit[j] == dit[n] + mat[n][j]) {
                if(cot[j] > cot[n] + mat0[n][j]) {
                    dit[j] = dit[n] + mat[n][j];
                    cot[j] = cot[n] + mat0[n][j];
                    pre[j] = n;
                }
            }
        }
    }
    vector<int> v;
    m = D;
    while(true) {
        v.push_back(m);
        if(m==S) break;
        m = pre[m];
    }
    reverse(v.begin(), v.end());
    for(i = 0; i < v.size(); i++) printf("%d ", v[i]);
    printf("%d %d\n", dit[D], cot[D]);
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
