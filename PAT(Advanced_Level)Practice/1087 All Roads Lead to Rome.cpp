update2
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
int citys, roads, start, rom, cnt = 0, happiness[206], inf = 999999999;
int counts = 0;
int matrix[206][206], status[206], hap[206], nod[206], cost[206], pre[206];
float avghap[206];
unordered_map<int, string> ump;
unordered_map<string, int> rev_ump;
vector<int> route[206], fin;
string t, t1;
void recursion(int citys) {
    if(citys==0) counts++;
    for(int i = 0; i < route[citys].size(); i++) {
        recursion(route[citys][i]);
    }
}
int main(int argc, char **argv) {
    cin>>citys>>roads>>t;
    ump[0] = t;
    rev_ump[t] = 0;
    int i, j, k, m, n;
    for(i = 1; i < citys; i++) {
        cin>>t>>happiness[i];
        if(t=="ROM") rom = i;
        ump[i] = t;
        rev_ump[t] = i;
    }
    fill(matrix[0], matrix[0]+206*206, inf);
    fill(status, status+206, 0);
    fill(nod, nod+206, 0);
    fill(hap, hap+206, inf);
    fill(cost, cost+206, inf);
    fill(avghap, avghap+206, 0.0);
    for(i = 0; i < roads; i++) {
        cin>>t>>t1>>m;
        matrix[rev_ump[t]][rev_ump[t1]]=matrix[rev_ump[t1]][rev_ump[t]] = m;
    }
    hap[0] = 0;
    cost[0] = 0;
    avghap[0] = 0;
    for(i = 0; i < citys; i++) {
        int minmin = inf;
        for(j = 0; j < citys; j++) {
            if(status[j]==0&&minmin > cost[j]){
                minmin = cost[j];
                m = j;
            }
        }
        status[m] = 1;
        for(j = 0; j < citys; j++) {
            if(status[j]==0&&cost[j] > cost[m]+matrix[m][j]){
                cost[j] = cost[m]+matrix[m][j];
                nod[j] = nod[m] + 1;
                hap[j] = hap[m] + happiness[j];
                avghap[j] = hap[j]/(float)nod[j];
                route[j].clear();
                route[j].push_back(m);
                pre[j] = m;
            }else if(status[j]==0&&cost[j] == cost[m]+matrix[m][j]){
                if(hap[j] < hap[m] + happiness[j]){
                    cost[j] = cost[m]+matrix[m][j];
                    nod[j] = nod[m] + 1;
                    hap[j] = hap[m] + happiness[j];
                    avghap[j] = hap[j]/(float)nod[j];
                    pre[j] = m;
                }else if(hap[j] == hap[m] + happiness[j]){
                    if(avghap[j] < ((hap[m] + happiness[j])/(float)(nod[m] + 1)) ) {
                        cost[j] = cost[m]+matrix[m][j];
                        nod[j] = nod[m] + 1;
                        hap[j] = hap[m] + happiness[j];
                        avghap[j] = hap[j]/(float)nod[j];
                        pre[j] = m;
                    }
                }
                route[j].push_back(m);
            }
        }
    }
    recursion(rom);
    printf("%d %d %d %d\n", counts, cost[rom], hap[rom], (int)(avghap[rom]));
    n = rom;
    while(pre[n]!=0) {
        fin.push_back(n);
        n = pre[n];
    }
    fin.push_back(n);
    fin.push_back(0);
    reverse(fin.begin(), fin.end());
    cout<<ump[fin[0]];
    for(i = 1; i < fin.size(); i++) cout<<"->"<<ump[fin[i]];
    return EXIT_SUCCESS;
}

update1
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
int i, j, k, m, n, x1, x2, x3, x4, x5, cnt=0, minmin, mat[209][209], hap[209], pre[209];
int status[209], nodnum[209], cost[209], hapsum[209], inf = 999999999, num = 0;
string t1, t2, t3;
unordered_map<string, int> mp, mp_h;
unordered_map<int, string> rmp;
vector<int> allpre[209];
void dfs(int point) {
    if(point==0) {
        num++;
        return;
    }
    for(int ij = 0; ij < allpre[point].size(); ij++) {
        dfs(allpre[point][ij]);
    }
}
int main(void) {
    fill(hap, hap + 209, inf);
    fill(mat[0], mat[0] + 209 * 209, inf);
    fill(status, status+209, 0);
    fill(cost, cost+209, inf);
    fill(hapsum, hapsum+209, inf);
    cin>>m>>n>>t3;
    rmp[cnt] = t3;
    mp[t3] = cnt++;
    for(i = 0; i < m-1; i++) {
        cin>>t2>>x1;
        mp[t2] = cnt;
        rmp[cnt++] = t2;
        mp_h[t2] = x1;
    }
    for(i = 0; i < n; i++) {
        cin>>t1>>t2>>x1;
        mat[mp[t1]][mp[t2]] = mat[mp[t2]][mp[t1]] = x1;
    }
    cost[0] = 0;
    hapsum[0] = 0;
    for(i = 0; i < m; i++) {
        minmin = inf;
        for(j = 0; j < m; j++) {
            if(status[j]==0&&minmin > cost[j]) {
                minmin = cost[j];
                x2 = j;
            }
        }
        status[x2] = 1;
        for(j = 0; j < m; j++) {
            if(status[j]==1) continue;
            if (cost[j] == cost[x2] + mat[x2][j]) allpre[j].push_back(x2);
            if(cost[j] > cost[x2] + mat[x2][j]) {
                cost[j] = cost[x2] + mat[x2][j];
                pre[j] = x2;
                nodnum[j] = nodnum[x2] + 1;
                hapsum[j] = hapsum[x2] + mp_h[rmp[x2]];
                allpre[j].clear();
                allpre[j].push_back(x2);
            }
            else if (cost[j] == cost[x2] + mat[x2][j] && hapsum[j] < hapsum[x2] + mp_h[rmp[x2]]) {
                cost[j] = cost[x2] + mat[x2][j];
                pre[j] = x2;
                nodnum[j] = nodnum[x2] + 1;
                hapsum[j] = hapsum[x2] + mp_h[rmp[x2]];
            } else if (cost[j] == cost[x2] + mat[x2][j] && hapsum[j] == hapsum[x2] + mp_h[rmp[x2]] && 
                        hapsum[j]/(float)nodnum[j] < (hapsum[x2] + mp_h[rmp[x2]])/(float)(nodnum[x2]+1)) {
                cost[j] = cost[x2] + mat[x2][j];
                pre[j] = x2;
                nodnum[j] = nodnum[x2] + 1;
                hapsum[j] = hapsum[x2] + mp_h[rmp[x2]];
            }
        }
    }
    x1 = cost[mp["ROM"]];
    vector<int> res;
    dfs(mp["ROM"]);
    x2 = mp["ROM"];
    while(pre[x2]!=0){
        res.push_back(x2);
        x2 = pre[x2];
    }
    res.push_back(x2);
    res.push_back(0);
    reverse(res.begin(), res.end());
    int sum1 = 0, sum2 = 0;
    for(i = 0; i < res.size(); i++)
        sum1 += mp_h[rmp[res[i]]];
    cout<<num<<" "<<cost[mp["ROM"]]<<" "<<sum1<<" "<<sum1/nodnum[mp["ROM"]]<<endl;
    for(i = 0; i < res.size(); i++){
        cout<<rmp[res[i]];
        if(i!=res.size()-1) cout<<"->";
    }
    return 0;
}


before old
/*迪杰特斯拉，要添加额外的条件*/
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int i, j, k, mm, n, w, x, y, des;
    string s, s0, ss, sss;
    cin >> mm >> n >> s;
    const int m = 201;
    map<string, int> pairs;
    map<int, int> mp;
    map<int, string> rev;
    int infinf = 999999999;
    x = 0;
    pairs[s] = 0;
    rev[0] = s;
    for (i = 0; i < mm - 1; i++) {
        cin >> s0 >> w;
        pairs[s0] = ++x;
        rev[x] = s0;
        if (s0 == "ROM")
            des = x;
        mp[x] = w;
    }
    int matrix[m][m];
    for(i = 0; i < m; i++)
        for(j = 0; j < m; j++)
            matrix[i][j] = infinf;
    for (i = 0; i < n; i++) {
        cin >> ss >> sss >> x;
        matrix[pairs[sss]][pairs[ss]] = matrix[pairs[ss]][pairs[sss]] = x;
    }
    bool status[m];
    memset((void*)status, false, sizeof(bool) * m);
    int dis[m];
    int hap[m];
    int sam[m];
    int way[m];
    int pat[m];
    for(i=0; i<m; i++) dis[i] = infinf;
    memset((void*)hap, 0, sizeof(int) * m);
    for(i=0; i<m; i++) sam[i] = 1;
    memset((void*)way, 0, sizeof(int) * m);
    dis[0] = 0;
    hap[0] = 0;
    int minmin, nod;
    float avg0, avg1;
    for (i = 0; i < mm; i++) {
        minmin = infinf;
        for (j = 0; j < mm; j++) {
            if (status[j] == false && minmin > dis[j]) {
                nod = j;
                minmin = dis[j];
            }
        }
        status[nod] = true;
        for (j = 0; j < mm; j++) {
            if (status[j] == false && dis[j] > dis[nod] + matrix[nod][j]&&
                matrix[nod][j]<infinf) {
                dis[j] = dis[nod] + matrix[nod][j];
                hap[j] = hap[nod] + mp[j];
                way[j] = way[nod] + 1;
                pat[j] = nod;
            }
            else if (status[j] == false && dis[j] == dis[nod] + matrix[nod][j]&&
                matrix[nod][j]<infinf) {
                if (hap[j] < hap[nod] + mp[j]) {
                    dis[j] = dis[nod] + matrix[nod][j];
                    hap[j] = hap[nod] + mp[j];
                    way[j] = way[nod] + 1;
                    pat[j] = nod;
                }
                else if (hap[j] == hap[nod] + mp[j]) {
                    if (way[j] > (way[nod] + 1)) {
                        dis[j] = dis[nod] + matrix[nod][j];
                        hap[j] = hap[nod] + mp[j];
                        way[j] = way[nod] + 1;
                        pat[j] = nod;
                    }
                }
                sam[j] += 1;
            }
        }
    }
    cout << sam[des] << " " << dis[des] << " " << hap[des] << " " << hap[des] / way[des] << endl;
    vector<int> v;
    v.push_back(des);
    x = pat[des];
    while (true) {
        v.push_back(x);
        if(x==0) break;
        x = pat[x];
    }
    reverse(v.begin(), v.end());
    for (i = 0; i < v.size(); i++) {
        cout << rev[v[i]];
        if (i != v.size() - 1) cout << "->";
    }
    return 0;
}
