#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, num, sum0;
    cin>>n;
    vector<int> vec;
    string s0;
    set<int> st;
    for(int i=0; i<n; i++){
        cin>>num;
        vec.push_back(num);
    }
    for(int i=0; i<n; i++){
        s0 = to_string(vec[i]);
        sum0 = 0;
        for(int j=0; j<s0.size(); j++){
            sum0 += s0[j] - '0';
        }
        st.insert(sum0);
    }
    cout<<st.size()<<endl;
    vector<int> s2;
    for(set<int>::iterator it = st.begin(); it!=st.end(); it++){
        s2.push_back(*it);
    }
    for(int i=0; i<s2.size(); i++){
        cout<<s2[i];
        if(i!=s2.size()-1)
            cout<<" ";
    }
    return 0;
}
