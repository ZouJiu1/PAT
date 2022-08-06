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
