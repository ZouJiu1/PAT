这道题其他人之前可以AC，现在补充了数据AC不了了，主要是点的个数要全，不能重复而且遍历时要注意边存在，而且可能存在多个区间
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v[1006];
bool status[1006], mat[1006][1006];
int main(void) {
    int i, j, k, m, n, N, M, K, y, z, cnt=1, num, arr[1006], id, mr;
    cin>>N>>M>>K;
    for(i = 0; i < M; i++) {
        cin>>y>>z;
        v[y].push_back(z);
        mat[y][z] = true;
    }
    for(j = 0; j < K; j++) {
        mr = 9;
        fill(status, status + 1006, false);
        for(i = 0; i < N; i++) {
            cin>>arr[i];
            if(mr < 0) continue;
            if(status[arr[i]]==true) mr = -9;
            status[arr[i]] = true;
            if(i > 0) {
                if(mat[arr[i-1]][arr[i]]!=true) {
                    int kk = 9;
                    for(k = 0; k < v[arr[i-1]].size(); k++){
                        if(status[v[arr[i-1]][k]]==false) {
                            kk= -9;
                            break;
                        }
                    }
                    if(kk < 0) mr = -9;
                }
            }
        }
        if(mr < 0) {
            printf("no\n");
        }else {
            printf("yes\n");
        }
    }
    return 0;
}
