#include<iostream>
#include<map>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        int x2=0, x3=0;
        cin>>s;
        map<char, int> m;
        for(unsigned int j=0; j<s.size(); j++){
            m[s[j]]++;
            if(s[j]=='P') x2 = j;
            if(s[j]=='T') x3 = j;
        }
        //要么是关于PAT对称，要么PAT之间加A，则P前和T后也要加
        bool x = (((x3-x2-2)*x2+x2*2+3+(x3-x2-2))==s.size()); //符合第二、三个条件
        if((m['P']==1)&&(m['T']==1)&&(m['A']>=1)&&((x3-x2)>=2)&&(m.size()==3)&&x)             //APAAATAA        
            cout<<"YES";
        else
            cout<<"NO";
        if(i<n-1) cout<<endl;
    }   
    return 0;
}
