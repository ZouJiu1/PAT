update202302 simple cycle经过每个节点且仅经过依次    cycle经过每个节点可能多次
#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

int mat[206][206];
bool vertex[206];

int main(void) {
    int i, j, k, m, n, N, M, K, y, z, minmin = 999999999;
    cin>>N>>M;
    for(i = 0; i < M; i++) {
        cin>>y>>z>>k;
        mat[y][z]=mat[z][y] = k;
    }
    cin>>K;
    for(i = 0; i < K; i++) {
        cin>>n;
        vector<int> v(n);
        set<int> tk;
        fill(vertex, vertex + 206, false);
        int mr = 9, kk = 9, sum = 0;
        for(j = 0; j < n; j++) {
            scanf("%d", &v[j]);
            tk.insert(v[j]);
            if(j!=n-1 && vertex[v[j]]==true) kk = -9;
            if(j > 0) {
                if(mat[v[j]][v[j-1]]==0) mr = -9;
                sum += mat[v[j]][v[j-1]];
            }
            vertex[v[j]] = true;
        }
        printf("Path %d: ", i+1);
        if(mr < 0) cout<<"NA (";
        else printf("%d (", sum);
        if(tk.size()!=N||v[n-1]!=v[0]||mr < 0) printf("Not a TS cycle)\n");
        else {
            if(kk < 0) printf("TS cycle)\n");
            else printf("TS simple cycle)\n");
            if(minmin > sum) {
                minmin = sum;
                z = i+1;
            }
        }
    }
    printf("Shortest Dist(%d) = %d\n", z, minmin);
    return 0;
}

old before
#include<iostream>
#include<vector>
using namespace std; 
int main(void) {
    int i, j, k, m, n, x1, x2, x3, w;
    cin>>m>>w;
    int matrix[209][209];
    for(i = 0; i < 209; i++)
        for(j = 0; j < 209; j++)
            matrix[i][j] = -9;
    for(i = 0; i < w; i++) {
        scanf("%d %d %d", &x1, &x2, &x3);
        matrix[x1][x2] = matrix[x2][x1] = x3;
    }
    int minmin = 9999999;
    cin>>w;
    for(i = 1; i <= w; i++) {
        cin>>n;
        vector<int> v, status(m + 1, 0);
        x2 = 0;
        for(j = 0; j < n; j++) {
            scanf("%d", &k);
            v.push_back(k);
            if(j > 0 && x2 >=0) {
                x3 = matrix[v[j - 1]][v[j]];
                status[v[j - 1]] = status[v[j]] = 9;
                if(x3 > 0) x2 += x3; 
                else x2 = -9;
            }
        }
        if(x2 < 0) {
            printf("Path %d: NA (Not a TS cycle)\n", i);
            continue;
        }
        x3 = -9;
        for(j = 1; j <= m; j++) {
            if(status[j]==0){
                x3 = 9;
                break;
            }
        }
        if(x3 > 0 || v[0]!=v[v.size() - 1]) {
            printf("Path %d: %d (Not a TS cycle)\n", i, x2);
            continue;
        }
        if(x2 < minmin) {
            minmin = x2;
            x1 = i;
        }
        if(v.size() != m + 1) {
            printf("Path %d: %d (TS cycle)\n", i, x2);
            continue;
        }
        printf("Path %d: %d (TS simple cycle)\n", i, x2);
        v.clear();
    }
    printf("Shortest Dist(%d) = %d\n", x1, minmin);
    return 0;
}
