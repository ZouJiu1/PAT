#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare_reverse(const char a, const char b){
    return a>b;
}

bool compare(const char a, const char b){
    return a<b;
}

int process(){
    int num, n0, n1, res;
    string s0, s2;
    cin>>num;
    if(num==6174)
        num = 6741;
    while(num!=6174){
        s0 = to_string(num);
        for(int i=s0.size(); i<4; i++){
            s0.push_back('0');
        }
        sort(s0.begin(), s0.end(), compare_reverse);
        n0 = atoi(s0.c_str());
        s2 = s0;
        reverse(s0.begin(), s0.end());
        if(s0==s2){
            cout<<s2<<" - "<<s2<<" = 0000"<<endl;
            return 0;
        }
        n1 = atoi(s0.c_str());
        num = n0 - n1;
        printf("%04d - %04d = %04d\n", n0, n1, num);
    }
    return 0;
}

int main(void){
    int x=0;
    x = process();
    return x;
}
