update202302
哈密顿图（哈密尔顿图）（英语：Hamiltonian graph，或Traceable graph）是一个无向图，由文学家哈密顿提出，由指定的起点前往指定的终点，
途中经过所有其他节点且只经过一次。在图论中是指含有哈密顿回路的图，闭合的哈密顿路径称作哈密顿回路（Hamiltonian cycle），
含有图中所有顶点的路径称作哈密顿路径（Hamiltonian path）。
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
bool status[206][206];
int vertex[206];
int main(void) {
    int i, j, k, K, N, M, n, m, y, z;
    cin>>N>>M;
    for(i = 0; i < M; i++) {
        cin>>y>>z;
        status[y][z] = status[z][y] = true;
    }
    cin>>K;
    for(i = 0; i < K; i++) {
        cin>>n;
        set<int> te;
        int mr = 9;
        fill(vertex, vertex + 206, 0);
        for(j = 0; j < n; j++) {
            scanf("%d", &y);
            te.insert(y);
            if(j==0) k = y;
            if(j==n-1 && k!=y) mr = -9;
            if(y <0||y>N) mr = -9;
            vertex[y]++;
            if(j!=n-1 && vertex[y]>1) mr = -9;
            if(j > 0) {
                if(status[y][z]==false||status[z][y]==false) mr = -9;
            }
            z = y;
        }
        if(te.size()!=N) mr = -9;
        if(mr < 0) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}


old before
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int main(void) {
    int i, j, k, m, n, x1, x2;
    cin>>m>>n;
    vector<vector<int>> v0;
    int matrix[206][206];
    int infinf = (int)(pow(2, 31) - 1006);
    for(i = 0; i < 206; i++) {
        for(j = 0; j < 206; j++) {
            matrix[i][j] = infinf;
        }
    }
    for(i = 0; i < n; i++) {
        cin>>x1>>x2;
        matrix[x1][x2] = matrix[x2][x1] = 1;
    }
    cin>>n;
    v0.resize(10000);
    for(i = 0; i < n; i++) {
        cin>>k;
        set<int> st;
        for(j = 0; j < k; j++) {
            cin>>x1;
            v0[i].push_back(x1);
            st.insert(x1);
        }
        int mr = -9;
        for(int ij = 0; ij < v0[i].size() - 1; ij++) {
            if(matrix[v0[i][ij]][v0[i][ij+1]]!=1){
                mr = 9;
                break;
            }
        }

        if(v0[i].size()!=m+1 || st.size()!=m || mr > 0 || v0[i][0]!=v0[i][v0[i].size() - 1]){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
    }

    return 0;
}
