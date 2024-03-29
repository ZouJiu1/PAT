update202302
#include<iostream>
#include<vector>
using namespace std;
int deg[600], status[600];
vector<int> v[600];
void recursion(int tat) {
    status[tat] = 1;
    for(int i = 0; i < v[tat].size(); i++) {
        if(status[v[tat][i]]==0) recursion(v[tat][i]);
    }
}
int main(void) {
    int i, j, k, N, M, K, y, z, h, odd=0, even=0, sum=0;
    cin>>N>>M;
    for(i = 0; i < M; i++) {
        cin>>y>>z;
        deg[y]++;
        deg[z]++;
        v[y].push_back(z);
        v[z].push_back(y);
    }
    for(i = 1; i <= N; i++) {
        if(deg[i]%2==0) even++;
        else odd++;
        printf("%d%s", deg[i], i==N? "\n":" ");
    }
    recursion(1);  //判断是否是connected
    for(i = 1; i <= N; i++) {
        sum += status[i];
    }
    if(sum!=N) {
        printf("Non-Eulerian\n");
        return 0;
    }
    if(even==N) printf("Eulerian\n");
    else if(odd==2) printf("Semi-Eulerian\n");
    else printf("Non-Eulerian\n");
    return 0;
}


old before
#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int m, n;
vector<vector<int>> v, status;
vector<int> degree;

void dfs(int x) {
    int end;
    for(int j = 0; j < v[x].size(); j++) {
        end = v[x][j];
        if(status[x][j]==1) continue;
        if(status[x][j]==0) {
            status[x][j] = 1;
            dfs(end);
        }
    }
}

int main(void) {
    int i, j, k;
    cin>>m>>n;
    v.resize(m + 1);
    status.resize(m + 1);
    vector<int> degree;
    int x1, x2;
    for(i = 0; i < n; i++) {
        cin>>x1>>x2;
        v[x1].push_back(x2);
        v[x2].push_back(x1);
        status[x1].push_back(0);
        status[x2].push_back(0);
    }
    dfs(1);
    int re = 0;
    for(i = 1; i < m+1; i++) {
        degree.push_back(status[i].size());
        if(status[i].size()%2==1) re++;
    }
    for(i = 0; i < degree.size(); i++) {
        cout<<degree[i];
        if(i!=degree.size()-1) cout<<" ";
    }
    int kk = 0;
    for(i = 1; i < m+1; i++) {
        for(j = 0; j < status[i].size(); j++) {
            if(status[i][j]==0) {
                cout<<endl<<"Non-Eulerian"<<endl;
                return 0;
            }
        }
    }
    cout<<endl;
    if(re==0) cout<<"Eulerian"<<endl;
    else if(re==2) cout<<"Semi-Eulerian"<<endl;
    else cout<<"Non-Eulerian"<<endl;
    return 0;
}
