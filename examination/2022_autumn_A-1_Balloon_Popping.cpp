/*
考试的时候脑子蒙了，没想到下标index可以直接用来计数
还单独用了map来存储index，最后导致两个map嵌套循环遍历最后两个测试点超时了
*/
方法1
//for的嵌套循环，使用break提前退出循环
#include<iostream>
#include<vector>
using namespace std;
int main(void) {
    int i, j, k, m, n, h, ww, maxmax = -999999999, pre=-9;
    cin>>n>>h;
    vector<int> v;
    for(i = 0; i < n; i++) {
        cin>>k;
        v.push_back(k);
    }
    if(n==1) {
        cout<<v[0]-h<<" "<<1<<endl;
        return 0;
    }
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            m = v[j] - v[i];
            if(m > h) break;
            k = j - i + 1;
            if(k > maxmax) {
                ww = v[j] - h;
                maxmax = k;
            }
        }
    }
    cout<<ww<<" "<<maxmax<<endl;
    return 0;
}

方法2
//https://www.acwing.com/file_system/file/content/whole/index/content/6598235/
//使用二分法进行lower_bound查找>=的最小数值的position  upper_bound查找>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
    int i, j, k, m, n, h, ww, maxmax=-999999999;
    cin>>n>>h;
    vector<int> v;
    for(i = 0; i < n; i++) {
        cin>>k;
        v.push_back(k);
    }
    for(i = 0; i < n; i++) {
        auto it = lower_bound(v.begin(), v.end(), v[i] - h); //the position of first element >= (v[i]-h)
        m = it - v.begin();
        k = i - m + 1; 
        if(k > maxmax) {
            maxmax = k;
            ww = v[i] - h;
        }
    }
    cout<<ww<<" "<<maxmax<<endl;
    return 0;
}

方法3 
//https://call1ce.github.io/posts/PAT-2022%E5%B9%B4%E7%A7%8B%E5%AD%A3%E8%80%83%E8%AF%95-Balloon-Popping-&-The-Second-Run-of-Quicksort-&-Leader-of-the-Opinion-Leaders-&-Pseudo-completeness/
//这里使用双指针方法
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
    int i, j, k, m, n, h, ww, maxmax=-999999999;
    cin>>n>>h;
    vector<int> v;
    for(i = 0; i < n; i++) {
        cin>>k;
        v.push_back(k);
    }
    if(n==1) {
        cout<<v[0]-h<<" "<<1<<endl;
        return 0;
    }
    int l = 0, r = 1;
    while(l < r && r < n) {
        while(v[r] - v[l] < h && r < n) {
            r++;
        }
        if(v[r] - v[l] > h) {
            if(maxmax < r - l) {
                maxmax = r - l;
                ww = v[r-1] -h;
            }
        }else if(v[r]-v[l]==h){
            if(maxmax < r - l + 1) {
                maxmax = r - l + 1;
                ww = v[r] -h;
            }
        }
        l++;
    }
    cout<<ww<<" "<<maxmax<<endl;
    return 0;
}

最开始做题的时候提交的超时版本
//myself submit original
#include<iostream>
#include<vector>
#include<map>
using namespace std;
int num[2000006];
int main(void) {
    int i, j, k, m, n, h, ww, minmin, pre=-9;
    cin>>n>>h;
    vector<int> v, kp;
    map<int, int> mp;
    for(i = 0; i < n; i++) {
        cin>>k;
        if(i==0) minmin = abs(k);
        ww = k+minmin;
        v.push_back(ww);
        mp[ww] = mp[pre] + 1;
        pre = ww;
    }
    int start = v[0], end = v[0] + h;
    int maxmax = -999999999, st, en;
    for(auto it:mp){
        for(auto ti:mp) {
            if(it.first >= ti.first) continue;
            if(ti.first - it.first > h) break;
            k = ti.second - it.second + 1;
            if(k > maxmax) {
                st = it.first;
                en = ti.first;
                maxmax = k;
            }
        }
    }
    cout<<en - minmin - h<<" "<<maxmax<<endl;
    return 0;
}
