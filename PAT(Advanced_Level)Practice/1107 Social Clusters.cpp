update202301，并查集两种方式或者DFS，问题是对人提问，要么直接将爱好对应到人然后并查集；要么对爱好进行并查集，最后对应到人；
要么DFS对爱好聚簇，然后对应到人
update202301，并查集方式1：这里将爱好对应到每个人，然后人放到并查集，数每个簇的人个数以及簇个数
直接用map进行计数不用单独看根节点个数
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

update202302，并查集方式2：这里将爱好放到并查集，然后将每个人对应到个人的第一个爱好的根节点，这样计数每个人的爱好根节点即可
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;
int arr[1006], person[1006];
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
    vector<int> vk[1006];
    for(i = 0; i < 1006; i++) arr[i] = i;
    for(i = 1; i <= N; i++) {
        scanf("%d:", &k);
        for(j = 0; j < k; j++) {
            cin>>z;
            vk[i].push_back(z);
            if(j > 0) unionjoin(z, pre);
            pre = z;
        }
    }
    for(i = 1; i <= N; i++) {
        if(vk[i].size() > 0) person[i] = findfather(vk[i][0]);
    }
    for(i = 1; i <= N; i++) res[person[i]]++;
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

update202301，DFS
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<set>
using namespace std;
int arr[1006], person[1006], status[1006], cnt = 0;
unordered_map<int, int> ump, res;
vector<int> vk[1006], tp[1006];
void recursion(int rot) {
    if(status[rot]==1) return;
    arr[rot] = cnt;
    status[rot] = 1;
    for(int i = 0; i < vk[rot].size(); i++) {
        if(status[vk[rot][i]]==0) recursion(vk[rot][i]);
    }
}
int main(void) {
    int i, j, k, m, N, K, y, z, pre;
    cin>>N;
    set<int> st;
    for(i = 0; i < 1006; i++) arr[i] = i;
    for(i = 1; i <= N; i++) {
        scanf("%d:", &k);
        for(j = 0; j < k; j++) {
            cin>>z;
            if(j!=0) {
                vk[z].push_back(pre);
                vk[pre].push_back(z);
            }
            pre = z;
            st.insert(z);
            tp[i].push_back(z);
        }
    }
    for(auto it:st) {
        if(status[it]==0) {
            recursion(it);
            cnt++;
        }
    }
    for(i = 1; i <= N; i++) {
        if(tp[i].size() > 0) person[i] = arr[tp[i][0]];
    }
    for(i = 1; i <= N; i++) res[person[i]]++;
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
