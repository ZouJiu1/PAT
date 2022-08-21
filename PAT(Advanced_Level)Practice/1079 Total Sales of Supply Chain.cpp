#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int i, j, m, n, k, w, q, xx, xy, prime;
    double unit, percent;
    double sum = 0.0, tmp;
    cin>>m>>unit>>percent;
    bool retailer[m];
    long long salenum[m];
    double price[m];
    memset((void *)retailer, false, sizeof(bool) * m);
    for(i = 0; i < m; i++) price[i] = unit;
    vector<vector<int>> v;
    v.resize(m);
    for(i = 0; i < m; i++){
        cin>>k;
        if(k==0){
            cin>>tmp;
            retailer[i] = true;
            salenum[i] = tmp;
            continue;
        }
        for(j = 0; j < k; j++){
            cin>>q;
            v[i].push_back(q);
        }
    }
    if(m<=1){
        cout<<"0.0";
        return 0;
    }
    queue<vector<int>> vtr;
    vector<int> rtv;
    vtr.push(v[0]);
    queue<int> pre;
    pre.push(0);
    int prenum, ind;
    while(vtr.size() > 0){
        rtv = vtr.front();
        prenum = pre.front();
        for(i = 0; i < rtv.size(); i++){
            ind = rtv[i];
            price[ind] = price[prenum] * ((double)1.0 + percent/(double)100.0);
            if(v[ind].size() == 0&&retailer[ind]==true){
                sum += salenum[ind] * price[ind];
                continue;
            }
            if(v[ind].size() > 0){
                vtr.push(v[ind]);
                pre.push(ind);
            }
        }
        vtr.pop();
        pre.pop();
    }
    printf("%.1f", round((double)sum*10.0)/(double)10.0);
    return 0;
}
