#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, m, A, B, val, num;
    cin>>n>>m>>A>>B>>val;
    int pixels[600][600];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>pixels[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            num = pixels[i][j];
            if(num>=A&&num<=B) printf("%03d", val);
            else printf("%03d", num);
            if(j!=(m-1))
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
