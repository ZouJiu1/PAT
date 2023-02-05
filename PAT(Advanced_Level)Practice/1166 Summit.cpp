update202302
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int arr[206][206];
int main(void) {
    int i, j, k, m, n, N, M, K, L, y, z, h;
    cin>>N>>M;
    for(i = 0; i < M; i++) {
        cin>>y>>z;
        arr[y][z] = arr[z][y] = 1;
    }
    cin>>K;
    for(i = 1; i<=K; i++) {
        cin>>L;
        vector<int> v(L);
        unordered_map<int, int> ump;
        for(j = 0; j < L; j++) {
            scanf("%d", &v[j]);
            ump[v[j]] = 1;
        }
        int mr = 9, kk = 9;
        for(j = 0; j < L; j++) {
            for(h = j + 1; h < L; h++) {
                if(arr[v[j]][v[h]]==0) {
                    mr = -9;
                    break;
                }
            }
            if(mr < 0) break;
        }
        if(mr < 0) {
            printf("Area %d needs help.\n", i);
            continue;
        }
        for(j = 1; j <= N; j++) {
            if(ump[j] == 1) continue;
            mr = 9;
            for(h = 0; h < L; h++) {
                if(arr[j][v[h]]==0) {
                    mr = -9;
                    break;
                }
            }
            if(mr > 0) {
                kk = -9;
                break;
            }
        }
        if(kk < 0) {
            printf("Area %d may invite more people, such as %d.\n", i, j);
            continue;;
        }
        printf("Area %d is OK.\n", i);
    }
    return 0;
}


old before
#include<iostream>
#include<vector>
#include<set>
using namespace std;
struct nod {int l, r;};
int main(void) {
    int i, j, k, m, n, x1, x2, ori;
    cin>>m>>n;
    bool arr[209][209] = {false};
    vector<nod> vt;
    nod nd;
    for(i = 0; i < n; i++) {
        cin>>nd.l>>nd.r;
        arr[nd.l][nd.r] = arr[nd.r][nd.l] = true;
        vt.push_back(nd);
    }
    cin>>n;
    for(i = 0; i < n; i++) {
        cin>>k;
        set<int> st, st0;
        vector<int> v, v0;
        int mr = -9;
        for(j = 0; j < k; j++) {
            cin>>x1;
            v0.push_back(x1);
            st0.insert(x1);
        }
        for(j = 0; j < k; j++) {
            for(x1 = j+1; x1< k; x1++) {
                if(arr[v0[j]][v0[x1]]==false){
                    mr = 9;
                    printf("Area %d needs help.\n", i+1);
                    break;
                }
            }
            if(mr > 0) break;
        }
        if(mr > 0) continue;
        int kk = -9;
        for(j = 1; j <=m; j++) {
            if(st0.find(j)!=st0.end()) continue;
            mr = -9;
            for(x1 = 0; x1 < v0.size(); x1++) {
                if(arr[v0[x1]][j]==false) {
                    mr = 9; 
                    break;
                }
            }
            if(mr < 0) {
                kk = 9;
                printf("Area %d may invite more people, such as %d.\n", i+1, j);
                break;
            }
        }
        if(kk > 0) continue;
        printf("Area %d is OK.\n", i+1);
    }
    return 0;
}
