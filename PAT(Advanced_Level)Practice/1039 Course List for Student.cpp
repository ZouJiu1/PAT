#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int i, j, k, m, n, h, mm, nn;
    int numstd, numcor;
    set<string> vec[2600];
    cin>>m>>n;
    string s;
    int max = -999;
    for(i = 0 ; i < n; i++)
    {
        cin>>mm>>nn;
        for(j = 0; j < nn; j++){
            cin>>s;
            vec[mm].insert(s);
        }
        if(mm>max) max = mm;
    }
    vector<string> vs;
    for(i = 0; i < m; i++){
        cin>>s;
        vs.push_back(s);
    }
    set<string>::iterator it;
    set<string> ste;
    for(i = 0; i<vs.size(); i++){
        s = vs[i];
        vector<int> vtr;
        for(j = 1; j<=max; j++){
            ste = vec[j];
            if(ste.size()==0) continue;
            it = ste.find(s);
            if(it!=ste.end()){
                vtr.push_back(j);
            }
        }
        sort(vtr.begin(), vtr.end());
        cout<<s<<" "<<vtr.size();
        for(j = 0; j<vtr.size();j++){
            if(j==0) cout<<" ";
            cout<<vtr[j];
            if(j != (vtr.size() - 1)) cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
