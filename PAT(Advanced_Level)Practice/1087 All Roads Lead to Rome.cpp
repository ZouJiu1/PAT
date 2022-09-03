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
