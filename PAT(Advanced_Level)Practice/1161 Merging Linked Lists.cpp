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
