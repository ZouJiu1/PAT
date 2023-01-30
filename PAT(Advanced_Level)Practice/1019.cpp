update202301 存在错误范例，不能用string存储
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
    int i, j, k, m, n;
    cin>>m>>n;
    vector<int> v, v0;
    while(m!=0) {
        k = m%n;
        m = m / n;
        v.push_back(k);
    }
    v0 = v;
    reverse(v.begin(), v.end());
    if(v0==v) printf("Yes\n");
    else printf("No\n");
    for(i = 0; i < v.size(); i++) {
        printf("%d", v[i]);
        if(i!=v.size() - 1) printf(" ");
    }
    if(v.size()==0) printf("0\n");
    return 0;
}

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(){
    long long a, w, c;
    int x, y, m;
    cin>>a>>c;
    string s, s0;
    vector<int> v, v0;
    w = a;
    if(w==0) s+='0';
    while(w!=0){
        w = a/c;
        y = a%c;
        s += to_string(y);
        v.push_back(y);
        a= w;
    }
    v0 = v;
    reverse(v.begin(), v.end());
    if(v0==v) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i];
        if(i!=(v.size()-1)) cout<<" ";
    }
    return 0;
}

// #include<iostream>
// #include<string>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int main(void) {
//     int i, j, k, m, n;
//     cin>>m>>n;
//     string t0, t1;
//     vector<int> v;
//     while(m!=0) {
//         k = m%n;
//         m = m / n;
//         t0 += to_string(k);  //错误范例存在[0, 13, 16]  01316但是[16 13 0]  61310
// [1, 13, 31, 1]  113311但是[1, 31, 13, 1]两者不相等，string倒置会判断相等, 113311
// [19, 91]  1991但是[91, 19]两者不相等，string倒置会判断相等, 1991
//         v.push_back(k);
//     }
//     t1 = t0;
//     reverse(t0.begin(), t0.end());
//     reverse(v.begin(), v.end());
//     if(t0==t1) printf("Yes\n");
//     else printf("No\n");
//     for(i = 0; i < v.size(); i++) {
//         printf("%d", v[i]);
//         if(i!=v.size() - 1) printf(" ");
//     }
//     if(v.size()==0) printf("0\n");
//     return 0;
// }
