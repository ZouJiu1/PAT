#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int M, N, S, begins;
    cin>>M>>N>>S;
    string s0;
    vector<string> vec;
    set<string> st;
    for(int i=0; i<M; i++){
        cin>>s0;
        vec.push_back(s0);
    }
    if(S>vec.size()){
        cout<<"Keep going...";
        return 0;
    }
    begins = S - 1;
    for(int i=0; i<(M/N+1); i++){
        if(begins>=M)
            break;
        set<string>::iterator it= st.find(vec[begins]);
        if(it==st.end()){
            cout<<vec[begins]<<endl;
            st.insert(vec[begins]);
            begins += N;
        }else{
            begins++;
        }
    }
    return 0;
}
