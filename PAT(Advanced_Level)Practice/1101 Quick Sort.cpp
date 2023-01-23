update2 

#include<iostream>
#include<vector>
using namespace std;
int main(void) {
    int i, j, k, m, n, N, minval = 999999999, maxval = -999999999;
    cin>>N;
    vector<int> v(N), res, maxmax(N), minmin(N);
    for(i = 0; i < N; i++) {
        scanf("%d", &v[i]);
        if(maxval < v[i]) maxval = v[i];
        maxmax[i] = maxval;
    }
    for(i = N-1; i >= 0; i--) {
        if(minval > v[i]) minval = v[i];
        minmin[i] = minval;
    }
    for(i = 0; i < N; i++) {
        if(v[i] >= maxmax[i] && v[i] <= minmin[i]) res.push_back(v[i]);
    }
    printf("%d\n", res.size());
    for(i = 0; i < res.size(); i++) {
        printf("%d", res[i]);
        if(i!=res.size()-1) printf(" ");
    }
    printf("\n");
    return 0;
}

update1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(int argc, char **argv) {
    int m, n, i, mx = -999999999, mn = 999999999;
    cin>>m;
    vector<int> res, v(m), maxmax(m), minmin(m);
    for(i = 0; i < m; i++) {
        cin>>v[i];
        if(mx < v[i]) mx = v[i];
        maxmax[i] = mx;
    }
    for(i = m - 1; i >= 0; i--) {
        if(mn > v[i]) mn = v[i];
        minmin[i] = mn;
    }
    n = 0;
    for(i = 0; i < m; i++) {
        if(v[i] >= maxmax[i] && v[i] <= minmin[i]){
            n++;
            res.push_back(v[i]);
        }
    }
    sort(res.begin(), res.end());
    printf("%d\n", n);
    if(n>0) printf("%d", res[0]);
    else printf("\n");
    for(i = 1; i < res.size(); i++) printf(" %d", res[i]);
    return EXIT_SUCCESS;
}
