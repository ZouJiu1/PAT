#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

struct pailie{
    int sub;
    int cishud;
};
bool compare(const pailie a, const pailie b){
    return a.sub>b.sub;
}

int main(void){
    int n, i, j, num;
    cin>>n;
    vector<int> vec;
    vector<pailie> vec0;
    map<int, int> mp;
    for(int i=0; i<n; i++){
        cin>>num;
        mp[abs(i-num+1)] = 0;
        vec.push_back(num);
    }
    for(int i=0; i<n; i++){
        num = vec[i];
        mp[abs(i-num+1)]++;
    }
    pailie pl;
    for(map<int, int>::iterator it=mp.begin(); it!=mp.end(); it++){
        pl.sub = it->first;
        pl.cishud = it->second;
        vec0.push_back(pl);
    }
    sort(vec0.begin(), vec0.end(), compare);
    for(i=0; i<vec0.size(); i++){
        if(vec0[i].cishud>1)
            cout<<vec0[i].sub<<" "<<vec0[i].cishud<<endl;
    }
    return 0;
}
