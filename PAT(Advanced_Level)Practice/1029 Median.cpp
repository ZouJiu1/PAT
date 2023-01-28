update202301
可以直接用sort排序，不过题目的意思应该不是这个，所以用归并的思想，使用双指针，对序列进行排序，
某个指针指向end，就可以退出while，此时mid的position已经确定了
#include<iostream>
#include<vector>
using namespace std;
int main(void) {
    int i, j, k, m, n, N, M, y=0, z=0, res, mid, cnt = 0;
    cin>>N;
    vector<int> a0(N);
    for(i = 0; i < N; i++) scanf("%d", &a0[i]);
    cin>>M;
    vector<int> a1(M);
    for(j = 0; j < M; j++) scanf("%d", &a1[j]);
    mid = (N + M - 1) / 2;
    while(y < N && z < M) {
        if(a0[y] < a1[z]) {
            res = a0[y];
            y++;
        }
        else {
            res = a1[z];
            z++;
        }
        if(y + z > mid) break;
    }
    if(y < N  && y + z <= mid) {
        res = a0[mid - z];
    }
    else if(z < N && y + z <=mid) {
        res = a1[mid - y];
    }
    cout<<res<<endl;
    return 0;
}

old before
#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char **argv){
    int i, j, k, m, n, w;
    cin>>m;
    vector<int> v, v0;
    for(i=0; i<m; i++){
        cin>>n;
        v.push_back(n);
    }
    cin>>m;
    for(i=0; i<m; i++){
        cin>>n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());
    cout<<v[(int)((v.size()-1)/2)];
}
