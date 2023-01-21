#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct nod {
    string t;
    int h;
};
bool cmp(nod &a, nod &c) {
    return a.h!=c.h? a.h < c.h : a.t > c.t;
}
int main(void) {
    int i, j, k, m=0, n=0, x, y, z, N, K;
    cin>>N>>K;
    nod nd;
    vector<nod> v, tmp, row[11];
    string tg;
    for(i = 0; i < N; i++) {
        cin>>nd.t>>nd.h;
        v.push_back(nd);
    }
    y = N/K;
    int lat = y + N%K, rownum;
    sort(v.begin(), v.end(), cmp);
    for(i = 0; i < K; i++) {
        if(i!=K-1) rownum = y;
        else rownum = lat;
        m += rownum;
        for(j = 0; j < rownum; j++) {
            if(j%2==0) tmp.insert(tmp.end(), v[m - j - 1]);
            else tmp.insert(tmp.begin(), v[m - j - 1]);
        }
        row[i] = tmp;
        tmp.clear();
    }
    for(j = i-1; j >=0; j--) {
        for(m = 0; m < row[j].size(); m++) {
            cout<<row[j][m].t;
            if(m!=row[j].size()-1) cout<<" ";
        }
        printf("\n");
    }
    return 0;
}




// #include<iostream>
// #include<vector>
// #include<string>
// #include<queue>
// #include<cmath>
// #include<bits/stdc++.h>

// using namespace std;

// vector<int> joinfind;

// int findfather(int a) {
//     int xx, tmp;
//     xx = tmp = a;
//     while(a!=joinfind[a]) a = joinfind[a];
//     //表的路径压缩
//     while(tmp!=joinfind[tmp]) {
//         int z = tmp;
//         tmp = joinfind[tmp];
//         joinfind[z] = a;
//     }
//     return a;
// }

// void unions(int a, int c) {
//     int x = findfather(a);
//     int y = findfather(c);
//     if(x!=y) joinfind[x] = y;
// }

// bool compare(int &a, int &c) {
//     return a > c;
// }

// int main(void){
//     int i, j, m, n, k, w, q, x, y;
//     cin>>m;
//     vector<int> hm;
//     vector<int> findroot;
//     findroot.resize(m + 1);
//     joinfind.resize(m + 1);
//     hm.resize(1003);
//     for(i = 0; i < 1003; i++) hm[i] = 0;
//     for(i = 1; i <= m; i++) {
//         joinfind[i] = i;
//         findroot[i] = 0;
//     }
//     for(i = 1; i <= m; i++) {
//         scanf("%d:", &n);
//         for(j = 0; j < n; j++) {
//             cin>>k;
//             if(hm[k]==0)
//                 hm[k] = i;
//             unions(i, findfather(hm[k]));
//         }
//     }
//     for(i = 1; i <= m; i++) {
//         findroot[findfather(i)]++;
//     }
//     sort(findroot.begin(), findroot.end(), compare);
//     int cnt = 0;
//     for(i = 0; i < m; i++) {
//         if(findroot[i]==0) break;
//         cnt++;
//     }
//     printf("%d\n", cnt);
//     for(i = 0; i < cnt; i++) {
//         printf("%d", findroot[i]);
//         if(i!=cnt - 1) printf(" ");
//     }
//     return 0;
// }
