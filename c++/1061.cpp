#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, m, num, sum;
    cin>>n>>m;
    vector<int> vec0, vec1, vec2;
    for(int i=0; i<m; i++){
        cin>>num;
        vec0.push_back(num);
    }
    for(int i=0; i<m; i++){
        cin>>num;
        vec1.push_back(num);
    }
    for(int i=0; i<n; i++){
        sum = 0;
        for(int j=0; j<m; j++){
            cin>>num;
            if(vec1[j]==num)
                sum+=vec0[j];
        }
        cout<<sum<<endl;
    }
    return 0;
}
