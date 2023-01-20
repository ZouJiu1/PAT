update
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct nod {
    int add, nex;
    char a;
};
int main(void) {
    int i, j, k, m, n, N, start0, start1, status[100006];
    nod nd, arr[100006];
    vector<nod> v0, v1;
    cin>>start0>>start1>>N;
    fill(status, status + 100006, 0);
    for(i = 0; i < N; i++) {
        cin>>nd.add>>nd.a>>nd.nex;
        arr[nd.add] = nd;
    }
    while(true) {
        if(start0==-1) break;
        v0.push_back(arr[start0]);
        start0=arr[start0].nex;
    }
    while(true) {
        if(start1==-1) break;
        v1.push_back(arr[start1]);
        start1=arr[start1].nex;
    }
    for(i = 0; i < v0.size(); i++) {
        status[v0[i].add] = 1;
    }
    for(j = 0; j < v1.size(); j++) {
        if(status[v1[j].add]==1) {
            printf("%05d\n", v1[j].add);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}

old before
#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char **argv){
    char add[100003];
    int m, n, c, k, h, i, j, f;
    int w, t, x, y, z;
    int ind[100003];
    char ch;
    scanf("%d %d %d", &m, &n, &c);
    for(i = 0; i < c; i++){
        cin>>k>>ch>>f;
        add[k] = ch;
        ind[k] = f;
    }
    w = m;
    string s, s0;
    while(w!=-1){
        s += add[w];
        w = ind[w];
    }
    w = n;
    while(w!=-1){
        s0 += add[w];
        w = ind[w];
    }
    reverse(s.begin(), s.end());
    reverse(s0.begin(), s0.end());
    char tmp;
    int minmin = s.length() < s0.length()? s.length():s0.length();
    w = -1;
    for(i = 0; i < minmin; i++){
        if(s[i]==s0[i]){
            w = i;
            tmp = s[w];
        }
        if(s[i]!=s0[i]) break;
    }
    t = s.length() - w - 1;
    if(w < 0) cout<<"-1";
    else{
        x = m;
        for(i = 0; i < s.length(); i++){
            if(i == t) {
                printf("%05d", x);
                return 0;
            }
            x = ind[x];
        }
    }
    return EXIT_SUCCESS;
}
