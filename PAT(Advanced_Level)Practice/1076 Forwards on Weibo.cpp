/*状态列表记录访问状态 */
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int i, j, m, n, k, w, q, xx, xy;
    cin>>m>>q;
    map<int, vector<int>> mp;
    bool status[m + 1];
    for(i = 1; i <= m; i++){
        cin>>k;
        for(j = 1; j<=k; j++){
            cin>>w;
            mp[w].push_back(i);
        }
    }
    vector<int> vec;
    cin>>n;
    for(j = 0; j < n; j++){
        cin>>k;
        vec.push_back(k);
    }
    set<int> st; //posted
    vector<int> v;
    vector<vector<int>> vv;
    for(j = 0; j < n; j++){
        memset((void*)status, false, sizeof(bool) * (m + 1));
        vv.push_back(mp[vec[j]]);
        st.insert(vec[j]);
        for(xy = 0; xy < q; xy++){
            int sizes = vv.size();
            for(xx = 0; xx < sizes; xx++){
                v = vv[xx];
                for(i = 0; i < v.size(); i++){
                    if(status[v[i]]==false){
                        vv.push_back(mp[v[i]]);
                        st.insert(v[i]);
                        status[v[i]] = true;
                    }
                }
            }
            vv.erase(vv.begin(), vv.begin() + sizes);
        }
        cout<<st.size() - 1<<endl;
        st.clear();
        vv.clear();
    }
    return 0;
}
