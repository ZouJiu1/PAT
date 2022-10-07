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
