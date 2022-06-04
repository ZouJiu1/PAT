#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    long long n, num, maxmax=-2000000000, minmin=2000000000;
    vector<long long> vec, res, mx, mn;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num;
        vec.push_back(num);
        if(num>maxmax)
            maxmax = num;
        mx.push_back(maxmax);
    }
    for(int i=n-1; i>=0; i--){
        if(vec[i]<minmin)
            minmin = vec[i];
        mn.push_back(minmin);
    }
    reverse(mn.begin(), mn.end());
    for(int i=0; i<n; i++){
        if(i!=0)
            maxmax = mx[i-1];
        else
            maxmax = mx[i];
        if(i!=(n-1))
            minmin = mn[i+1];
        else
            minmin = mn[n-1];
        if(maxmax<=vec[i]&&minmin>=vec[i])
            res.push_back(vec[i]);
    }
    sort(res.begin(), res.end());
    cout<<res.size()<<endl;
    for(int i=0; i<res.size(); i++){
        cout<<res[i];
        if(i!=(res.size()-1))
            cout<<" ";
    }
    cout<<endl;
    return 0;
}
