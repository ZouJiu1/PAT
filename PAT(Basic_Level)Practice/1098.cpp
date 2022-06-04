#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, num, i, j, m, k, sub;
    cin>>n;
    vector<int> v9, v0;
    for(int i=0; i<n; i++){
        cin>>num;
        v0.push_back(num);
    }
    for(int i=0; i<n; i++){
        cin>>num;
        v9.push_back(num);
    }
    sort(v0.begin(), v0.end());
    sort(v9.begin(), v9.end());
    m = v9[v9.size()-1]; //max
    k = v0[0]; //min
    if(m>=k){
        cout<<"No "<<(m-k+1);
        return 0;
    }
    sub = k - m;
    cout<<"Yes "<<sub;
    return 0;
}
