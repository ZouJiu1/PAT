old before
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

update1
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;
int arr[100000];

int findfather(int a) {
    int tmp = a;
    while(arr[a]!=a) a = arr[a];
    arr[tmp] = a;
    return a;
}
void unionjoin(int a, int c) 
{
    int aa = findfather(a);
    int cc = findfather(c);
    if(aa < cc) arr[cc] = aa;
    else arr[aa] = cc;
}
int main(int argc, char **argv) {
    int i, j, k, m, n, y, z, maxmax = -999999999, pre = 0;
    cin>>m;
    for(i = 0; i < 100000; i++) arr[i] = i;
    for(i = 0; i < m; i++) {
        cin>>n;
        vector<int> v;
        for(j = 0; j < n; j++) {
            cin>>y;
            v.push_back(y);
            if(maxmax < y) maxmax = y;
        }
        sort(v.begin(), v.end());
        for(j = 0; j < v.size()-1; j++) 
            unionjoin(v[j], v[j+1]);
    }
    y = 0;
    for(i = 1; i <= maxmax; i++) {
        if(findfather(i)==i) y++;
    }
    printf("%d %d\n", y, maxmax);
    cin>>n;
    for(i = 0; i < n; i++) {
        cin>>y>>z;
        if(findfather(y)==findfather(z)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
