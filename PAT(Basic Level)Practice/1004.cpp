#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main(void){
    int n, max=-666666, min = 666666;
    string s1, s2, s3, s9, s33, s99;
    int score;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s1>>s2>>score;
        if(score>max){
            max = score;
            s3 = s1;
            s9 = s2;
        }
        if(score<min){
            min = score;
            s33 = s1;
            s99 = s2;
        }
    }
    cout<<s3<<" "<<s9<<endl<<s33<<" "<<s99;
    return 0;
}
