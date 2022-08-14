#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;
int a[10006], cnt = 0;
vector<int> vec[10006];

int findcoin(int n, int x){
    int m;
    for(int i = x; i < 10006; i++){
        if(i > n/2 + 2) return -1;
        if(a[i]){
            a[i]--;
            if(i==n) {
                vec[cnt].push_back(i);
                return i;
            }
            if(n > i && a[n-i]) {
                m = findcoin(n - i, 0);
                vec[cnt].push_back(n - i);
                if(a[n - i]!=0) a[n - i] = 0;
                vec[cnt].push_back(i);
                return i;
            }else{
                m = findcoin(n - i, 0);
                if(m > 0) vec[cnt++].push_back(i);
            }
            a[i]++;
        }
    }
    return -1;
}

int main(void){
    int i, j, k, m, n, h, mm, nn;
    cin>>m>>n;
    memset((void *)a, 0, sizeof(int) * (10006));
    vector<int> v;
    for(i=0; i<m; i++){
        cin>>h;
        v.push_back(h);
        a[h]++;
    }
    findcoin(n, 0);
    vector<int> v00;
    v00 = vec[0];
    if(v00.size()==0){
        cout<<"No Solution";
        return 0;
    }
    sort(v00.begin(), v00.end());
    h = 0;
    for(i = 0; i < v00.size(); i++){
        if(h!=n){
            cout<<v00[i];
            h += v00[i];
        }
        if(h!=n) cout<<" ";
    }
    return 0;
}
