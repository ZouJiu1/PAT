#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
int arr[206][2], in[206], out[206];
bool cmp(string &a, string &c) {return a < c;};
int main(void) {
    int i, j, k, m, n, N, M, K, inf = 999999999;
    cin>>N>>M;
    for(i = 0; i < M; i++) {
        cin>>m>>n;
        out[m]++;
        in[n]++;
    }
    vector<string> v(N), r;
    for(i = 0; i < N; i++) {
        cin>>v[i];
    }
    for(i = 0; i < N; i++) {
        if(out[i] > in[i]) {
            r.push_back(v[i]);
        }
    }
    sort(r.begin(), r.end(), cmp);
    for(i = 0; i < r.size(); i++) cout<<r[i]<<endl;
    return 0;
}
