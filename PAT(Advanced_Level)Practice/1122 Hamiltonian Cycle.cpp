#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int main(void) {
    int i, j, k, m, n, x1, x2;
    cin>>m>>n;
    vector<vector<int>> v0;
    int matrix[206][206];
    int infinf = (int)(pow(2, 31) - 1006);
    for(i = 0; i < 206; i++) {
        for(j = 0; j < 206; j++) {
            matrix[i][j] = infinf;
        }
    }
    for(i = 0; i < n; i++) {
        cin>>x1>>x2;
        matrix[x1][x2] = matrix[x2][x1] = 1;
    }
    cin>>n;
    v0.resize(10000);
    for(i = 0; i < n; i++) {
        cin>>k;
        set<int> st;
        for(j = 0; j < k; j++) {
            cin>>x1;
            v0[i].push_back(x1);
            st.insert(x1);
        }
        int mr = -9;
        for(int ij = 0; ij < v0[i].size() - 1; ij++) {
            if(matrix[v0[i][ij]][v0[i][ij+1]]!=1){
                mr = 9;
                break;
            }
        }

        if(v0[i].size()!=m+1 || st.size()!=m || mr > 0 || v0[i][0]!=v0[i][v0[i].size() - 1]){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
    }

    return 0;
}
