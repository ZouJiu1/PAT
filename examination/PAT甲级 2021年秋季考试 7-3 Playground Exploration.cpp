#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool status[106];
vector<int> v[106], t;
int sum, id, maxmax = -999999999;
void recursion(int tat) {
    status[tat] = true;
    sum++;
    t.push_back(tat);
    for(int i = 0; i < v[tat].size(); i++) {
        if(status[v[tat][i]]==true) continue;
        recursion(v[tat][i]);
        break;
    }
}
int main(void) {
    int i, j, k, m, n, N, M, K, maxmax=-999999999, num;
    cin>>N>>M;
    for(i = 0; i < M; i++) {
        scanf("%d %d", &m, &n);
        v[m].push_back(n);
        v[n].push_back(m);
    }
    for(i = 1; i <= N; i++) {
        sort(v[i].begin(), v[i].end());
    }
    for(i = 1; i <= N; i++) {
        sum = 0;
        fill(status, status+106, false);
        recursion(i);
        if(maxmax < sum) {
            maxmax = sum;
            id = i;
        }
    }
    printf("%d %d\n", id, maxmax);
    return 0;
}
