/*模拟题，偶数保存不是平方的数字，奇数次保存不是素数的数字，最后只剩一个，输出就可以了*/
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<cmath>
using namespace std;
bool isprime(int &a) {
    if(a <= 1) return false;
    for(int i = 2; i * i <= a; i++) {
        if(a%i==0) return false;
    }
    return true;
}



int main(void) {
    int i, j, k, m, n, N, M, K, inf = 999999999;
    cin>>N;
    vector<int> v, r, rr;
    for(i = 1; i <= N; i++) v.push_back(i);
    k = 0;
    while(v.size()!=1) {
        r = v;
        rr.clear();
        if(k%2==0) {
            for(i = 1; i <=r.size(); i++) {
                double kk = sqrt((double)i);
                K = (int)kk;
                if(fabs(K - kk) < 0.00000001) {
                    continue;
                }else{
                    rr.push_back(r[i-1]);
                }
            }
        }else{
            for(i=1; i<=r.size(); i++) {
                if(isprime(i)){
                    continue;
                }else{
                    rr.push_back(r[i-1]);
                }
            }
        }
        v = rr;
        k++;
    }
    cout<<v[0]<<endl;
    return 0;
}
