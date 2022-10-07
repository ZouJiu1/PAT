#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
int main(void) {
    int i, j, k, m, n;
    string x1, x2;
    cin>>m>>n;
    unordered_map<string, int> mp, mmp, rmp;
    vector<string> v;
    for(i = 0; i < m; i++) {
        cin>>x1>>x2;
        mp[x1 + x2] = mp[x2 + x1] = 9;
        if(rmp[x1]+0==0) rmp[x1] = 9;
        if(rmp[x2]+0==0) rmp[x2] = 9;
    }
    for(i = 0; i < n; i++) {
        cin>>m;
        for(j = 0; j < m; j++) {
            cin>>x1;
            v.push_back(x1);
        }
        k = -9;
        for(j = 0; j < m - 1; j++) {
            if(rmp[v[j]]+0==0) continue;
            for(int ij = j + 1; ij < m; ij++) {
                if(rmp[v[ij]]+0==0) continue;
                if(mp[v[j] + v[ij]] + 0 > 0) {
                    k = 9;
                    cout<<"No"<<endl;
                    break;    
                }
            }
            if(k > 0) break;
        }
        if(k < 0) cout<<"Yes"<<endl;
        v.clear();
    }
    return 0;
}
