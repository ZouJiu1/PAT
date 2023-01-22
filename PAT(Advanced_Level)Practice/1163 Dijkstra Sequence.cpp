update2
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
    int i, j, m, n, x, y, k, w, inf = 999999999;
    vector<int> matrix[1006], kk(1006, inf);
    for(i = 0; i < 1006; i++) matrix[i] = kk;
    int status[1006], dis[1006];
    cin>>m>>n;
    for(i = 0; i < n; i++) {
        cin>>x>>y>>k;
        matrix[x][y] = matrix[y][x] = k;
    }
    cin>>k;
    vector<int> v[1006];
    for(x = 0; x < k; x++) {
        for(w = 0; w < m; w++) {
            cin>>y;
            v[x].push_back(y);
        }
    }
    for(x = 0; x < k; x++) {
        fill(status, status + 1006, 0);
        fill(dis,    dis + 1006,    inf);
        int ind = 0, minmin, ver, kk, mr;
        dis[v[x][0]] = 0;
        for(j = 1; j <= m; j++) {
            mr = -9, minmin = inf;
            for(i = 1; i <= m; i++) {
                if(status[i]==0 && minmin > dis[i]) {
                    minmin = dis[i];
                    ver = i;
                    if(i==v[x][ind]) mr = 9;
                    else mr = -9;
                } else if (status[i]==0 && minmin !=inf && minmin==dis[i]) {
                    if(i==v[x][ind]) mr = 9;
                }
            }
            if(mr<0) {
                printf("No\n");
                break;
            }
            ver = v[x][ind];
            status[ver] = 1;
            for(i = 1; i <= m; i++) {
                if(status[i]==0 && dis[i] > dis[ver] + matrix[ver][i]) {
                    dis[i] = dis[ver] + matrix[ver][i];
                }
            }
            ind++;
        }
        if(mr>0) printf("Yes\n");
    }
    return 0;
}

update1 堆优化
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int, int> p;
p r0, r1, r2;
int status[1006], dis[1006], inf = 999999999;
int main(void) {
    int i, j, k, m, n, Nv, Ne, K, x, y, z, tan0, ind;
    cin>>Nv>>Ne;
    vector<p> v[1006];
    for(i = 0; i < Ne; i++) {
        cin>>k>>m>>n;
        r0.first = n;
        r0.second = m;
        v[k].push_back(r0);
        r0.second = k;
        v[m].push_back(r0);
    }
    cin>>K;
    for(i = 0; i < K; i++) {
        vector<int> tmp(Nv);
        for(j = 0; j < Nv; j++) scanf("%d", &tmp[j]);
        fill(dis, dis + 1006, inf);
        dis[tmp[0]] = 0;
        fill(status, status + 1006, 0);
        r0.first = 0;
        r0.second = tmp[0];
        priority_queue<p, vector<p>, greater<p>> pq, pqc;
        pq.push(r0);
        ind = 0;
        int mr;
        while(!pq.empty()) {
            r0 = pq.top();
            pqc = pq;
            if(status[r0.second]==1) {
                pq.pop();
                continue;
            }
            mr = -9;
            if(r0.second==tmp[ind]) {
                status[r0.second] = 1;
                mr = 9;
                pq.pop();
            }
            while(!pqc.empty() && mr < 0) {
                r1 = pqc.top();
                if(r1.first!=r0.first) break;
                pqc.pop();
                if(r1.first == r0.first && tmp[ind]==r1.second) {
                    mr = 9;
                    status[r1.second] = 1;
                    break;
                }
            }
            if(mr < 0) break;
            for(j = 0; j < v[tmp[ind]].size(); j++) {
                r1 = v[tmp[ind]][j];
                y = r1.second;
                tan0 = r1.first;
                if(status[y]==0 && dis[y] > dis[tmp[ind]] + tan0) {
                    dis[y] = dis[tmp[ind]] + tan0;
                    pq.push({dis[y], y});
                }
            }
            ind++;
        }
        if(mr > 0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

old before
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(void) {
    int i, j, m, n, x, y, k, w;
    vector<vector<int>> matrix;
    int infinf = (int)pow(2, 31) - 6;
    matrix.resize(1006);
    for(i = 0; i < 1006; i++) matrix[i].resize(1006);
    cin>>m>>n;
    for(i = 0; i < n; i++) {
        cin>>x>>y>>k;
        matrix[x][y] = matrix[y][x] = k;
    }
    cin>>k;
    vector<vector<int>> v;
    v.resize(k);
    for(x = 0; x < k; x++) {
        for(w = 0; w < m; w++) {
            cin>>y;
            v[x].push_back(y);
        }
    }
    for(x = 0; x < k; x++) {
        bool status[1006] = {false};
        int sum[1006], cnt = 0, exi;
        for(i = 0; i < 1006; i++) sum[i] = infinf;
        sum[v[x][0]] = 0;
        int minmin, ind, mr;
        for(i = 1; i <= m; i++) {
            minmin = infinf - 1;
            exi = v[x][cnt];
            for(j = 1; j <=m; j++) {
                if(status[j]==false && sum[j] <= minmin) {
                    if(sum[j] < minmin) {
                        if(j==exi)
                            mr = 9;
                        else mr = -9;
                    }else if(sum[j]==minmin && j==exi) mr = 9;
                    minmin = sum[j];
                }
            }
            if(mr < 0) {
                printf("No\n");
                break;
            }
            cnt++;
            status[exi] = true;
            for(j = 1; j <=m; j++) {
                if(status[j]==false && sum[j] > sum[exi] + matrix[exi][j] && matrix[exi][j]!=0) {
                    sum[j] = sum[exi] + matrix[exi][j];
                }
            }
            mr = 9;
        }
        if(mr > 0) printf("Yes\n");
    }
    return 0;
}
