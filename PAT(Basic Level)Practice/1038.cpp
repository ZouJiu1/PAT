#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, m, num;
    int count;
    vector<int> vec, vec6;
    map<int, int> mp;
    set<int> st;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num;
        vec.push_back(num);
    }
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>num;
        vec6.push_back(num);
        st.insert(num);
        mp[num] = 0;
    }
    for(int j=0; j<vec.size(); j++){
        set<int>::iterator it= st.find(vec[j]);
        if(it!=st.end())
            mp[vec[j]] += 1; 
    }
    for(int i=0; i<m; i++){
        cout<<mp[vec6[i]];
        if(i!=(m-1))
            cout<<" ";
    }
    return 0;
}
