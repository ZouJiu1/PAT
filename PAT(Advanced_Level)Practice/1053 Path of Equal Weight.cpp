update
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int target;
struct NODE {
    int w;
    vector<int> child;
};
vector<NODE> v;
vector<int> path;
void dfs(int index, int nodeNum, int sum) {
    if(sum > target) return ;
    if(sum == target) {
        if(v[index].child.size() != 0) return;
        for(int i = 0; i < nodeNum; i++)
            printf("%d%c", v[path[i]].w, i != nodeNum - 1 ? ' ' : '\n');
        return ;
    }
    for(int i = 0; i < v[index].child.size(); i++) {
        int node = v[index].child[i];
        path[nodeNum] = node;
        dfs(node, nodeNum + 1, sum + v[node].w);
    }
    
}
int cmp1(int a, int b) {
    return v[a].w > v[b].w;
}
int main() {
    int n, m, node, k;
    scanf("%d %d %d", &n, &m, &target);
    v.resize(n), path.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i].w);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &node, &k);
        v[node].child.resize(k);
        for(int j = 0; j < k; j++)
            scanf("%d", &v[node].child[j]);
        sort(v[node].child.begin(), v[node].child.end(), cmp1);
    }
    dfs(0, 1, v[0].w);
    return 0;
}

old before
/*迭代*/
#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<bits/stdc++.h>

using namespace std;


bool compare(vector<int> &v1, vector<int> &v2){
    int minnum = min(v1.size(), v2.size());
    for(int i = 0; i < minnum; i++){
        if(v1[i]==v2[i]) continue;
        else{
            if(v1[i] > v2[i]) return true;
            else return false;
        }
    }
}
int main(void){
    int i, j, m, n, t, counts, x, y, cnt=0;
    long long k;
    cin>>m>>n>>k; 
    vector<int> v, v0[101], vs[101];
    int status[101];
    int leafs[101];
    memset((void *)status, 0, sizeof(int) * 101);
    memset((void *)leafs,  9, sizeof(int) * 101);
    for(i=0; i<m; i++){
        cin>>t;
        v.push_back(t);
    }
    for(i=0; i<n; i++){
        cin>>x>>t;
        leafs[x] = -9;
        for(j=0; j<t; j++){
            cin>>y;
            v0[x].push_back(y);
        }
    }
    vs[cnt].push_back(0);
    long long sum = v[0];
    status[0] = 9;
    if(m==1 && sum==k){
        cout<<v[0]<<endl;
        return 0;
    }
    while(vs[cnt].size()!=0){
        int mar;
        x = vs[cnt][vs[cnt].size() - 1];
        if(v0[x].size()==0){
            vs[cnt].pop_back();
            sum -= v[x];
            continue;
        }
        int fix = 999;
        for(i = 0; i<v0[x].size(); i++){
            if(status[v0[x][i]] > 0){
                mar = 999;
                continue;
            }
            else{
                mar = -999;
                if(fix > 0)
                    sum += v[v0[x][i]];
                else
                    sum = sum - v[v0[x][i-1]] + v[v0[x][i]];
                status[v0[x][i]] = 9;
                if(sum > k){
                    sum -= v[v0[x][i]];
                    fix = 999;
                    continue;
                }else if(sum==k && leafs[v0[x][i]] >= 0){
                    if(fix < 0) vs[cnt].pop_back();
                    vs[cnt].push_back(v0[x][i]);
                    vs[cnt+1] = vs[cnt];
                    cnt++;
                    fix = -999;
                    continue;
                }else if(sum==k && leafs[v0[x][i]] < 0){
                    sum -= v[v0[x][i]];
                    fix = 999;
                    continue;
                }
                vs[cnt].push_back(v0[x][i]);
                break;
            }
        }
        if(mar > 0){
            vs[cnt].pop_back();
            sum -= v[x];
        }
    }

    vector<vector<int>> vsr;
    for(i = 0; i < cnt; i++){
        vector<int> res;
        for(j = 0; j < vs[i].size(); j++){
            res.push_back(v[vs[i][j]]);
        }
        vsr.push_back(res);
    }
    sort(vsr.begin(), vsr.end(), compare);
    for(i=0; i<cnt; i++){
        for(j = 0; j < vsr[i].size(); j++){
            cout<<vsr[i][j];
            if(vsr[i].size()-1!=j) cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
递归
*/
#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<bits/stdc++.h>

using namespace std;
vector<int> v, v0[101], vs[101];
int i, j, m, n, t, counts, x, y, cnt=0;
long long k;

int pathes[101];

void dfs(int start, int nodenum, int sum){
    if(sum > k) return;
    if(sum==k){
        if(v0[start].size()!=0) return;
        for(int i = 0; i < nodenum; i++){
            printf("%d", pathes[i]);
            if(i!=nodenum-1) printf(" ");
        }
        printf("\n");
        return;
    }else{
        for(int i = 0; i < v0[start].size(); i++){
            pathes[nodenum] = v[v0[start][i]];
            dfs(v0[start][i], nodenum + 1, sum + v[v0[start][i]]);
        }
    }
}

bool compare(int &a, int &c){
    if(v[a] > v[c]) return true;
    else return false;
}

int main(void){
    cin>>m>>n>>k; 
    for(i=0; i<m; i++){
        cin>>t;
        v.push_back(t);
    }
    for(i=0; i<n; i++){
        cin>>x>>t;
        for(j=0; j<t; j++){
            cin>>y;
            v0[x].push_back(y);
        }
        sort(v0[x].begin(), v0[x].end(), compare);
    }
    pathes[0]=v[0];
    dfs(0, 1, v[0]);
    return 0;
}
