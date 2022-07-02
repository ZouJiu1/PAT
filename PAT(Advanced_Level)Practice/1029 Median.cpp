#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char **argv){
    int i, j, k, m, n, w;
    cin>>m;
    vector<int> v, v0;
    for(i=0; i<m; i++){
        cin>>n;
        v.push_back(n);
    }
    cin>>m;
    for(i=0; i<m; i++){
        cin>>n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());
    cout<<v[(int)((v.size()-1)/2)];
}
