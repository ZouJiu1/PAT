#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

#define CLK_TCK 100

int main(void){
    int c1, c2;
    cin>>c1>>c2;
    float sub = (float)(c2 - c1);
    float sec = (float)sub/(float)CLK_TCK;

    int hour = sec/3600;
    float remain = sec - hour * 3600;
    int minute = remain/60;
    remain = remain - minute * 60;
    sec = round(remain);
    int second = (int)sec;
    printf("%02d:%02d:%02d\n", hour, minute, second);
    return 0;
}
