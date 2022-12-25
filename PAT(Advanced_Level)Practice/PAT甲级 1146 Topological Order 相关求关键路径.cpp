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

        k = nd.y;
        nd.y = y;
        revarr[k].push_back(nd); 
    }
    while(res.size()!=m) { //求出拓扑序列
        for(i = 1; i <= m; i++) {
            if(tmp[i]==0 && status[i]==0) {
                status[i] = 1;
                res.push_back(i);
                for(j = 0; j < arr[i].size(); j++) {
                    tmp[arr[i][j].y]--;
                }
                break;
            }
        }
    }
    rev = res;
    reverse(rev.begin(), rev.end());
    earlytim[res[0]] = 0;
    for(i = 1; i < m; i++) {
        int maxmax = -999999;
        k = res[i];
        for(j = 0; j < revarr[k].size(); j++) { //k之前的不固定 earlytim[revarr[k][j].y]
            maxmax = max(maxmax, earlytim[revarr[k][j].y] + ump[k * 1000 + revarr[k][j].y]);
        }
        earlytim[k] = maxmax;
    }
    lasttim[res[m - 1]] = earlytim[res[m - 1]];
    for(i = m - 2; i >= 0; i--) {
        int minmin = 999999999;
        k = res[i];
        for(j = 0; j < arr[k].size(); j++) { //k之后的不固定
            minmin = min(minmin, lasttim[arr[k][j].y] - ump[k * 1000 + arr[k][j].y]);
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
