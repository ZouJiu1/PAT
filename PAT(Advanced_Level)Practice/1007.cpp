/*
要用到dynamic programming，动态规划的，若是不使用动态规划，
时间复杂度会变为O(n^3)，用了以后变到了O(n^2)，注意内存使用，
循环里使用数组会导致内存多，所以直接使用标量记录最大值即可, 注意sum==maxmax
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

struct indexes{
    int ind0;
    int ind2;
    int max;
};

int main(void){
    int n, m, i, j, k;
    vector<int> vec, vec0;
    cin>>n;
    k = 666;
    for(i = 0; i < n; i++){
        cin>>m;
        if(m>=0) {k = -666;}
        vec.push_back(m);
    }
    if(k>0) {
        cout<<0<<" "<<vec[0]<<" "<<vec[vec.size()-1]<<endl;
        return 0;
    }
    int sum, maxmax = -666666, par=1, counts = 0, first, last;
    vector<int> tor[2];
    vector<indexes> lis;
    indexes ide;
    for(i = 0; i < n; i++) tor[0].push_back(0);
    for(j = 0; j < n; j++){
        counts = 0;
        for(i = par - 1; i < n; i++){
            sum = vec[i] + tor[(par-1)%2][counts++];
            tor[par%2].push_back(sum);
            if(sum<0) continue;
            if(sum>maxmax){
                first = i - par + 1;
                last = i;
                maxmax = sum;
            }else if(sum==maxmax){
                if(first > (i-par+1)){
                    first = i - par + 1;
                    last = i;
                    maxmax = sum;
                }
            }
        }
        tor[(par-1)%2].erase(tor[(par-1)%2].begin(), tor[(par-1)%2].end());
        par++;
    }
    
    cout<<maxmax<<" "<<vec[first]<<" "<<vec[last];
    return 0;
}
