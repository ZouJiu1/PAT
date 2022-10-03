#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

//row from low to high, low:1,  high:N
int main(void) {
    int i, j, k, m, n;
    cin>>n;
    vector<vector<int>> v;
    v.resize(n);
    for(i = 0; i < n; i++) {
        cin>>m;
        for(j = 0; j < m; j++) {
            cin>>k;
            v[i].push_back(k);
        }
    }
    for(i = 0; i < n; i++) {
        int mr = -9, column = 0;
        set<int> st;  //for equal row
        for(j = 0; j < v[i].size() - 1; j++) {
            if(abs(v[i][j] - v[i][j+1])<=1) mr = 9;
            st.insert(v[i][j]);
        }
        st.insert(v[i][j]);
        if(st.size()!=v[i].size() && mr <0) mr = 9;
        if(mr < 0) {
            for(j = 0; j < v[i].size() - 1; j++) {
                for(k = j + 1; k < v[i].size(); k++) {
                    if(k-j==v[i][j]-v[i][k]) {
                        mr = 9;
                        break;
                    }
                }
                if(mr>0) break;
            }   
        }
        if(mr < 0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    return 0;
}
