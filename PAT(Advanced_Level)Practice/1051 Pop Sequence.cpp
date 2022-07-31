#include<iostream>
#include<vector>
#include<stack>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int i, j, k, m, n, h, mm, nn;
    cin>>m>>n>>h;
    vector<int> vec[h];
    for(i = 0; i < h; i++){
        for(j = 0; j < n; j++){
            cin>>k;
            vec[i].push_back(k);
        }
    }
    for(i = 0; i < h; i++){
        stack<int> s;
        int cnt = 0;
        int num = 1;
        while(s.size()<=m){
            if(s.size() > 0 && s.top()==vec[i][cnt]){
                s.pop();
                cnt++;
            }
            else if(s.size() > 0 && num <=n && s.top()!=vec[i][cnt])
                s.push(num++);
            else if(s.size()==0 && num <=n)
                s.push(num++);
            else break;
        }
        if(s.size() > 0) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
