#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;
vector<bool> retailer;
vector<double> price;
double unit, percent;
vector<vector<int>> v;
double minmin = 99999999;

void dfs(int ind, double pr) {
    vector<int> vr; 
    vr = v[ind];
    if(ind!=0)
        price[ind] = pr * percent;
    if(minmin > price[ind] && retailer[ind]==true) {
        minmin = price[ind];
    }
    for(int i = 0; i < vr.size(); i++) {
        dfs(vr[i], price[ind]);
    }
}

int main(void){
    int i, j, m, n, k, w, q, xx, xy, prime;
    double tmp;
    cin>>m>>unit>>percent;
    v.resize(m);
    retailer.resize(m);
    price.resize(m);
    percent = (1 + percent/(double)100.0);
    for(i = 0; i < m; i++) price[i] = unit;
    for(i = 0; i < m; i++){
        cin>>k;
        if(k==0){
            retailer[i] = true;
            continue;
        }
        for(j = 0; j < k; j++){
            cin>>q;
            v[i].push_back(q);
        }
    }
    if(m<=1){
        cout<<"0.0000 0";
        return 0;
    }
    dfs(0, unit);

    int cnt = 0;
    for(i = 0; i < m; i++) {
        if(retailer[i]==true && price[i]==minmin) {
            cnt++;
        }
    }
    printf("%.4f %d", minmin, cnt);
    return 0;
}





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
    double price[m];
    memset((void *)retailer, false, sizeof(bool) * m);
    for(i = 0; i < m; i++) price[i] = unit;
    vector<vector<int>> v;
    v.resize(m);
    if(m<=1){
        cout<<"0.0";
        return 0;
    }
    for(i = 0; i < m; i++){
        cin>>k;
        if(k==0){
            retailer[i] = true;
            continue;
        }
        for(j = 0; j < k; j++){
            cin>>q;
            v[i].push_back(q);
        }
    }
    queue<vector<int>> vtr;
    vector<int> rtv;
    vtr.push(v[0]);
    queue<int> pre;
    pre.push(0);
    int prenum, ind;
    double minmin = 9999999;
    while(vtr.size() > 0){
        rtv = vtr.front();
        prenum = pre.front();
        for(i = 0; i < rtv.size(); i++){
            ind = rtv[i];
            price[ind] = price[prenum] * ((double)1.0 + percent/(double)100.0);
            if(minmin > price[ind] && retailer[ind]==true) {
                minmin = price[ind];
            }
            if(v[ind].size() > 0){
                vtr.push(v[ind]);
                pre.push(ind);
            }
        }
        vtr.pop();
        pre.pop();
    }
    int cnt = 0;
    for(i = 0; i < m; i++) {
        if(retailer[i]==true && price[i]==minmin) {
            cnt++;
        }
    }
    printf("%.4f %d", minmin, cnt);
    return 0;
}
