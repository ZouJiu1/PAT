update202301
https://www.liuchuo.net
#include<iostream>
#include<string>
using namespace std;
int arr[1000];
int main(void) {
    int i, j, k, m, n, ned = 0;
    string t0, t1;
    cin>>t0>>t1;
    for(i = 0; i < t0.length(); i++) arr[t0[i]]++;
    for(i = 0; i < t1.length(); i++) {
        if(arr[t1[i]] > 0) arr[t1[i]]--;
        else ned++;
    }
    if(ned > 0) printf("No %d", ned);
    else printf("Yes %d", t0.length() - t1.length());
    return 0;
}


#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    map<char, int> mp, mp6;
    set<char> st, st6;
    string s0, s1;
    getline(cin, s0);
    getline(cin, s1);
    for(int i=0; i<s0.size(); i++){
        st.insert(s0[i]);
    }
    for(set<char>::iterator i=st.begin(); i!=st.end(); i++){
        mp[*i] = 0;
    }
    for(int i=0; i<s0.size(); i++){
        mp[s0[i]] += 1;
    }

    for(int i=0; i<s1.size(); i++){
        st6.insert(s1[i]);
    }
    for(set<char>::iterator i=st6.begin(); i!=st6.end(); i++){
        mp6[*i] = 0;
    }
    for(int i=0; i<s1.size(); i++){
        mp6[s1[i]] += 1;
    }
    int count0=0, count1=0, marked = -3;

    for(set<char>::iterator i=st6.begin(); i!=st6.end(); i++){
        set<char>::iterator it = st.find(*i);
        // cout<<*i<<" "<<count0<<" "<<count1<<endl;
        count1 += mp6[*i];
        if(it==st.end()){
            marked = 3;
            continue;
        }
        // else{
        //     count0 += mp[*i];
        //     continue;
        // }
        if(mp[*i]<mp6[*i]){
            marked = 3;
        }
        
        if(mp[*i] > mp6[*i]){
            count0 += mp6[*i];
        }else{
            count0 += mp[*i];
        }
    }
    if(marked>0){
        cout<<"No "<<(count1 - count0);
    }else{
        cout<<"Yes "<<(s0.size()-s1.size());
    }
    return 0;
}
