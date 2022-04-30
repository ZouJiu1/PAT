#include<iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, num, sum0=0, sum1=0, num2=0, sum3=0,  max4=-666;
    int cou0=0, cou1=0, cou3=0, cou4=0;
    float res3=0.0;
    cin>>n;
    if(n==0){
        cout<<"N N N N N";
        return 0;
    }
    for(unsigned int i = 0; i < n; i++){
        cin>>num;
        if(num%5==0){
            if(num%2==0){
                sum0+=num;
                cou0++;
            }
        }
        else if(num%5==1){
            if(cou1%2==0)
                sum1 += num;
            else
                sum1 -= num;
            cou1++;
        }
        else if(num%5==2)
            num2++;
        else if(num%5==3){
            sum3 += num;
            cou3++;
        }
        else if(num%5==4){
            if(max4<num)
                max4 = num;
            cou4++;
        }
    }
    if(cou3!=0)
        res3 = sum3/(float)cou3;

    if(cou0==0)
        cout<<"N ";
    else
        cout<<sum0<<" ";
    if(cou1==0)
        cout<<"N ";
    else
        cout<<sum1<<" ";
    if(num2==0)
        cout<<"N ";
    else
        cout<<num2<<" ";
    if(cou3==0)
        cout<<"N ";
    else
        printf("%.1f ", res3);
    if(cou4==0)
        cout<<"N";
    else
        cout<<max4;
    return 0;
}
