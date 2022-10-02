#include<iostream>
#include<vector>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int arrays[100000];

int findfather(int a) {
    int tmp = a;
    while(a!=arrays[a])
        a = arrays[a];
    arrays[tmp] = a;
    return a;
}

void unionjoin(int a, int c) {
    int x = findfather(a);
    int y = findfather(c);
    arrays[y] = x;
}

int main(void) {
    int i, j, k, m, n;
    cin>>n;
    for(i = 0; i < 100000; i++) arrays[i] = i;
    set<int> st;
    for(i = 0; i < n; i++) {
        cin>>m;
        vector<int> v;
        for(j = 0; j < m; j++) {
            cin>>k;
            v.push_back(k);
            st.insert(k);
        }
        sort(v.begin(), v.end());
        for(int ij = 1; ij < v.size(); ij++) {
            unionjoin(v[0], v[ij]);
        }
    }
    int n0, x1, x2;
    cin>>n0;
    int cnt = 0;
    for(i = 1; i <= st.size(); i++) {
        if(arrays[i]==i) cnt++;
    }
    cout<<cnt<<" "<<st.size()<<endl;
    for(i = 0; i < n0; i++) {
        cin>>x1>>x2;
        if(findfather(x1) == findfather(x2)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
