#include<iostream>
#include<string>
using namespace std;
bool isprime(string c) {
    int a = stoi(c);
    if(a<=1) return false;
    for(int i = 2; i * i <= a; i++) {
        if(a%i==0) return false;
    }
    return true;
}
int main(void) {
    int i, j, k, N, M, mr = 9;
    string t0, t1;
    cin>>t0;
    k = 0;
    while(k!=t0.length()) {
        t1 = t0.substr(k);
        if(!isprime(t1)) {
            mr = -9;
            cout<<t1<<" "<<"No\n";
        } else cout<<t1<<" "<<"Yes\n";
        k++;
    }
    if(mr > 0) printf("All Prime!\n");
    return 0;
}
