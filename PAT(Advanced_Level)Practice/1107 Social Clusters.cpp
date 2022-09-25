#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

vector<int> joinfind;

int findfather(int a) {
    int xx, tmp;
    xx = tmp = a;
    while(a!=joinfind[a]) a = joinfind[a];
    //表的路径压缩
    while(tmp!=joinfind[tmp]) {
        int z = tmp;
        tmp = joinfind[tmp];
        joinfind[z] = a;
    }
    return a;
}

void unions(int a, int c) {
    int x = findfather(a);
    int y = findfather(c);
    if(x!=y) joinfind[x] = y;
}

bool compare(int &a, int &c) {
    return a > c;
}

int main(void){
    int i, j, m, n, k, w, q, x, y;
    cin>>m;
    vector<int> hm;
    vector<int> findroot;
    findroot.resize(m + 1);
    joinfind.resize(m + 1);
    hm.resize(1003);
    for(i = 0; i < 1003; i++) hm[i] = 0;
    for(i = 1; i <= m; i++) {
        joinfind[i] = i;
        findroot[i] = 0;
    }
    for(i = 1; i <= m; i++) {
        scanf("%d:", &n);
        for(j = 0; j < n; j++) {
            cin>>k;
            if(hm[k]==0)
                hm[k] = i;
            unions(i, findfather(hm[k]));
        }
    }
    for(i = 1; i <= m; i++) {
        findroot[findfather(i)]++;
    }
    sort(findroot.begin(), findroot.end(), compare);
    int cnt = 0;
    for(i = 0; i < m; i++) {
        if(findroot[i]==0) break;
        cnt++;
    }
    printf("%d\n", cnt);
    for(i = 0; i < cnt; i++) {
        printf("%d", findroot[i]);
        if(i!=cnt - 1) printf(" ");
    }
    return 0;
}
