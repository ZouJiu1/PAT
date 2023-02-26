/*
关键路径找到earliest发生时间和最迟发生时间相等的节点路径
使用递推关系，第183页，先求出拓扑排序和逆拓扑排序
《数据结构（C语言版）qing华大学出版社》
*/
/*      
inputs：  9个顶点也就是9个事件，11个边就是11个活动
9 11
1 2 6
1 3 4
2 5 1
3 5 1
5 7 9
5 8 7
7 9 2
8 9 4
1 4 5
4 6 2
6 8 4
*/
/*
output: 1 2 5 7 9
*/
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
struct nod{int y, tim;};
int main(int argc, char **argv) {
    int i, j, m, n, y, z, k, status[1001];
    cin>>m>>n;
    vector<nod> arr[1001], revarr[1001];
    vector<int> res, rev, tmp(1001), earlytim(1001), lasttim(1001);
    fill(tmp.begin(), tmp.begin() + 1001, 0);
    earlytim = tmp;
    lasttim = tmp;
    fill(status, status + 1001, 0);
    nod nd;
    unordered_map<int, int> ump;
    for(i = 0; i < n; i++) {
        cin>>y>>nd.y>>nd.tim;
        arr[y].push_back(nd);
        tmp[nd.y] += 1;                  //入度
        ump[y + nd.y * 1000] = ump[y * 1000 + nd.y] = nd.tim;
    }
    int point;
    while(res.size()!=m) { //求出拓扑序列
        for(i = 1; i <= m; i++) {
            if(tmp[i]==0 && status[i]==0) {
                status[i] = 1;
                res.push_back(i);
                for(j = 0; j < arr[i].size(); j++) {
                    point = arr[i][j].y;
                    tmp[point]--;
                    if(earlytim[point] < earlytim[i] + ump[i*1000 + point])
                        earlytim[point] = earlytim[i] + arr[i][j].tim;
                }
                break;
            }
        }
    }
    lasttim[res[m - 1]] = earlytim[res[m - 1]];
    for(i = m - 2; i >= 0; i--) {
        int minmin = 999999999;
        k = res[i];
        for(j = 0; j < arr[k].size(); j++) { //k之后的不固定
            point = arr[k][j].y;
            minmin = min(minmin, lasttim[point] - ump[k * 1000 + point]);
        }
        lasttim[k] = minmin;
    }
    vector<int> v;
    for(i = 1; i <= m; i++) {
        if(lasttim[i]==earlytim[i]) {
            v.push_back(i);
        }
    }

    printf("%d", v[0]);
    for(i = 1; i < v.size(); i++) 
        if(ump[v[i-1]*1000 + v[i]]!=0) printf(" %d", v[i]);
    return EXIT_SUCCESS;
}

update202301
#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;
int status[1006], deg[1006];
struct nod{
    int b, e, v;
};
int main(void) {
    int i, j, ij, k, N, M, x, y, z, inf = 999999999;
    cin>>N>>M;
    vector<int> tmp, vk, res, earlytime(1006, 0), lasttime(1006, inf);
    vector<nod> v[1006];
    nod nd;
    map<int, int> mp;
    for(i = 0; i < M; i++) {
        cin>>nd.b>>nd.e>>nd.v;
        v[nd.b].push_back(nd);
        v[nd.e].push_back(nd);
        mp[nd.b*10000+nd.e] = mp[nd.e*10000+nd.b] = 1;
        deg[nd.e]++;
    }
    while(vk.size()!=N) {
        for(i = 1; i <= N; i++) {
            if(status[i]==0&&deg[i]==0) {
                for(j = 0; j < v[i].size(); j++) {
                    deg[v[i][j].e]--;
                    earlytime[v[i][j].e] = max(earlytime[v[i][j].e], earlytime[v[i][j].b] + v[i][j].v);
                }
                vk.push_back(i);
                status[i] = 1;
            }
        }
    }
    lasttime[N] = earlytime[N];
    fill(status, status + 1006, 0);
    for(z = vk.size() - 1; z >= 0; z--) {
        i = vk[z];
        for(j = 0; j < v[i].size(); j++) {
            lasttime[v[i][j].b] = min(lasttime[v[i][j].b], lasttime[v[i][j].e] - v[i][j].v);
        }
    }
    for(i = 1; i <= N; i++) {
        if(lasttime[i]==earlytime[i]) {
            res.push_back(i);
        }
    }
    printf("%d", res[0]);
    for(i = 1; i < res.size(); i++) {
        if(mp[res[i]*10000+res[i-1]]==0) continue;
        printf(" %d", res[i]);
    }
    return 0;
}
