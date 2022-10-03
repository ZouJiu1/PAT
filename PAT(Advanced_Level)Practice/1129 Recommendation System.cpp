#include<iostream>
#include<vector>
#include<map>
#include<bits/stdc++.h>

using namespace std;

struct nod {
    int val = 0;
    int search_num = 0;
};

bool compare(struct nod &a, struct nod &c) {
    if(a.search_num > c.search_num) return true;
    else if(a.search_num==c.search_num) return a.val < c.val;
    else return false;
}

int main(void) {
    int i, j, k, m, n;
    cin>>m>>n;
    vector<int> v;
    vector<struct nod> vec;
    for(i = 0; i < m; i++) {
        cin>>k;
        v.push_back(k);
    }
    struct nod nd;
    map<int, int> mp;
    for(i = 0; i < m; i++) {
        sort(vec.begin(), vec.end(), compare);
        if(vec.size() > 0) cout<<v[i]<<": ";
        k = min((int)vec.size(), n);
        for(j = 0; j < k; j++) {
            cout<<vec[j].val;
            if(j!=k-1) cout<<" ";
        }
        if(vec.size() > 0) cout<<endl;
        if(mp[v[i]]+0 > 0){
            for(j = 0; j < vec.size(); j++) {
                if(vec[j].val==v[i]) {
                    vec[j].search_num++;
                    break;
                }
            }
        }
        else {
            nd.val = v[i];
            nd.search_num = 1;
            vec.push_back(nd);
        }
        mp[v[i]] = 1;
    }
    return 0;
}
