update202301，直接用map进行计数不用单独看根节点个数
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;
int arr[1006], hob[1006];
unordered_map<int, int> ump, res;
int findfather(int a) {
    int tmp = a;
    while(a!=arr[a]) a = arr[a];
    arr[tmp] = a;
    return a;
}
void unionjoin(int a, int c) {
    int A = findfather(a);
    int C = findfather(c);
    if(A >= C) arr[A] = C;
    else arr[C] =A;
}
int main(void) {
    int i, j, k, m, N, K, y, z, pre;
    cin>>N;
    for(i = 0; i < 1006; i++) arr[i] = i;
    for(i = 1; i <= N; i++) {
        scanf("%d:", &k);
        for(j = 0; j < k; j++) {
            cin>>z;
            if(ump[z]==0) ump[z] = i;
            unionjoin(ump[z], i);
        }
    }
    for(i = 1; i <= N; i++) res[findfather(i)]++;
    vector<int> v;
    for(auto it:res) v.push_back(it.second);
    printf("%d\n", v.size());
    sort(v.begin(), v.end());
    for(i = v.size() - 1; i >= 0; i--) {
        printf("%d", v[i]);
        if(i!=0) printf(" ");
    }
    return 0;
}


old before
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

vector<int> joinfind;

int findfather(int a) {
    int xx, tmp;
    xx = tmp = a;
    while(a!=joinfind[a]) a = joinfind[a];
    //表的路径压缩
    while(tmp!=joinfind[tmp]) {
        int z = tmp;
        tmp = joinfind[tmp];
        joinfind[z] = a;
    }
    return a;
}

void unions(int a, int c) {
    int x = findfather(a);
    int y = findfather(c);
    if(x!=y) joinfind[x] = y;
}

bool compare(int &a, int &c) {
    return a > c;
}

int main(void){
    int i, j, m, n, k, w, q, x, y;
    cin>>m;
    vector<int> hm;
    vector<int> findroot;
    findroot.resize(m + 1);
    joinfind.resize(m + 1);
    hm.resize(1003);
    for(i = 0; i < 1003; i++) hm[i] = 0;
    for(i = 1; i <= m; i++) {
        joinfind[i] = i;
        findroot[i] = 0;
    }
    for(i = 1; i <= m; i++) {
        scanf("%d:", &n);
        for(j = 0; j < n; j++) {
            cin>>k;
            if(hm[k]==0)
                hm[k] = i;
            unions(i, findfather(hm[k]));
        }
    }
    for(i = 1; i <= m; i++) {
        findroot[findfather(i)]++;
    }
    sort(findroot.begin(), findroot.end(), compare);
    int cnt = 0;
    for(i = 0; i < m; i++) {
        if(findroot[i]==0) break;
        cnt++;
    }
    printf("%d\n", cnt);
    for(i = 0; i < cnt; i++) {
        printf("%d", findroot[i]);
        if(i!=cnt - 1) printf(" ");
    }
    return 0;
}

update 1
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

int arr[1006], reflect[1006];

int findfather(int a) {
    int tmp = a;
    while(arr[a]!=a) a = arr[a];
    arr[tmp] = a;
    return a;
}
void unionjoin(int a, int c) {
    int aa = findfather(a);
    int cc = findfather(c);
    if(aa != cc) arr[aa] = cc;
}
bool compare(int a, int c) {return a > c;};
int main(int argc, char **argv) {
    int i, j, k, m, n, y, z;
    cin>>m;
    fill(reflect, reflect+1006, 0);
    for(i = 0; i < 1006; i++) arr[i] = i;
    for(i = 1; i <= m; i++) {
        scanf("%d:", &n);
        for(j = 0; j < n; j++) {
            cin>>k;
            if(reflect[k]==0)
                reflect[k]=i;
            unionjoin(i, findfather(reflect[k]));
        }
    }
    z = 0;
    map<int, int> mp;
    for(i = 1; i <= m; i++) {
        if(findfather(i)==i) z++;
        mp[findfather(i)]++;
    }
    vector<int> v;
    for(map<int, int>::iterator it=mp.begin(); it!=mp.end(); it++) {
        v.push_back(it->second);
    }

    sort(v.begin(), v.end(), compare);
    printf("%d\n%d", z, v[0]);
    for(i = 1; i < v.size(); i++) printf(" %d", v[i]);
    return EXIT_SUCCESS;
}
