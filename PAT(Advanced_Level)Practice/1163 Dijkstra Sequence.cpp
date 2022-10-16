#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(void) {
    int i, j, m, n, x, y, k, w;
    vector<vector<int>> matrix;
    int infinf = (int)pow(2, 31) - 6;
    matrix.resize(1006);
    for(i = 0; i < 1006; i++) matrix[i].resize(1006);
    cin>>m>>n;
    for(i = 0; i < n; i++) {
        cin>>x>>y>>k;
        matrix[x][y] = matrix[y][x] = k;
    }
    cin>>k;
    vector<vector<int>> v;
    v.resize(k);
    for(x = 0; x < k; x++) {
        for(w = 0; w < m; w++) {
            cin>>y;
            v[x].push_back(y);
        }
    }
    for(x = 0; x < k; x++) {
        bool status[1006] = {false};
        int sum[1006], cnt = 0, exi;
        for(i = 0; i < 1006; i++) sum[i] = infinf;
        sum[v[x][0]] = 0;
        int minmin, ind, mr;
        for(i = 1; i <= m; i++) {
            minmin = infinf - 1;
            exi = v[x][cnt];
            for(j = 1; j <=m; j++) {
                if(status[j]==false && sum[j] <= minmin) {
                    if(sum[j] < minmin) {
                        if(j==exi)
                            mr = 9;
                        else mr = -9;
                    }else if(sum[j]==minmin && j==exi) mr = 9;
                    minmin = sum[j];
                }
            }
            if(mr < 0) {
                printf("No\n");
                break;
            }
            cnt++;
            status[exi] = true;
            for(j = 1; j <=m; j++) {
                if(status[j]==false && sum[j] > sum[exi] + matrix[exi][j] && matrix[exi][j]!=0) {
                    sum[j] = sum[exi] + matrix[exi][j];
                }
            }
            mr = 9;
        }
        if(mr > 0) printf("Yes\n");
    }
    return 0;
}
