//BFS  使用DFS的话会报错，可能是递归的层数太多导致栈出问题了，使用BFS才可以AC
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
bool arr[66][1300][130]={false}, status[66][1300][130]={false};
int num, allnum = 0, K, N, M, L, T;
struct nod {int k, i, j;};
int width_firstly_search(int k, int i, int j) {
    queue<nod>q;
    nod nd = {k, i, j};
    q.push(nd);
    int ww = 0;
    while(!q.empty()) {
        nd = q.front();
        q.pop();
        bool kk = true;
        if(nd.k < 0 || nd.k >=L || nd.i < 0 || nd.i >= M || nd.j < 0 || nd.j >= N 
            || status[nd.k][nd.i][nd.j]==true || arr[nd.k][nd.i][nd.j]==false) continue;
        status[nd.k][nd.i][nd.j] = true;
        q.push(nod{nd.k - 1, nd.i, nd.j});
        q.push(nod{nd.k + 1, nd.i, nd.j});
        q.push(nod{nd.k, nd.i - 1, nd.j});
        q.push(nod{nd.k, nd.i + 1, nd.j});
        q.push(nod{nd.k, nd.i, nd.j - 1});
        q.push(nod{nd.k, nd.i, nd.j + 1});
        ww++;
    }
    return ww;
}
int main(void) {
    int i, j, k, m, n, kk;
    cin>>M>>N>>L>>T;
    for(k = 0; k < L; k++) {
        for(i = 0; i < M; i++) {
            for(j = 0; j < N; j++) {
                scanf("%d", &kk);
                arr[k][i][j] = kk==1;
            }
        }
    }
    for(k = 0; k < L; k++) {
        for(i = 0; i < M; i++) {
            for(j = 0; j < N; j++) {
                if(status[k][i][j]==false && arr[k][i][j]==true) {
                    num = width_firstly_search(k, i, j);
                    if(num >= T) allnum += num;
                }
            }
        }
    }
    printf("%d\n", allnum);
    return 0;
}


这里也贴出相应DFS的codes

//DFS
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
bool arr[66][1300][130]={false}, status[66][1300][130]={false};
int num, allnum = 0, K, N, M, L, T;
void recursion(int k, int i, int j) {
    if(k < 0 || k >=L || i < 0 || i >= M || j < 0 || j >= N || status[k][i][j]==true || arr[k][i][j]==false) return;
    status[k][i][j] = true;
    num++;
    if(k-1 >= 0 || k-1 < L) recursion(k - 1, i, j);
    if(k+1 >= 0 || k+1 < L) recursion(k + 1, i, j);
    if(i-1 >= 0 || i-1 < M) recursion(k, i - 1, j);
    if(i+1 >= 0 || i+1 < M) recursion(k, i + 1, j);
    if(j-1 >= 0 || j-1 < N) recursion(k, i, j - 1);
    if(j+1 >= 0 || j+1 < N) recursion(k, i, j + 1);
}
int main(void) {
    int i, j, k, m, n, kk;
    cin>>M>>N>>L>>T;
    for(k = 0; k < L; k++) {
        for(i = 0; i < M; i++) {
            for(j = 0; j < N; j++) {
                scanf("%d", &kk);
                arr[k][i][j] = kk==1;
            }
        }
    }
    for(k = 0; k < L; k++) {
        for(i = 0; i < M; i++) {
            for(j = 0; j < N; j++) {
                if(status[k][i][j]==false && arr[k][i][j]==true) {
                    num = 0;
                    recursion(k, i, j);
                    if(num >= T) allnum += num;
                }
            }
        }
    }
    printf("%d\n", allnum);
    return 0;
}
