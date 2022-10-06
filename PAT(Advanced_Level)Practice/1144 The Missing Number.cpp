#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

int main(void) {
    int m, i, j, k; 
    cin>>m;
    map<int, int> mp;
    for(i = 0; i < m; i++) {
        cin>>k;
        mp[k]++;
    }
    for(i = 1; i < 1024*1024*1024 - 1; i++) {
        if(mp[i]+0==0) {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
