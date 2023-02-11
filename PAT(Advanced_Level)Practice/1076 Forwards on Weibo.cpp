和普通的节点不相同的图不相同，这里的节点可能会重复，同个follower可能存在多层的，deepth first 会存在先访问了左侧的3然后令状态=true，
然后右侧节点的3之后的follower就访问不到了，所以最好用width first加status判断是否访问过，是层序遍历，所以不会出现deepth first的情况。
Deepth first也可以不过要用set存然后不判断状态，不过最后一个测试点会超时

Widthfirst用set存会内存过大的

L=3

              1

      2             3

3               6       11

…

AC的版本
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> v[1006];
int L, sum;
struct nod{int v, l;};
bool status[1006];
void width_firstly(int tat) {
    queue<nod> q;
    q.push({tat, 0});
    nod nd;
    while(!q.empty()) {
        nd = q.front();
        q.pop();
        status[nd.v] = true;
        for(int i = 0; i < v[nd.v].size(); i++) {
            if(status[v[nd.v][i]]==false && nd.l < L) {
                q.push({v[nd.v][i], nd.l+1});
                status[v[nd.v][i]] = true;
                sum++;
            }
        }
    }
}
int main(void) {
    int i, j, k, M, N, n, m, K, y, z, x;
    cin>>N>>L;
    for(i = 1; i <= N; i++) {
        cin>>M;
        for(j = 0; j < M; j++) {
            cin>>y;
            v[y].push_back(i);
        }
    }
    cin>>K;
    for(i = 0; i < K; i++) {
        cin>>y;
        sum=0;
        fill(status, status + 1006, false);
        width_firstly(y);
        printf("%d\n", sum);
    }
    return 0;
}

内存大的版本 width firstly
尽量不要用set存
#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
vector<int> v[1006];
int L, sum;
struct nod{int v, l;};
set<int> te;
void width_firstly(int tat) {
    queue<nod> q;
    q.push({tat, 0});
    nod nd;
    while(!q.empty()) {
        nd = q.front();
        q.pop();
        for(int i = 0; i < v[nd.v].size(); i++) {
            if(nd.l < L) {
                q.push({v[nd.v][i], nd.l+1});
                te.insert(v[nd.v][i]);
            }
        }
    }
}
int main(void) {
    int i, j, k, M, N, n, m, K, y, z, x;
    cin>>N>>L;
    for(i = 1; i <= N; i++) {
        cin>>M;
        for(j = 0; j < M; j++) {
            cin>>y;
            v[y].push_back(i);
        }
    }
    cin>>K;
    for(i = 0; i < K; i++) {
        cin>>y;
        te.clear();
        width_firstly(y);
        printf("%d\n", te.find(y)!=te.end()? te.size()-1:te.size());
    }
    return 0;
}

时间过长的版本 deepth firstly
#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<int> v[1006];
int L, sum;
set<int> te;
void deepth_firstly_recursion(int tat, int lev) {
    if(lev > L) return;
    te.insert(tat);
    for(int i = 0; i < v[tat].size(); i++) {
        deepth_firstly_recursion(v[tat][i], lev + 1);
    }
}
int main(void) {
    int i, j, k, M, N, n, m, K, y, z, x;
    cin>>N>>L;
    for(i = 1; i <= N; i++) {
        cin>>M;
        for(j = 0; j < M; j++) {
            cin>>y;
            v[y].push_back(i);
        }
    }
    cin>>K;
    for(i = 0; i < K; i++) {
        cin>>y;
        te.clear();
        deepth_firstly_recursion(y, 0);
        printf("%d\n", te.size() - 1);
    }
    return 0;
}

 状态列表记录访问状态 
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int i, j, m, n, k, w, q, xx, xy;
    cin>>m>>q;
    map<int, vector<int>> mp;
    bool status[m + 1];
    for(i = 1; i <= m; i++){
        cin>>k;
        for(j = 1; j<=k; j++){
            cin>>w;
            mp[w].push_back(i);
        }
    }
    vector<int> vec;
    cin>>n;
    for(j = 0; j < n; j++){
        cin>>k;
        vec.push_back(k);
    }
    set<int> st; //posted
    vector<int> v;
    vector<vector<int>> vv;
    for(j = 0; j < n; j++){
        memset((void*)status, false, sizeof(bool) * (m + 1));
        vv.push_back(mp[vec[j]]);
        st.insert(vec[j]);
        for(xy = 0; xy < q; xy++){
            int sizes = vv.size();
            for(xx = 0; xx < sizes; xx++){
                v = vv[xx];
                for(i = 0; i < v.size(); i++){
                    if(status[v[i]]==false){
                        vv.push_back(mp[v[i]]);
                        st.insert(v[i]);
                        status[v[i]] = true;
                    }
                }
            }
            vv.erase(vv.begin(), vv.begin() + sizes);
        }
        cout<<st.size() - 1<<endl;
        st.clear();
        vv.clear();
    }
    return 0;
}
