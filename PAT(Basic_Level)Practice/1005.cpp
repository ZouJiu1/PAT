#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<bits/stdc++.h>


using namespace std;


bool compare(const int a, const int b){
    return a>b;
}

int main(void){
    int n, num;
    vector<int> v, vx;
    set<int> se;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num;
        v.push_back(num);
    }
    for(int j=0; j<v.size(); j++){
        n = v[j];
        while (n!=1){
            if (n%2==0){
                n = n/2;
            }
            else{
                n=(3*n+1)/2;
            }
            se.insert(n);
        }
    }

    for(int i=0; i<v.size(); i++){
        set<int>::iterator it= se.find(v[i]);
        if(it==se.end())
            vx.push_back(v[i]);
    }
    sort(vx.begin(), vx.end(), compare);
    for(vector<int>::iterator tmp=vx.begin(); tmp!=vx.end(); tmp++){
        cout<<*tmp;
        if(tmp!=(vx.end()-1)){
            cout<<" ";
        }
    }
    return 0;
}
