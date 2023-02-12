#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
int main(void) {
    int i, j, k, m, n, N, M, K, maxmax=-999999999, num;
    cin>>N;
    vector<int> hat(N), peo(N), ht(N), pe(N), r;
    unordered_map<int, int> ump, indht, indpe;
    for(i = 0; i < N; i++) {
        scanf("%d", &hat[i]);
    }
    ht = hat;
    sort(hat.begin(), hat.end());
    for(i = 0; i < N; i++) {
        indht[hat[i]] = i;
    }
    for(i = 0; i < N; i++) {
        scanf("%d", &peo[i]);
        ump[peo[i]] = i;
    }
    pe = peo;
    sort(peo.begin(), peo.end());
    for(i = 0; i < N; i++) {
        indpe[peo[i]] = i;
    }
    for(i = N-1; i >= 0; i--) {
        k = indht[ht[i]];
        r.push_back(ump[peo[k]]);
    }
    for(i = 0; i < r.size(); i++) {
        printf("%d", r[i]+1);
        if(i!=r.size()-1) printf(" ");
    }
    return 0;
}
