#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

bool compare(const long long &a, const long long &b){
    return a < b;
}

int main(void){
    long long num, p;
    int i, N, j;
    cin>>N>>p;
    vector<long long> vec;
    for(i=0; i<N; i++){
        cin>>num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end(), compare);
    int tmp=0, result = 0;
    for(i = 0; i<N; i++){
        for(j=i+result; j<N; j++){
            if(vec[j]<=vec[i]*p)
            {
                tmp = j-i+1;
                if(result<tmp)
                    result = tmp;
            }else{
                break;
            }
        }
    }
    // for(i = N-1; i>=0; i--){
    //     for(j=0; j<i-result; j++){
    //         if(vec[i]<=vec[j]*p)
    //         {
    //             tmp = i-j+1;
    //             if(result<tmp)
    //                 result = tmp;
    //             break;
    //         }
    //     }
    // }
    // if(result==0)
    //     result=1;
    cout<<result<<endl;
    return 0;
}
