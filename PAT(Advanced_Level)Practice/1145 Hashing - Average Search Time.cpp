#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;
int isprime(int a){
    int sqt = min((int)sqrt(a) + 1, a - 1);
    for(int i = 2; i < sqt; i++){
        if(a%i==0)
            return false;
    }
    return true;
}
int main(void) {
    int i, j, m, n, k, w, q, xx, xy, prime;
    int x1, x2;
    cin>>prime>>n>>x1;
    while(!isprime(prime)) prime++;
    map<int, int> mp;
    for(i = 0; i < n; i++){
        scanf("%d", &w);
        xx = -9;
        for(j = 0; j < prime; j++){
            q = (w + j*j)%prime;
            if(mp[q]+0 == 0){
                mp[q] = w;
                xx = 9;
                break;
            }
        }
        if(xx < 0) printf("%d cannot be inserted.\n", w);
    }
    int sum = 0;
    for(i = 0; i < x1; i++) {
        scanf("%d", &w);
        for(j = 0; j <= prime; j++) {
            q = (w + j*j)%prime;
            sum++;
            if(mp[q]==w||mp[q] + 0 == 0) break;
        }
    }
    printf("%.1f\n", sum/(float)x1);
    return 0;
}
