#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int i, j, k, m, n, h, mm, nn;
    cin>>m;
    vector<int> exits, allexit, cumsum;
    exits.resize(m + 1);
    cumsum.resize(m + 1);
    cumsum[0] = 0;
    for(i=1; i<=m; i++){
        cin>>n;
        exits[i] = n;
        cumsum[i] = n + cumsum[i - 1];
    }
    cin>>m;
    for(i=1; i<=m; i++){
        cin>>n>>h;
        allexit.push_back(n);
        allexit.push_back(h);
    }
    int minmin, maxmax, tmp, tmp0, tmp00, sizes;
    sizes = exits.size();
    for(i = 0; i < m; i++){
        mm = allexit[2 * i];
        nn =  allexit[2 * i + 1];
        maxmax = max(mm, nn);
        minmin = min(mm, nn);
        tmp = cumsum[maxmax - 1] - cumsum[minmin - 1];
        tmp0 = cumsum[sizes - 2] - cumsum[maxmax - 1] + exits[sizes - 1];
        tmp00 = cumsum[minmin - 1];
        tmp = min(tmp, tmp0 + tmp00);
        cout<<tmp<<endl;
    }
    return 0;
}
