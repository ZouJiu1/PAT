#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> vtr;
vector<int> power, v;
int w, n, m, maxmax = -999999;

void dfs(vector<int> v, int sum, int depth, int start) {
    int k, i, tmp, tmp1;
    for(i = start; i >= 1; i--) {
        k = power[i] + sum;
        if (k<=m) {
            tmp = sum + (n - depth + 1) * power[i];
            tmp1 = sum + (n - depth + 1);
            if(tmp < m) return;
            if(tmp1 > m) return;
            if(k==m&&depth == n){
                v.push_back(i);
                vtr.push_back(v);
                return;
            }
            else {
                v.push_back(i);
                dfs(v, k, depth + 1, i);
                v.pop_back();
            }
        }
    }
    return;
}

int main(void) {
    int i, j, x = -9;
    cin>>m>>n>>w;
    power.resize(m + 1);
    for(int i = m; i >= 1; i--) {
        power[i] = (int)pow(i, w);
        if(power[i] > m || x > 0) continue;
        else x = i;
    }
    dfs(v, 0, 1, x);
    if(vtr.size()==0) {
        cout<<"Impossible";
        return 0;
    }
    for(i = 0; i < vtr.size(); i++) {
        int all = 0;
        for(j = 0; j < vtr[i].size(); j++)
            all += vtr[i][j];
        if(all > maxmax) {
            maxmax = all;
            v = vtr[i];
        }
    }
    cout<<m<<" = ";
    for(i = 0; i < v.size(); i++) {
        cout<<v[i]<<"^"<<w;
        if(i!=v.size() - 1) cout<<" + ";
    }
    return 0;
}
