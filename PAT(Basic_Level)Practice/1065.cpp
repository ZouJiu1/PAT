#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    string num0, num2;
    cin>>n;
    vector<string> oneman, all;
    map<string, string> couples, revercoup;
    set<string> st;
    for(int i=0; i<n; i++){
        cin>>num0>>num2;
        couples[num0] = num2;
        revercoup[num2] = num0;
        // paires.push_back(num0);
        // paires.push_back(num2);
    }
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num0;
        all.push_back(num0);
        st.insert(num0);
    }
    string x{};
    for(int i=0; i<n; i++){
        if(couples[all[i]]==x&&revercoup[all[i]]==x){
            oneman.push_back(all[i]);
        }
        if(couples[all[i]]!=x&&revercoup[all[i]]==x){
            num0 = couples[all[i]];
            set<string>::iterator it = st.find(num0);
            if(it==st.end()){
                oneman.push_back(all[i]);
            }
        }
        if(couples[all[i]]==x&&revercoup[all[i]]!=x){
            num0 = revercoup[all[i]];
            set<string>::iterator it = st.find(num0);
            if(it==st.end()){
                oneman.push_back(all[i]);
            }
        }
    }
    sort(oneman.begin(), oneman.end());
    cout<<oneman.size()<<endl;
    for(int i=0; i<oneman.size(); i++){
        cout<<oneman[i];
        if(i!=(oneman.size()-1))
            cout<<" ";
    }
    return 0;
}
