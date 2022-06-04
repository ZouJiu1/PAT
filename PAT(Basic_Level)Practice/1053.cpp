#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int N, D, num, count;
    double dle, e;
    cin>>N>>e>>D;
    int half;
    int kong=0, keneng=0;
    for(int i=0; i<N; i++){
        cin>>num;
        count = 0;
        half = num/2;
        for(int j=0; j<num; j++){
            cin>>dle;
            if(dle<e)
                count++;
        }
        if(count>half){
            if(num>D)
                kong++;
            else
                keneng++;
        }
    }
    double res0, res1;
    res0 = (double)(keneng*100)/(double)N;
    res1 = (double)(kong*100)/(double)N;
    printf("%.1f%% %.1f%%\n", res0, res1);
    return 0;
}
