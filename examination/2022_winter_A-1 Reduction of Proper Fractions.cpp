#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
struct nod{string val; int num=0;};
int main() {
    string a, c, aa, cc;
    int k, h, y, z, i, j, status0[10], status1[10];
    float res1, res2;
    cin >> a >> c;
    y = stoi(a);
    z = stoi(c);
    res1 = y / (float)z;
    fill(status0, status0+10, 0);  //不能多删也就是一个重复删除一个
    fill(status1, status1+10, 0);  //不能多删也就是一个重复删除一个
    for(i = 0; i < a.length(); i++) { 
        int kk = -9;
        for(j = 0; j < c.length(); j++) {
            if(status1[j]==0 && a[i]==c[j]) {
                status1[j] = 1;
                kk = 9;
                break;
            }
        }
        if(kk < 0) aa += a[i];
    }
    for(i = 0; i < c.length(); i++) {
        int kk = -9;
        for(j = 0; j < a.length(); j++) {
            if(status0[j]==0 && c[i]==a[j]) {
                status0[j] = 1;
                kk = 9;
                break;
            }
        }
        if(kk < 0) cc += c[i];
    }
    if(aa.length()==0) aa="0";
    if(cc.length()==0) cc="0";   //删完以后用0代替
    if(abs(res1- (stoi(aa) / (float)stoi(cc))) < 0.00000001) {
        printf("%d/%d = %d/%d", stoi(a), stoi(c), stoi(aa), stoi(cc));
    }else printf("%d/%d != %d/%d", stoi(a), stoi(c), stoi(aa), stoi(cc));
    return 0;
}
