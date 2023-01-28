经过quick sort以后的序列，pivot在的index一定和完全排序以后的index相等，也就是一次quick sort以后的pivot在它应该在的position，
也就是pivot>左侧的最大值，pivot<右侧的最小值，拿到从左到右的递推最大值，以及从右到左的递推最小值，然后两者相等的可能就是pivot
pivot存在端点处0, n-1，两个pivot，或者序列的中间，序列中间的话必须是3个，第一次1个pivot，第二次两个pivot；

#include<iostream>
#include<vector>
using namespace std;
int main(void) {
    int i, j, k, m, n, K, N;
    cin>>K;
    for(i = 0; i < K; i++) {
        cin>>N;
        vector<int> v(N, 0), tmp, maxmax(N, -999999999), minmin(N+1, 999999999);
        for(j = 0; j < N; j++) {
            scanf("%d", &v[j]);
            if(j==0) maxmax[0] = v[0];
            if(j!=0) maxmax[j] = max(maxmax[j-1], v[j]);
        }
        maxmax[0] = v[0];
        minmin[N] = v[N-1];
        for(j = N-1; j >= 0; j--) {
            minmin[j] = min(minmin[j+1], v[j]);
        }
        tmp = v;
        int cnt = 0;
        for(j = 0; j < N; j++) {
            if(minmin[j]==maxmax[j]){
                cnt++;
            }
        }
        if(cnt==2) {
            if(minmin[0]==maxmax[0] || minmin[N-1]==maxmax[N-1]){
                printf("Yes\n");
            }else {
                printf("No\n");
            }
        }else if(cnt>=3) {
            printf("Yes\n");
        }else {
            printf("No\n");
        }
    }
    return 0;
}
