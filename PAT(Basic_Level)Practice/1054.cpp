#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int num, n, tmp, zer, alg, count;
    double sum, x;
    string s0;
    cin>>n;
    vector<string> vec;
    for(int i=0; i<n; i++){
        cin>>s0;
        vec.push_back(s0);
    }
    count = 0;
    for(int i=0; i<n; i++){
        zer = 0;
        s0 = vec[i];
        alg=0;
        for(int j=0; j<s0.size(); j++){
            if(s0[j]=='0'||s0[j]=='9'||s0[j]=='1'||s0[j]=='2'||
               s0[j]=='3'||s0[j]=='4'||s0[j]=='5'||s0[j]=='6'||
               s0[j]=='7'||s0[j]=='8') 
               alg++;
            else if(s0[j]=='.')
                zer++;
        }
        if(s0.find('.')!=string::npos) alg++;
        if(s0[0]=='-') alg++;
        if((alg!=s0.size())||(zer>1)){
            cout<<"ERROR: "<<s0<<" is not a legal number"<<endl;
            continue;
        }
        if(s0.find('.')!=string::npos){
            tmp = s0.find('.');
            tmp = s0.size() - tmp - 1;
            if(tmp>2){
                cout<<"ERROR: "<<s0<<" is not a legal number"<<endl;
                continue;
            }
        }
        x = stof(s0);
        if(x>1000||x<-1000){
            cout<<"ERROR: "<<s0<<" is not a legal number"<<endl;
            continue;
        }
        sum += x;
        count +=1 ;
    }
    if(count==0){
        cout<<"The average of "<<count<<" numbers is Undefined";
        return 0;
    }
    double avg = sum/(double)count;
    printf("The average of %d numbers is %.2f", count, avg);
    return 0;
}
