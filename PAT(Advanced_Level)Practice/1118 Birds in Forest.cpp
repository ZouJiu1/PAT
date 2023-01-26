update202301 问题是对鸟进行提问，看鸟所在簇的个数，并查集或者DFS
update202301 DFS，先将鸟看作图节点，遍历看有几个不连通的区块，每个区块就是一颗树，然后将鸟加上区块index，鸟的index相同就是在同一颗树
#include<iostream>
#include<vector>
#include<set>
using namespace std;
int arr[10006], status[10006], cnt = 0;
vector<int> v[10006];
void recursion(int rot) {
    if(status[rot]==1) return;
    arr[rot] = cnt;
    status[rot] = 1;
    for(int i = 0; i < v[rot].size(); i++) {
        if(status[v[rot][i]]==0) recursion(v[rot][i]);
    }
}
int main(void) {
    int i, j, k, m, n, N, K, M, pre, y, z;
    cin>>N;
    set<int> st;
    for(i = 0; i < N; i++) {
        cin>>K;
        for(j = 0; j < K; j++) {
            cin>>m;
            st.insert(m);
            if(j!=0) {
                v[m].push_back(pre);
                v[pre].push_back(m);
            }
            pre = m;
        }
    }
    for(auto it:st) {
        if(status[it]==0) {
            recursion(it);
            cnt++;
        }
    }
    printf("%d %d\n", cnt, st.size());
    cin>>M;
    for(i = 0; i < M; i++) {
        cin>>y>>z;
        if(arr[y]==arr[z]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

update202301 并查集，先将鸟送到并查集，然后数根节点个数即可，鸟的根节点相同就是在同一棵树
#include<iostream>
#include<vector>
#include<set>
using namespace std;
int arr[10006];
int findfather(int a) {
    int t = a;
    while(a!=arr[a]) a = arr[a];
    arr[t] = a;
    return a;
}
void unionjoin(int a, int c) {
    int A = findfather(a);
    int C = findfather(c);
    if(A >= C) arr[A] = C;
    else arr[C] = A;
}
int main(void) {
    int i, j, k, m, n, N, K, M, pre, y, cnt = 0, z, maxmax = -999999999;
    cin>>N;
    set<int> st;
    vector<int> v[10006];
    for(i = 0; i < 10006; i++) arr[i] = i;
    for(i = 0; i < N; i++) {
        cin>>K;
        for(j = 0; j < K; j++) {
            cin>>m;
            if(maxmax < m) maxmax = m;
            if(j!=0) unionjoin(pre, m);
            pre = m;
            v[i].push_back(m);
        }
    }
    for(i = 1; i <= maxmax; i++) {
        if(findfather(i)==i) cnt++;
    }
    printf("%d %d\n", cnt, maxmax);
    cin>>M;
    for(i = 0; i < M; i++) {
        cin>>y>>z;
        if(findfather(y)==findfather(z)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

old before
#include<iostream>
#include<vector>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int arrays[100000];

int findfather(int a) {
    int tmp = a;
    while(a!=arrays[a])
        a = arrays[a];
    arrays[tmp] = a;
    return a;
}

void unionjoin(int a, int c) {
    int x = findfather(a);
    int y = findfather(c);
    arrays[y] = x;
}

int main(void) {
    int i, j, k, m, n;
    cin>>n;
    for(i = 0; i < 100000; i++) arrays[i] = i;
    set<int> st;
    for(i = 0; i < n; i++) {
        cin>>m;
        vector<int> v;
        for(j = 0; j < m; j++) {
            cin>>k;
            v.push_back(k);
            st.insert(k);
        }
        sort(v.begin(), v.end());
        for(int ij = 1; ij < v.size(); ij++) {
            unionjoin(v[0], v[ij]);
        }
    }
    int n0, x1, x2;
    cin>>n0;
    int cnt = 0;
    for(i = 1; i <= st.size(); i++) {
        if(arrays[i]==i) cnt++;
    }
    cout<<cnt<<" "<<st.size()<<endl;
    for(i = 0; i < n0; i++) {
        cin>>x1>>x2;
        if(findfather(x1) == findfather(x2)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}

update1
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;
int arr[100000];

int findfather(int a) {
    int tmp = a;
    while(arr[a]!=a) a = arr[a];
    arr[tmp] = a;
    return a;
}
void unionjoin(int a, int c) 
{
    int aa = findfather(a);
    int cc = findfather(c);
    if(aa < cc) arr[cc] = aa;
    else arr[aa] = cc;
}
int main(int argc, char **argv) {
    int i, j, k, m, n, y, z, maxmax = -999999999, pre = 0;
    cin>>m;
    for(i = 0; i < 100000; i++) arr[i] = i;
    for(i = 0; i < m; i++) {
        cin>>n;
        vector<int> v;
        for(j = 0; j < n; j++) {
            cin>>y;
            v.push_back(y);
            if(maxmax < y) maxmax = y;
        }
        sort(v.begin(), v.end());
        for(j = 0; j < v.size()-1; j++) 
            unionjoin(v[j], v[j+1]);
    }
    y = 0;
    for(i = 1; i <= maxmax; i++) {
        if(findfather(i)==i) y++;
    }
    printf("%d %d\n", y, maxmax);
    cin>>n;
    for(i = 0; i < n; i++) {
        cin>>y>>z;
        if(findfather(y)==findfather(z)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
