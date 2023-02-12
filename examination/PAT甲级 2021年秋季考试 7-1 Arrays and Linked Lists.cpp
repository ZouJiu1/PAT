#include<iostream>
#include<algorithm>
using namespace std;
long long arr[10006][2], sum[10006];
int main(void) {
    long long i, j, k, m, n, N, M, K, maxmax=0;
    scanf("%lld %lld", &N, &K);
    for(i = 1; i <= N; i++) {
        scanf("%lld %lld", &arr[i][0], &arr[i][1]);
        sum[i] += sum[i-1] + arr[i][1];
    }
    for(i = 0; i < K; i++) {
        scanf("%lld", &m);
        if(sum[N] <= m) {
            printf("Illegal Access\n");
            continue;
        }
        for(j = 1; j <= N; j++) {
            if(sum[j] > m) {
                printf("%lld\n", arr[j][0] + sizeof(int)*(m + 1 - sum[j-1] -1));
                if(maxmax < j) maxmax = j;
                break;
            }
        }
    }
    printf("%lld\n", maxmax==0? 1:maxmax); //At the very beginning, an integer array A0 of length L0 is initialized for the user. 
    return 0;
}
