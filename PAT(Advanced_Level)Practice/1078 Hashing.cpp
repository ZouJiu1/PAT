#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

int get_min_prime(int a){
    if(a<=2) return 2;
    else if(a<=3) return 3;
    else if(a<=5) return 5;
    else if(a<=7) return 7;
    else if(a<=11) return 11;
    else if(a<=13) return 13;
    else if(a<=17) return 17;
    else if(a<=19) return 19;

    bool prime = false;
    while(!prime){
        int sqt = sqrt(a) + 6;
        int mar = 999;
        for(int i = 2; i <= sqt; i++){
            if(a%i==0){
                mar = -999;
                break;
            }
        }
        if(mar > 0) return a;
        else a++;
    }
}

int main(void){
    int i, j, m, n, k, w, q, xx, xy, prime;
    cin>>m>>n;
    vector<int> v;
    for(i = 0; i < n; i++){
        cin>>k;
        v.push_back(k);
    }
    prime = get_min_prime(m);
    vector<string> vv;
    bool status[prime+1];
    memset((void *)status, false, sizeof(bool) * (prime + 1));
    for(i = 0; i < n; i++){
        q = v[i]%prime;
        xx = -999;
        for(j = 0; j < prime; j++){
            q = (v[i] + j*j)%prime;
            if(status[q]==false){
                status[q] = true;
                vv.push_back(to_string(q));
                xx = 999;
                break;
            }
        }
        if(xx < 0)
            vv.push_back("-");
    }
    for(i = 0; i < n; i++){
        cout<<vv[i];
        if(i!=n-1) cout<<" ";
    }
    return 0;
}
