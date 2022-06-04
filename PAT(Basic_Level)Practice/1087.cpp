#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, m, res;
    cin>>n;
    set<int> st;
    for(int i=1; i<=n; i++){
        m = (int)floor(i/(float)2.0) + (int)floor(i/(float)3.0) + (int)floor(i/(float)5.0);
        st.insert(m);
    }
    cout<<st.size();
    return 0;
}
