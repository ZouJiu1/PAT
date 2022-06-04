#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, m, i, j, num;
    cin>>n>>m;
    vector<int> vec[n];
    int teacher[n];
    for(int i=0; i<n; i++){
        vector<int> vec0;
        for(int j=0; j<n; j++){
            cin>>num;
            if(num>m||num<0) continue;
            if(j==0) teacher[i] = num;
            else vec0.push_back(num);
        }
        vec[i] = vec0;
    }
    int sum;
    float avg;
    for(int i=0; i<n; i++){
        sort(vec[i].begin(), vec[i].end());
        sum = 0;
        vec[i].pop_back();
        vec[i].erase(vec[i].begin(), vec[i].begin()+1);
        for(int j=0; j<vec[i].size(); j++) sum += vec[i][j];
        avg = (float)sum / (float)vec[i].size();
        printf("%d\n", (int)round((avg+teacher[i])/2.0));
    }
    return 0;
}
