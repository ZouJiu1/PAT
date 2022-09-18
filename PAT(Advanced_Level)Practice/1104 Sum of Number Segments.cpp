#include<iostream>
#include<vector>
using namespace std;

int main(void) {
    int i, j, m, n;
    double k, all = 0;
    cin>>m;
    vector<double> v, sum;
    sum.resize(m+1);
    sum[m] = 0;
    for(i = 0; i < m; i++) {
        cin>>k;
        v.push_back(k);
    }
    for(i = m - 1; i >= 0; i--) sum[i] = (m - i) * v[i] + sum[i + 1];
    for(i = 0; i < m; i++)  all += sum[i];
    printf("%.2f", all);
}
