update202302    累加，两种情况一种从小到大，一种从大到小
#include<iostream>
#include<vector>
using namespace std;
int main(void) {
    int i, j, k, N, M, K, y, z, r;
    cin>>N;
    vector<int> v(N+1), arr(N+2, 0);
    for(i = 1; i <= N; i++) {
        scanf("%d", &v[i]);
        arr[i+1] = v[i] + arr[i];
    }
    cin>>M;
    for(i = 0; i < M; i++) {
        cin>>y>>z;
        r = y > z? y : z;
        y = y + z - r;
        int sum2 = arr[N] - arr[r] + arr[y] - arr[1] + v[N];
        int sum1 = arr[r] - arr[y];
        printf("%d\n", sum1<sum2? sum1:sum2);
    }
    return 0;
}
or
#include<iostream>
#include<vector>
using namespace std;
int main(void) {
    int i, j, k, N, M, K, y, z, r;
    cin>>N;
    vector<int> v(N+1), arr(N+2, 0);
    for(i = 1; i <= N; i++) {
        scanf("%d", &v[i]);
        arr[i+1] = v[i] + arr[i];
    }
    cin>>M;
    for(i = 0; i < M; i++) {
        cin>>y>>z;
        r = y > z? y : z;
        y = y + z - r;
        int sum = arr[r] - arr[y];
        printf("%d\n", min(sum, arr[N+1] - sum));
    }
    return 0;
}



old before
#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int i, j, k, m, n, h, mm, nn;
    cin>>m;
    vector<int> exits, allexit, cumsum;
    exits.resize(m + 1);
    cumsum.resize(m + 1);
    cumsum[0] = 0;
    for(i=1; i<=m; i++){
        cin>>n;
        exits[i] = n;
        cumsum[i] = n + cumsum[i - 1];
    }
    cin>>m;
    for(i=1; i<=m; i++){
        cin>>n>>h;
        allexit.push_back(n);
        allexit.push_back(h);
    }
    int minmin, maxmax, tmp, tmp0, tmp00, sizes;
    sizes = exits.size();
    for(i = 0; i < m; i++){
        mm = allexit[2 * i];
        nn =  allexit[2 * i + 1];
        maxmax = max(mm, nn);
        minmin = min(mm, nn);
        tmp = cumsum[maxmax - 1] - cumsum[minmin - 1];
        tmp0 = cumsum[sizes - 2] - cumsum[maxmax - 1] + exits[sizes - 1];
        tmp00 = cumsum[minmin - 1];
        tmp = min(tmp, tmp0 + tmp00);
        cout<<tmp<<endl;
    }
    return 0;
}
