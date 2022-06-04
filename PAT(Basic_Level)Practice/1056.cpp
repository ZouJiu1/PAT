#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, num, sum=0;
    cin>>n;
    vector<int> vec;
    for(int i=0; i<n; i++){
        cin>>num;
        vec.push_back(num);
    }
    for(int i=0; i<n; i++){
        num = vec[i]*10;
        for(int j=0; j<n; j++){
            if(i==j){
                continue;
            }
            sum += vec[j] + num;
        }
    }
    cout<<sum<<endl;
    return 0;
}
