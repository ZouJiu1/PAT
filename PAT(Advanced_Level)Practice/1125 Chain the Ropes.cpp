#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

bool compare(const int a, const int b){
    return a<b;
}

int main(void){
    int n, num;
    double sum, sum0;
    cin>>n;
    vector<int> vec;
    for(int i=0; i<n; i++){
        cin>>num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end(), compare);
    sum = vec[0];
    for(int i=1; i<n; i++){
        sum = (sum+vec[i])/(double)2.0;
    }
    cout<<floor(sum)<<endl;
    return EXIT_SUCCESS;
}
