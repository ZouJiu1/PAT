#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, m, res, i, j;
    cin>>n>>m;
    vector<int> vec[10001], vec0, tmp;
    for(j = 0; j < m; j++){
        for(i=0; i<n; i++){
            cin>>res;
            vec[j].push_back(res);
        }
    }
    for(j = 0; j < n; j++){
        res = 0;
        for(i = 0; i < m; i++){
            res += vec[i][j];
        }
        vec0.push_back(res);
    }
    tmp = vec0;
    sort(vec0.begin(), vec0.end());
    res = vec0[vec0.size() - 1];
    cout<<res<<endl;
    vec0 = tmp;
    vector<int> net;
    for(i = 0; i < vec0.size(); i++){
        if(res==vec0[i]) net.push_back(i+1);
    }
    for(i = 0; i<net.size(); i++){
        cout<<net[i];
        if((i+1)!=net.size()) cout<<" ";
    }
    return 0;
}
