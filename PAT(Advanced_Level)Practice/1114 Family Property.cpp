#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<bits/stdc++.h>

using namespace std;

int joinsearch[100000];

int findfather(int a) {
    int tmp = a;
    while(a!=joinsearch[a]) 
        a = joinsearch[a];
    joinsearch[tmp] = a;
    return a;
}

void unionjoin(int a, int c) {
    int x = findfather(a);
    int y = findfather(c);
    joinsearch[y] = x; 
}

struct nod{
    int minmin;
    int count;
    float sum0;
    float sum1;
};

bool compare(struct nod &a, struct nod &c) {
    if(a.sum1 > c.sum1) return true;
    else if(a.sum1==c.sum1) {
        if(a.minmin < c.minmin) return true;
        else return false;
    }
    else return false;
}

int main(void) {
    int i, j, k, m, n;
    for(i = 0; i < 100000; i++) 
        joinsearch[i] = i;
    cin>>n;
    int x1, x2, x3, x6, x9, x10;
    set<int> st;
    map<int, vector<int>> mp;
    for(i = 0; i < n; i++) {
        cin>>x1>>x2>>x3>>m;
        if(x2!=-1)
            unionjoin(x2, x1);
        if(x3!=-1)
            unionjoin(x3, x1);
        st.insert(x1);
        st.insert(x2);
        st.insert(x3);
        // cout<<joinsearch[x1]<<" ";
        // if(x2!=-1)
        //     cout<<joinsearch[x2]<<" ";
        // if(x3!=-1)
        //     cout<<joinsearch[x3];
        // cout<<endl;
        for(j = 0; j < m; j++) {
            cin>>x6;
            st.insert(x6);
            unionjoin(x1, x6);
            // cout<<joinsearch[x6]<<endl;
        }
        cin>>x6>>x9;
        mp[x1].push_back(x6);
        mp[x1].push_back(x9);
    }
    vector<int> vtr;
    for(set<int>::iterator it=st.begin(); it!=st.end(); it++) {
        if(*it==-1) continue;
        vtr.push_back(*it);
    }
    int cnt = 0;
    set<int> vt;
    for(i = 0; i < vtr.size(); i++) {
        if(vtr[i]==findfather(vtr[i])) {
            vt.insert(findfather(vtr[i]));
        }
        // cout<<vtr[i]<<"-->"<<joinsearch[vtr[i]]<<"-->"<<findfather(vtr[i])<<endl;
    }
    vector<struct nod> rtv;
    cnt = 0;
    struct nod nd;
    for(set<int>::iterator it = vt.begin(); it!=vt.end(); it++) {
        int minmin = 9999999;
        int sum0=0, sum1=0, count = 0;
        for(j = 0; j < vtr.size(); j++) {
            if(findfather(vtr[j])==*it) {
                if(minmin > vtr[j]) {
                    minmin = vtr[j];
                }
                count++;
                if(mp[vtr[j]].size() > 0) {
                    sum0 += mp[vtr[j]][0];
                    sum1 += mp[vtr[j]][1];
                }
            }
        }
        nd.minmin = minmin;
        nd.count = count;
        nd.sum0 = sum0/(float)count;
        nd.sum1 = sum1/(float)count;
        rtv.push_back(nd);
    }
    sort(rtv.begin(), rtv.end(), compare);
    cout<<rtv.size()<<endl;
    for(i = 0; i < rtv.size(); i++) {
        printf("%04d %d %.3f %.3f\n", rtv[i].minmin, 
            rtv[i].count, rtv[i].sum0,
            rtv[i].sum1);
    }
    return 0;
}
