物种个数要=K
然后可能存在多个不连通的图，所以最好不要使用递归，直接判断每条边的端点，也就是region对应的物种是否相同

#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int arr[600], tat[600][600], mr = 9, kk[1000000][2], yz;
vector<int> v[600];
// void recursion(int start){
//     if(mr < 0) return;
//     for(int i = 0; i < v[start].size(); i++) {
//         yz = v[start][i];
//         if(tat[start][yz]==1 && tat[yz][start]==1) continue;
//         if(arr[start]==arr[yz]) {
//             mr = -9;
//             return;
//         }
//         tat[start][yz] = 1;
//         tat[yz][start] = 1;
//         recursion(yz);
//     }
// }

int main(void) {
    int i, j, k, N, M, R, K, y, z, ll;
    cin>>N>>R>>K;
    map<int, int> mp;
    for(i = 0; i < R; i++) {
        scanf("%d %d", &y, &z);
        v[y].push_back(z);
        v[z].push_back(y);
        kk[i][0] = y;
        kk[i][1] = z;
    }
    cin>>M;
    for(i = 0; i < M; i++) {
        fill(tat[0], tat[0] + 600 * 600, 0);
        set<int> te;
        mr = 9;
        for(j = 1; j <= N; j++) {
            scanf("%d", &arr[j]);
            te.insert(arr[j]);
        }
        if(te.size() < K) printf("Error: Too few species.\n");
        else if(te.size() > K) printf("Error: Too many species.\n");
        else {
            // recursion(N);   //可能存在多个不连通的图，所以最好不要使用递归
            for(j = 0; j < R; j++) {
                y = kk[j][0];
                z = kk[j][1];
                if(arr[y]==arr[z]){
                    mr = -9;
                    break;
                }
            }
            if(mr < 0) printf("No\n");
            else printf("Yes\n");
        }
    }
    return 0;
}
