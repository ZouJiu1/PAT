/*
依次执行的，不要考虑最优，而且存在相邻指令相同的情况这个时候要+5 
*/
update202302
#include<iostream>
using namespace std;
int main(void) {
    int i, j, k, N, M, K, sum = 0, pre;
    cin>>N;
    for(i = 0; i < N; i++) {
        cin>>k;
        if(i==0) sum += k * 6 + 5;
        else {
            if(k > pre) sum += (k - pre) * 6 + 5;
            else if(k == pre) sum += 5;
            else sum += (pre - k) * 4 + 5;
        }
        pre = k;
    }
    printf("%d", sum);
    return 0;
}


old before
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, m, i, j, k;
    cin>>n;
    vector<int> vec;
    set<int> st;
    vec.push_back(0);
    for(int i=0; i<n; i++){
        cin>>m;
        vec.push_back(m);
    }
    k = 0;
    for(int i=0; i<n; i++){
        if(vec[i+1]>vec[i])
            k += (vec[i+1]-vec[i])*6 + 5;
        else if(vec[i+1]<vec[i])
            k += abs(vec[i+1]-vec[i])*4 + 5;
        else
            k += 5;
    }
    cout<<k;
    return 0;
}

