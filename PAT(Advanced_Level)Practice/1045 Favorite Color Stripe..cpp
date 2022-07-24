#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int i, j, k, m, n, h=0, maxnum = -99999999;
    cin>>m;
    cin>>n;
    int book[201], a[10001], dp[10001];
    memset((void *)book, 0, sizeof(int)*201);
    memset((void *)a, 0, sizeof(int)*10001);
    memset((void *)dp, 0, sizeof(int)*10001);
    for(i = 1; i <= n; i++){
        cin>>k;
        book[k] = i;
    }
    cin>>n;
    for(i = 0; i < n; i++){
        cin>>k;
        if(book[k] >= 1){
            a[h++] = book[k];
        }
    }
    for(i = 0; i <= h; i++){
        dp[i] = 1;
        for(j = 0; j < i; j++){
            if(a[i] >= a[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxnum = max(maxnum, dp[i]);
    }
    printf("%d", maxnum);
    return 0;
}
/*
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int i, j, k, m, n, h, maxnum = -99999999, cnt;
    cin>>m;
    cin>>n;
    vector<int> v, v0, v00;
    set<int> st;
    set<int>::iterator it;
    map<int, int> mp;
    v.resize(n);
    for(i = 0; i < n; i++){
        cin>>k;
        v[i] = k;
        st.insert(k);
        mp[k] = i;
    }
    cin>>n;
    h = -999;
    cnt = 0;
    for(i = 0; i < n; i++){
        cin>>k;
        it = st.find(k);
        if(it!=st.end()){
            if(h!=k){
                v0.push_back(k);
                h = k;
                if(i!=0) v00.push_back(cnt);
                cnt = 1;
            }else{
                cnt++;
            }
        }
    }
    v00.push_back(cnt);
    vector<int> vtr, vtr0;
    int dp[10001];
    for(i = 0; i < v0.size(); i++){
        dp[i] = v00[i];
        for(j = 0; j < i; j++){
            if(mp[v0[i]] > mp[v0[j]]){
                dp[i] = max(dp[i], (dp[j] + v00[i]));
            }
        }
        maxnum = max(maxnum, dp[i]);
    }
    printf("%d", maxnum);
    return 0;
}
*/
