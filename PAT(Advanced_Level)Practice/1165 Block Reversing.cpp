old before
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct nod{int a, d, n;};
int main(void) {
    int i, j, k, m, n, x1, x2, cnt = 0;
    nod arr[100001];
    cin>>k>>m>>n;
    vector<vector<nod>> v;
    vector<nod> vv;
    nod nd;
    v.resize(m/n + 1);
    for(i = 0; i < m; i++) {
        cin>>x1;
        cin>>arr[x1].d>>arr[x1].n;
        arr[x1].a = x1;
    }
    while(k!=-1) {
        nd.d = arr[k].d;
        nd.n = arr[k].n;
        nd.a = arr[k].a;
        v[cnt++/n].push_back(nd);
        k = arr[k].n;
    }
    reverse(v.begin(), v.end());
    for(i = 0; i < v.size(); i++)
        for(j = 0; j < v[i].size(); j++)
            vv.push_back(v[i][j]);
    for(i = 0; i < vv.size() - 1; i++) 
        printf("%05d %d %05d\n", vv[i].a, vv[i].d, vv[i+1].a);
    printf("%05d %d -1\n", vv[i].a, vv[i].d);
    return 0;
}

update202302
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct nod {int add, val, net; };
nod arr[100006];
int main(void) {
    int i, j, k, m, n, N, M, K, h, y, z, TAT;
    cin>>TAT>>N>>K;
    nod nd;
    for(i = 0; i < N; i++) {
        cin>>nd.add>>nd.val>>nd.net;
        arr[nd.add] = nd;
    }
    h = TAT;
    vector<nod> v, res;
    while(true) {
        if(h==-1) break;
        v.push_back(arr[h]);
        h = arr[h].net;
    }
    reverse(v.begin(), v.end());
    h = v.size()%K;
    for(i = 0; i < v.size()/K + int(h > 0); i++) {
        if(i==0 && h > 0) {
            for(j = h - 1; j>=0; j--) res.push_back(v[j]);
        }
        else if(h > 0) {
            for(j = h + K * i - 1; j >= h + K * (i-1); j--) res.push_back(v[j]);
        } else {
            for(j = K * (i+1) - 1; j >= K * i; j--) res.push_back(v[j]);
        }
    }
    for(i = 0; i < res.size() - 1; i++) {
        printf("%05d %d %05d\n", res[i].add, res[i].val, res[i+1].add);
    }
    printf("%05d %d -1\n", res[i].add, res[i].val);

    return 0;
}
