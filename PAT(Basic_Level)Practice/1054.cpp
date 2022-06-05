#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int num, n, zer, alg, counts=0;
    double sum=0, tmp;
    string s0;
    cin>>n;
    char a[60], b[60]; 
    for(int i=0; i<n; i++){
        scanf("%s", a);
        sscanf(a,"%lf", &tmp);
        sprintf(b, "%.2f", tmp);
        alg = 0;
        for(int j=0; j<strlen(a); j++){
            if(a[j]!=b[j]) {
                alg=1;
                break;
            }
        }
        if(alg||tmp<-1000||tmp>1000){
            cout<<"ERROR: "<<a<<" is not a legal number"<<endl;
            continue;
        }else{
            sum += tmp;
            counts++;
        }
    }
    if(counts==0){
        cout<<"The average of "<<counts<<" numbers is Undefined";
        return 0;
    }
    if(counts==1) {
        printf("The average of 1 number is %.2f", sum);
        return 0;
    }
    double avg = sum/(double)counts;
    printf("The average of %d numbers is %.2f", counts, avg);
    return 0;
}
