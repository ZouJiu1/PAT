#include<set>
#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;

int main(void) {
    int i, j, k, m, n;
    cin>>m>>n;
    vector<vector<int>> v;
    v.resize(n);
    int x1, x2;
    for(i = 0; i < n; i++) v[i].resize(2);
    for(i = 0; i < n; i++) {
        scanf("%d %d", &x1, &x2);
        v[i][0] = x1;
        v[i][1] = x2;
    }
    int ww = n;
    scanf("%d", &ww);
    vector<set<int>> vrt;
    vrt.resize(ww);
    for(i = 0; i < ww; i++) {
        scanf("%d", &k);
        v1[i].resize(k);
        for(j = 0; j < k; j++) {
            scanf("%d", &x1);
            vrt[i].insert(x1);
        }
     }
     for(i = 0; i < ww; i++) {
        int sum = 0;
        int mr = -9;
        for(x1 = 0; x1 < n; x1++) {
            if(vrt[i].find(v[x1][0])!=vrt[i].end() ||
                vrt[i].find(v[x1][1])!=vrt[i].end())
                sum++;
        }
        if(sum!=n) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
     }
    return 0;

}
