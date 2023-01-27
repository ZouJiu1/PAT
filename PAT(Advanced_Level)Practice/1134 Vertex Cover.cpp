update202301   set集合查找比循环比对要好，边只要有一个顶点在set集合就可以，一个O(n)一个是O(n^2)
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int main(void) {
    int i, j, ij, k, m, n, K, N, M, y, z, res, arr[10006][2], status[10006];
    cin>>N>>M;
    for(i = 0; i < M; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }
    cin>>K;
    for(i = 0; i < K; i++) {
        cin>>y;
        fill(status, status + 10006, 0);
        res = 0;
        set<int> st;
        for(j = 0; j < y; j++) {
            cin>>z;
            st.insert(z);
        }
        for(ij = 0; ij < M; ij++) {  //O(n)
            if(st.find(arr[ij][0])!=st.end()||
                st.find(arr[ij][1])!=st.end())
                res++;
        }
        if(res==M) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

循环会超时的
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
    int i, j, ij, k, m, n, K, N, M, y, z, res, arr[10006][2];
    cin>>N>>M;
    for(i = 0; i < M; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }
    cin>>K;
    for(i = 0; i < K; i++) {
        cin>>y;
        vector<bool> status(M, false);
        res = 0;
        for(j = 0; j < y; j++) { //O(n^2)
            cin>>z;
            for(ij = 0; ij < M; ij++) {
                if(status[ij]==true) continue;
                if(arr[ij][0]==z||arr[ij][1]==z) {
                    res++;
                    status[ij] = true;
                }
            }
        }
        if(res==M) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

https://www.liuchuo.net
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
    int i, j, ij, k, m, n, K, N, M, y, z, res;
    vector<int> arr[10006];
    cin>>N>>M;
    for(i = 0; i < M; i++) {
        cin>>y>>z;
        arr[y].push_back(i);
        arr[z].push_back(i);
    }
    cin>>K;
    for(i = 0; i < K; i++) {
        cin>>y;
        vector<bool> status(M, false);
        res = 9;
        for(j = 0; j < y; j++) { //O(n^2)
            cin>>z;
            for(ij = 0; ij < arr[z].size(); ij++) {
                status[arr[z][ij]] = true;
            }
        }
        for(ij = 0; ij < M; ij++) {
            if(status[ij]==0){
                printf("No\n");
                res = -9;
                break;
            }
        }
        if(res > 0) printf("Yes\n");
    }
    return 0;
}

old before 
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
