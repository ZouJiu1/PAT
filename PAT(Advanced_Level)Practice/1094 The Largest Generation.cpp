dfs
#include<iostream>
#include<vector>
using namespace std;
vector<int> v[101];
int m, n, k, y, num[101], maxmax = -99999999;
void dfs(int start, int level) {
    num[level]++;
    if(v[start].size()==0) {
        if(num[level] > maxmax) {
            maxmax = num[level];
            y = level;
        }
        return;
    }
    for(int i = 0; i < v[start].size(); i++)
        dfs(v[start][i], level + 1);
}
int main(int argc, char **argv) {
    int i, j, z;
    cin>>m>>n;
    for(i = 0; i < n; i++) {
        cin>>k>>z;
        for(j = 0; j < z; j++) {
            cin>>y;
            v[k].push_back(y);
        }
    }
    dfs(1, 1);
    cout<<maxmax<<" "<<y<<endl;
    return 0;
}

bfs
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main(void) {
    int i, j, k, m, n, w, x, y, t;
    cin >> m >> n;
    vector<int> mp[101];
    for(i = 0; i < n; i++){
        cin>>x>>t;
        for(j = 0; j < t; j++){
            cin>>y;
            mp[x].push_back(y);
        }
    }
    queue<int> q, q0;
    q.push(1);
    q0.push(1);
    vector<int> vec[101];
    vec[1].push_back(1);
    while(q.size() > 0){
        x = q.front();
        y = q0.front();
        q.pop();
        y++;
        q0.pop();
        if(mp[x].size()==0) continue;
        for(i = 0; i < mp[x].size(); i++){
            t = mp[x][i];
            vec[y].push_back(t);
            q.push(t);
            q0.push(y);

        }
    }
    x = -9999999;
    for(i = 0; i < 101; i++){
        if(vec[i].size()==0) continue;
        t = vec[i].size();
        if(x < t){
            x = t;
            y = i;
        }
    }
    cout<<x<<" "<<y;
    return 0;
}
