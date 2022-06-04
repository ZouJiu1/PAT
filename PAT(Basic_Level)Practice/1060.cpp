#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>


using namespace std;

bool compare(const int a, const int b){
    return a>b;
}

int main(void){
    int n, num, max = -666;
    cin>>n;
    map<int, int> mp, mp0;
    vector<int> vec;
    for(int i=0; i<n; i++){
        cin>>num;
        mp[num] = 0;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end(), compare);
    for(int i=0; i<n; i++){
        mp[vec[i]] += 1;
    }
    for(int i=n; i>=0; i--){
        num = 0;
        for(int j=0; j<n; j++){
            if(vec[j]>i)
                num++;
            if(vec[j]==i)
                break;
        }
        if(num<i)
            continue;
        mp0[i] = num;
        cout<<i;
        return 0;
    }
}
