#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;
struct nodes{
    int num;
    double price;
    double unit;
};
bool compare_reverse(const nodes &a, 
                        const nodes &b){
    return a.unit >= b.unit;
}

int main(void){
    int N, D, s1, s2, i;
    cin>>N>>D;
    vector<int> vec0;
    vector<nodes> mp;
    nodes nd;
    double s0;
    for(i=0; i<N; i++){
        cin>>s0;
        vec0.push_back(s0);
    }
    for(i=0; i<N; i++){
        cin>>s0;
        nd.num = vec0[i];
        nd.price = s0;
        nd.unit   = (double)s0/(double)vec0[i];
        mp.push_back(nd);
    }
    sort(mp.begin(), mp.end(), compare_reverse);
    float sum = 0;
    for(i=0; i<N; i++){
        if(D==0) break;
        if(mp[i].num <= D){
            sum += mp[i].price;
            D -= mp[i].num;
        }else{
            sum += mp[i].unit * D;
            D = 0;
        }
    }
    printf("%.2f\n", sum);
    return 0;
}
