#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>
using namespace std;

long long todec10(string s, long long sum0){
    long long sum=0, ind = 0, tmp=0;
    for(auto j = s.rbegin(); j != s.rend(); j++) 
        sum += (isdigit(*j) ? *j - '0' : *j-'a'+10)* pow(sum0, ind++);
    return sum;
}

long long findmid(string s, long long num){
    char t = *max_element(s.begin(), s.end());
    long long low = (isdigit(t) ? t - '0' : t-'a'+10) + 1;
    long long high = low > num ? low:num;
    while(high >= low){
        long long mid = (high + low)/2;
        long long res = todec10(s, mid);
        if(res > num||res < 0)  high = mid - 1;
        else if(res == num){
            return mid;
        }
        else low = mid + 1;
    }
    return -1;
}
int main(void){
    long long a, k, s0;
    string s, s2, s6, s9, s3;
    cin>>s>>s2>>a>>s0;
    if(a==1) k = findmid(s2, todec10(s, s0));
    else k = findmid(s, todec10(s2, s0));
    if(k==-1)
        cout<<"Impossible";
    else
        printf("%lld", k);
    return 0;
}
