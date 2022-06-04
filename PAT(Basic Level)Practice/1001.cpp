#include<iostream>
using namespace std;
int main(){
    int n;
    int counts=0;
    cin>>n;
    while (n!=1){
        if (n%2==0){
            n = n/2;
        }
        else{
            n=(3*n+1)/2;
        }
        counts+=1;
    }
    cout<<counts;
    return 0;
}
