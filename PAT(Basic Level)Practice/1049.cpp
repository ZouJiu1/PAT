#include<iostream>
using namespace std;

int main(void){
    int n;
    double num, sum=0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num;
        sum += (i+1) * num * (n-i);
    }
    printf("%.2f\n", sum);
    return 0;
}
