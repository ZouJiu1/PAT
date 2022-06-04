#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, k, x, num, i, j, m;
    cin>>n>>k>>x;
    vector<int> vec[n];
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            cin>>num;
            vec[i].push_back(num);
        }
    }
    j = 1;
    for(i = 0; i < n; i++){
        if((i+1)%2==1){
            if(j==(k+1)) j = 1;
            for(m = 0; m < j; m++){
                vec[i].pop_back();
                vec[i].insert(vec[i].begin(), x);
            }
            j++;
        }
    }
    vector<int> sum;
    for(i = 0; i < n; i++){
        m = 0;
        for(j = 0; j < n; j++){
            m += vec[j][i];
        }
        sum.push_back(m);
    }
    for(i = 0; i < n; i++){
        cout<<sum[i];
        if(i!=(n-1)) cout<<" ";
    }
    return 0;
}
