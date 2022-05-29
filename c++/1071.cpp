#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int all, n2, s0, s1, s2, s3;
    cin>>all>>n2;
    int number[600][4];
    for(int i=0; i<n2; i++){
        cin>>s0>>s1>>s2>>s3;
        number[i][0]=s0;
        number[i][1]=s1;
        number[i][2]=s2;
        number[i][3]=s3;
    }
    for(int i=0; i<n2; i++){
        s0 = number[i][0];
        s1 = number[i][1];
        s2 = number[i][2];
        s3 = number[i][3];
        if(s2>all){
            printf("Not enough tokens.  Total = %d.\n", all);
            continue;
        }
        if((s3>s0&&s1)||(s3<s0&&!s1)){
            all += s2;
            printf("Win %d!  Total = %d.\n", s2, all);
        }else{
            all -= s2;
            printf("Lose %d.  Total = %d.\n", s2, all);
        }
        if(all==0){
            cout<<"Game Over.";
            return 0;
        }
    }
    return 0;
}
