#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int i, j, k, m, n, h, mm, nn;
    int numstd, numcor;
    set<string> vec[2600];
    cin>>m>>n;
    string s;
    int max = -999;
    map<string, vector<int>> mp;
    for(i = 0 ; i < n; i++)
    {
        cin>>mm>>nn;
        for(j = 0; j < nn; j++){
            cin>>s;
            // vec[mm].insert(s);
            mp[s].push_back(mm);
        }
        if(mm>max) max = mm;
    }
    vector<int> vs;
    for(i = 0; i < m; i++){
        cin>>s;
        vs = mp[s];
        cout<<s<<" "<<vs.size();
        sort(vs.begin(), vs.end());
        for(j = 0; j<vs.size();j++){
            if(j==0) cout<<" ";
            cout<<vs[j];
            if(j != (vs.size() - 1)) cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
