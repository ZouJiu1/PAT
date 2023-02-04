update202302
#include<iostream>
#include<vector>  
#include<stack>                                                                                            
using namespace std;
int main(void) {
    int i, j, k, m, n, N, M, K, y, z;
    cin>>M>>N>>K;
    for(i = 0; i < K; i++) {
        vector<int> v(N);
        stack<int> t;
        for(j = 0; j < N; j++) scanf("%d", &v[j]);
        int cnt = 0;
        for(j = 1; j <= N; j++) {
            t.push(j);
            if(t.size() > M) break;
            while(t.size() > 0 && v[cnt]==t.top()) {
                t.pop();
                cnt++;
            }
        }
        if(t.size()!=0) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}

old before
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
