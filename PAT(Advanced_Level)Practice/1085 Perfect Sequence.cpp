auto it = lower_bound(v.begin(), v.end(), (long long)v[j] * p, greater<long long>());
加入greater<long long>());，则是<=，或者upper_bound <，此时v从大到小排列
默认lower_bound >=   upper_bound >    v从小到大排列
it – v.begin()拿到index

方法1：upper_bound二分法找到第一个 > 某数的position
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
    int i, j, m, n, N, maxmax = -999999999;
    long long k, p;
    cin>>N>>p;
    vector<long long int> v(N);
    for(i = 0; i < N; i++) scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    for(j = 0; j < N; j++) {
        int it = upper_bound(v.begin(), v.end(), (long long)v[j] * p) - v.begin(); //>的第一个值position
        if(maxmax < it - j) maxmax = it - j;
    }
    cout<<maxmax<<endl;
    return 0;
}

方法2： for 嵌套循环提前break，双指针的方法
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
    int i, j, k, m, n, N, p, maxmax = 0;
    cin>>N>>p;
    vector<long long> v(N);
    for(i = 0; i < N; i++) scanf("%d", &v[i]);
    if(N==1) {
        cout<<v[0]<<endl;
        return 0;
    }
    sort(v.begin(), v.end());
    // for(i = 0; i < N; i++) {   //用这个嵌套循环会超时
    //     if(N - i < maxmax) break;
    //     for(j = N - 1; j >= 0; j--) {
    //         if(maxmax >= j - i + 1) break;
    //         if(v[j] <= v[i] * p && maxmax < j - i + 1) {
    //             maxmax = j - i + 1;
    //         }
    //         if(v[j] <= v[i] * p) break;
    //     }
    // }
    for(i = 0; i < N; i++) {
        for(j = i + maxmax; j < N; j++) {
            if(v[j] <= v[i] * p && maxmax < j - i + 1) {
                maxmax = j - i + 1;
            }
            if(v[j] > v[i] * p) break;
        }
    }
    cout<<maxmax<<endl;
    return 0;
}

/*排序然后左右遍历 */
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    long long i, j, k, m, n, w, x, y;
    cin>>n>>m;
    vector<long long> v;
    for(i = 0; i < n; i++){
        cin>>k;
        v.push_back(k);
    }
    
    sort(v.begin(), v.end());
    x = -9999999;
    for(i = n-1; i > 0; i--){
        w = v[i];
        k = w/m;
        for(j = 0; j < n; j++){
            if(i==j) break;
            if(v[j] < k) continue;
            if(w<=v[j]*m){
                y = i - j + 1;
                if(y>x) x = y;
                break;
            }
        }
    }
    if(x>0) cout<<x;
    else cout<<v[0];
    return 0;
}
