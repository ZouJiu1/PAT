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
