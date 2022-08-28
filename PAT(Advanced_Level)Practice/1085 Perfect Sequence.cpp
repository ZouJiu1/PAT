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
