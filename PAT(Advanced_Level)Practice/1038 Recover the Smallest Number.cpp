update
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool compare(string a, string c) {
    return a + c < c + a;
}
int main(void) {
    int i, j, k=0, m, n, N;
    string tk, res;
    cin>>N;
    vector<string> vt;
    for(i = 0; i < N; i++) {
        cin>>tk;
        vt.push_back(tk);
    }
    sort(vt.begin(), vt.end(), compare);
    for(i = 0; i < vt.size(); i++) {
        res += vt[i];
    }
    while(res.length()!=0 && res[k]=='0') k++;
    res.erase(res.begin(), res.begin() + k);
    if(res.length()==0) cout<<0;
    cout<<res<<endl;
    return 0;
}

old before
#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main(void){
    int i, j, k, m, n, t, counts;
    cin>>m;
    string s, s0;
    vector<string> v, v0;
    for(i=0; i<m; i++){
        cin>>s;
        if(stoll(s)==0) continue;
        v.push_back(s);
    }
    vector<string> st;
    int len = v.size();
    int cnt = 0, maxmax;
    vector<string> vtr, pre{};
    set<string>::iterator it;
    k = 0;
    while(st.size()!=len){
        int minmin = 999999;
        if(cnt==0) vtr = v;
        int le = vtr.size();
        set<string> st0;
        for(i = 0; i < le; i++){
            t = vtr[i][cnt%vtr[i].length()] - '0';
            if(t < minmin){
                minmin = t;
                vtr.erase(vtr.begin() + le, vtr.end());
                vtr.push_back(vtr[i]);
                st0.insert(vtr[i]);
                maxmax = -999;
                int ltt = vtr[i].length();
                if(ltt > maxmax)
                    maxmax = vtr[i].length();
            }else if(t==minmin){
                it = st0.find(vtr[i]);
                if(it==st0.end())
                    vtr.push_back(vtr[i]);
                    int ltt = vtr[i].length();
                    if(ltt > maxmax) 
                        maxmax = vtr[i].length();
            }
        }
        vtr.erase(vtr.begin(), vtr.begin() + le);
        if(vtr.size()==1||(maxmax < k)){
            for(i = 0; i < v.size(); i++){
                if(v[i]==vtr[0]){
                    k = i;
                    break;
                }
            }
            s0 += v[k];
            st.push_back(v[k]);
            v.erase(v.begin() + k);
            cnt = 0;
            k = 0;
        }else if(vtr.size() > 1){
            cnt++;
        }
        if(vtr==pre)
            k++;
        pre = vtr;
    }
    for(i = 0; i < s0.length(); i++){
        if(s0[i]!='0'){
            k = i;
            break;
        }
    }
    s0 = s0.substr(k, s0.length() - k);
    cout<<s0;
    if(s0.size()==0) cout<<0;
    return 0;
}
