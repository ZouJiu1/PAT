old before
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct nod {int next, val;};
int main(void) {
    int i, j, k, m, n, x1, x2, x6, cnt = 0;
    nod arr[100006] = {0};
    cin>>k>>m>>n;
    for(i = 0; i < n; i++) {
        cin>>x1>>x2>>x6;
        arr[x1].val = x2;
        arr[x1].next = x6;
    }
    vector<int> v1, v2, v;
    while(k!=-1) {
        v1.push_back(k);
        k = arr[k].next;
    }
    while(m!=-1) {
        v2.push_back(m);
        m = arr[m].next;
    }
    if(v1.size() < v2.size()) {
        v = v1;
        v1 = v2;
        v2 = v;
    }
    reverse(v2.begin(), v2.end());
    for(j = 0; j < v1.size(); j++)
        if(j%2==1 && cnt < v2.size()) v1.insert(v1.begin() + j + (++cnt), v2[cnt]);
    for(i = 0; i < v1.size() - 1; i++)
        printf("%05d %d %05d\n", v1[i], arr[v1[i]].val, v1[i+1]);
    printf("%05d %d -1\n", v1[i], arr[v1[i]].val);
    return 0;
}

update202302
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct nod{int add, val, net;};
nod arr[100006];
int main(void) {
    int i, j, k, m, n, N, M, K, h, y, z, T0, T1;
    nod nd;
    cin>>T0>>T1>>N;
    for(i = 0; i < N; i++) {
        scanf("%d %d %d", &nd.add, &nd.val, &nd.net);
        arr[nd.add] = nd;
    }
    vector<nod> v0, v1, v2, r;
    while(true) {
        if(T0==-1) break;
        v0.push_back(arr[T0]);
        T0 = arr[T0].net;
    }
    while(true) {
        if(T1==-1) break;
        v1.push_back(arr[T1]);
        T1 = arr[T1].net;
    }
    if(v0.size() > v1.size()) v2 = v0;
    else {
        v2 = v1;
        v1 = v0;
    }
    reverse(v1.begin(), v1.end());
    y = z = 0;
    for(i = 0; i < v2.size(); i++) {
        if((i+1)%2==0 && z < v1.size()){
            r.push_back(v2[i]);
            r.push_back(v1[z++]);
        } else r.push_back(v2[i]);
    }
    for(i = 0; i < r.size() - 1; i++) {
        printf("%05d %d %05d\n", r[i].add, r[i].val, r[i+1].add);
    }
    printf("%05d %d -1\n", r[i].add, r[i].val);
    return 0;
}
