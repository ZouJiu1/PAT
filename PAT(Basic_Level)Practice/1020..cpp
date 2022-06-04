#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

bool compare_reverse(pair<int, float> &a, 
                        pair<int, float> &b){
    return a.second >= b.second;
}

int main(void){
    int N, D, s0, s1, s2, i;
    cin>>N>>D;
    vector<int> vec0[2];
    vector<pair<int, float>> mp;
    for(i=0; i<N; i++){
        cin>>s0;
        vec0[0].push_back(s0);
    }
    for(i=0; i<N; i++){
        cin>>s0;
        vec0[1].push_back(s0);
        mp.push_back({i, (float)s0/(float)vec0[0][i]});
    }
    sort(mp.begin(), mp.end(), compare_reverse);
    float sum = 0;
    for(i=0; i<N; i++){
        s0 = vec0[0][mp[i].first];
        s1 = vec0[1][mp[i].first];
        if(D<s0){
            sum += D * mp[i].second;
            break;
        }
        else{
            sum += (float)s1;
            D -= s0;
        }
    }
    printf("%.2f\n", sum);
    return 0;
}
