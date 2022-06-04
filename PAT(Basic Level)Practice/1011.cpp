#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void){
    long long int sum, num0, num1, num2;
    int n, count=0;
    cin>>n;
    for(unsigned int i=0; i<n; i++){
        count++;
        cin>>num0>>num1>>num2;
        sum = num0 + num1;
        if(sum>num2)
            cout<<"Case #"<<count<<": true"<<endl;
        else
            cout<<"Case #"<<count<<": false"<<endl;
    }
    return 0;
}
