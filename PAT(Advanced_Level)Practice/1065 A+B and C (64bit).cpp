#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int i, j, m, n, x, y, k, w, f=9, g=9;
    long long AA, KK, CC;
    string A, K, C, tm;
    cin>>n;
    for(i = 0; i < n; i++){
        cin>>A>>K>>C;
        // scanf("%lld %lld %lld", &AA, &KK, &CC);
        if(A[0]=='-') f = -9;
        if(K[0]=='-') g = -9; 
        if(f < 0 && g < 0 && C[0]!='-') {
            printf("Case #%d: false\n", i+1);
            continue;
        }else if(f > 0 && g > 0 && C[0]=='-'){
            printf("Case #%d: true\n", i+1);
            continue;
        }
        if(f>0 && g>0 && min(A.length(), K.length()) < 19 ){
            unsigned long long AAA, KKK, CCC;
            AAA = stoull(A);
            KKK = stoull(K);
            CCC = stoull(C);
            unsigned long long res = AAA + KKK;
            if(res > CCC)
                printf("Case #%d: true\n", i+1);
            else
                printf("Case #%d: false\n", i+1);
            continue;
        }
        if(f<0 && g<0 && C[0]=='-' && min(A.length(), K.length()) < 19 ){
            A.erase(A.begin());
            K.erase(K.begin());
            C.erase(C.begin());
            unsigned long long AAA, KKK, CCC;
            AAA = stoull(A);
            KKK = stoull(K);
            CCC = stoull(C);
            unsigned long long res = AAA + KKK;
            if(res < CCC)
                printf("Case #%d: true\n", i+1);
            else
                printf("Case #%d: false\n", i+1);
            continue;
        }
        if(min(A.length(), K.length()) < 19 || f * g < 0){
            AA = stoll(A);
            KK = stoll(K);
            CC = stoll(C);
            if(AA + KK> CC)
                printf("Case #%d: true\n", i+1);
            else
                printf("Case #%d: false\n", i+1);
            continue;
        }
        reverse(A.begin(), A.end());
        reverse(K.begin(), K.end());
        if(f < 0) A.pop_back();
        if(g < 0) K.pop_back();
        m = min(A.length(), K.length());
        // A.append(A.length() - m, '0');
        // K.append(K.length() - m, '0');
        y = 0;
        for(j = 0; j < A.length(); j++){
            k = A[j] - '0' + K[j] - '0' + y;
            x = k%10;
            y = k/10;
            tm += to_string(x);
        }
        if(y > 0) tm += to_string(y);
        reverse(tm.begin(), tm.end());
        if(f < 0 && g < 0){ // C < 0
            C.erase(C.begin());
            if(C.length() < tm.length())
                printf("Case #%d: false\n", i+1);
            else if(C.length() > tm.length())
                printf("Case #%d: true\n", i+1);
            else{
                if(C==tm){
                    printf("Case #%d: false\n", i+1);
                    continue;
                }
                for(j = 0; j < C.length(); j++){
                    if(C[j]==tm[j]) continue;
                    else if((C[j]-'0') > (tm[j] - '0')){
                        printf("Case #%d: true\n", i+1);
                        break;
                    }
                    else{
                        printf("Case #%d: false\n", i+1);
                        break;
                    }
                }
            }
            continue;
        }
        if(C==tm){
            printf("Case #%d: false\n", i+1);
            continue;
        }
        if(C.length() < tm.length())
            printf("Case #%d: true\n", i+1);
        else if(C.length() > tm.length())
            printf("Case #%d: false\n", i+1);
        else{
            for(j = 0; j < C.length(); j++){
                if(C[j]==tm[j]) continue;
                else if((C[j]-'0') > (tm[j] - '0')){
                    printf("Case #%d: false\n", i+1);
                    break;
                }
                else{
                    printf("Case #%d: true\n", i+1);
                    break;
                }
            }
        }
    }
    return 0;
}
/*
#include <cstdio>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        long long sum = a + b;
        if(a > 0 && b > 0 && sum < 0) {
            printf("Case #%d: true\n", i + 1);
        } else if(a < 0 && b < 0 && sum >= 0){
            printf("Case #%d: false\n", i + 1);
        } else if(sum > c) {
            printf("Case #%d: true\n", i + 1);
        } else {
            printf("Case #%d: false\n", i + 1);
        }
    }
    return 0;
}
*/
