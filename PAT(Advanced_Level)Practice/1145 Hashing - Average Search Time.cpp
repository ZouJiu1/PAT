update202301 status[m]==0 意指不存在的，空节点没被填充
#include<iostream>
#include<vector>
using namespace std;
bool isprime(int a) {
    if(a==1) return false;
    for(int i = 2; i*i <= a; i++) {
        if(a%i==0) return false;
    }
    return true;
}
int status[10006], arr[10006];
int main(void) {
    int i, j, k, m, n, H, MSize, N, M;
    cin>>MSize>>N>>M;
    while(!isprime(MSize)) MSize++;
    for(i = 0; i < N; i++) {
        cin>>k;
        H = -9;
        for(j = 0; j < MSize; j++) {
            m = (k + j * j) % MSize;
            if(status[m]==0) {
                arr[m] = k;
                status[m] = 1;
                H = 9;
                break;
            }
        }
        if(H < 0) printf("%d cannot be inserted.\n", k);
    }
    H = 0;
    for(i = 0; i < M; i++) {
        cin>>k;
        for(j = 0; j <= MSize; j++) {
            m = (k + j * j)%MSize;
            H++;
            if(status[m]==0 || arr[m]==k) break; //status[m]==0 意指不存在的，空节点没被填充
        }
    }
    printf("%.1f\n", H/(float)M);
    return 0;
}

update2
#include<iostream>
#include<unordered_map>
using namespace std;
bool isprime(int a) {
    if(a <= 1) return false;
    for(int i = 2; i * i <= a; i++) {
        if(a%i==0) return false;
    }
    return true;
}
int main(int argc, char **argv) {
    int m, n, i, j, k, y, z, w;
    cin>>m>>n>>k;
    while(!isprime(m)) m++;
    unordered_map<int, int> ump;
    for(i = 0; i < n; i++) {
        int mr = -9;
        cin>>w;
        for(j = 0; j < m; j++) {
            z = (w + j * j) % m;
            if(ump[z]==0) {
                ump[z] = w;
                mr = 9;
                break;
            }
        }
        if(mr < 0) printf("%d cannot be inserted.\n", w);
    }
    int sum = 0;
    for(i = 0; i < k; i++) {
        cin>>w;
        for(j = 0; j <= m; j++) {
            sum++;
            z = (w + j * j) % m;
            if(ump[z]==w||ump[z]==0) {
                break;
            }
        }
    }
    printf("%.1f\n", sum/(float)k);
    return EXIT_SUCCESS;
}

old before
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

update
#include<iostream>
#include<unordered_map>
using namespace std;
bool isprime(int a) {
    if(a<=1) return false;
    for(int i = 2; i * i <= a; i++) 
        if(a%i==0) return false;
    return true;
}
int main(int argc, char **argv) {
    int i, j, msize, k, m, n, y, z, sum = 0;
    cin>>msize>>n>>m;
    while(!isprime(msize)) msize++;
    unordered_map<int, int> ump;
    for(i = 0; i < n; i++) {
        cin>>y;
        k = -9;
        for(j = 0; j <= msize; j++) {
            z = (y + j * j) % msize;
            if(ump[z] == 0) {
                ump[z] = y;
                k = 9;
                break;
            }
        }
        if(k < 0) printf("%d cannot be inserted.\n", y);
    }
    for(i = 0; i < m; i++) {
        cin>>y;
        for(j = 0; j <= msize; j++) {
            z = (y + j * j) % msize;
            sum++;
            if(ump[z]==y||ump[z]+0 == 0) break;
        }
    }
    printf("%.1f", sum/(float)m);
    return 0;
}
