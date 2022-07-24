#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int i, j, k, m, n, h, mm, nn;
    cin>>m>>n;
    int a[10001];
    memset((void *)a, 0, sizeof(int) * (10001));
    for(i=0; i<m; i++){
        cin>>h;
        a[h]++;
    }
    for(i = 0; i < 10001; i++){
        if(a[i]){
            a[i]--;
            if(n > i && a[n-i]){
                cout<<i<<" "<<n-i;
                return 0;
            }
            a[i]++;
        }
    }
    cout<<"No Solution";
    return 0;
}

/*
#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int i, j, k, m, n, h, mm, nn;
    cin>>m>>n;
    vector<int> v;
    for(i=0; i<m; i++){
        cin>>h;
        v.push_back(h);
    }
    sort(v.begin(), v.end());
    int minmin = 9999999;
    for(i=0; i<m; i++){
        if(v[i] >= n) break;
        for(j=i+1; j<m; j++){
            mm = v[i] + v[j];
            if(mm==n) {
                minmin = v[i];
                cout<<v[i]<<" "<<v[j];
                return 0;
            }
        }
    }
    cout<<"No Solution";
    return 0;
}
*/
