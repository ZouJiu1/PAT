堆优化的队列，priority_queue最开始的那个值就是最小值，产生最小的堆greater<int>
进来值<pop出去值，进来值run加一暂时不参加排序，也就是queue数组的index + 1
while(!pq[run].empty())循环内不存在for或者while等循环，所以当前的pq[run]个数+pq[run+1]的个数一直都是固定的M
  
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> v, tp[100];
int main(void) {
    int i, j, k, N, M, K, y, z, mr = 9, cnt, run = 0, ww = 0;
    cin>>N>>M;
    for(i = 0; i < N; i++) {
        scanf("%d", &k);
        v.push_back(k);
    }
    priority_queue<int, vector<int>, greater<int>> pq[100];
    for(i = 0; i < min(M, (int)v.size()); i++) pq[run].push(v[i]);
    cnt = pq[run].size();
    while(!pq[run].empty()) {
        z = pq[run].top();
        tp[run].push_back(z);
        pq[run].pop();
        if(cnt < v.size() && v[cnt] < z) {   //放到下一个run
            pq[run + 1].push(v[cnt++]);
        }
        else if(cnt < v.size()) {
            pq[run].push(v[cnt++]);
        }
        if(pq[run].empty()) {   //当前run全部空以后，run+1
            run++;
        }
    }
    for(i = 0; i < 100; i++) {
        for(j = 0; j < tp[i].size(); j++) {
            printf("%d", tp[i][j]);
            if(j!=tp[i].size() - 1) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}
