#include<iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    unsigned int N, M;
    int tmp;
    float hal;
    vector<int> vec;
    cin>>N>>M;
    unsigned int i, ele;
    for(i = 0; i < N; i++){
        cin>>ele;
        vec.push_back(ele);
    }
    if(M>N)
        M=M%N;
    hal = N/(float)2;
    if(M<hal){
        for(i = 0; i < M; i++){
            tmp = vec[vec.size() - 1];
            vector<int>::iterator it = vec.insert(vec.begin(), tmp);
            vec.pop_back();
        }
    }else{
        for(i = 0; i < N-M; i++){
            tmp = vec[0];
            vector<int>::iterator it = vec.insert(vec.end(), tmp);
            vec.erase(vec.begin());
        }
    }
    for(i=0;i<vec.size();i++){  
        cout<<vec[i];
        if(i!=vec.size()-1) cout<<" ";
    }
    return 0;
}
