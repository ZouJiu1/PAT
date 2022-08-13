#include<iostream>
#include<vector>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int i, j, m, n, x, y, k, w;
    cin>>n;
    set<int> st[n];
    for(i=0; i<n; i++){
        cin>>m;
        for(j=0; j<m; j++){
            cin>>x;
            st[i].insert(x);
        }
    }
    cin>>m;
    int minval;
    set<int>::iterator itx;
    for(i = 0; i < m; i++){
        cin>>x>>y;
        int cnt0 = 0, cnt00 = 0;
        k = st[x].size() >= st[y].size()? y-1:x-1;
        w = st[x].size() >= st[y].size()? x-1:y-1;
        x = w;
        y = k;
        for(set<int>::iterator it=st[y].begin(); it!=st[y].end(); it++){
            itx = st[x].find(*it);
            if(itx!=st[x].end())
                cnt0++;
        }
        cnt00 = st[x].size() + st[y].size() - cnt0;
        printf("%.1f%\n", (float)(cnt0*100)/(float)cnt00);
    }
    system("pause");
    return 0;
}
