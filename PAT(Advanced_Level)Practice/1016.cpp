/*先排序，然后对照相应的名称，进行输出要注意计算时间和费用*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

vector<int> hourbill;
int daysum = 0, alltime = 0;

struct cus{
    string s;
    string timestamp;
    string onoffl;
};

bool compare(const cus& a, const cus& b){
    if(a.s==b.s){
        if(a.timestamp<b.timestamp) return true;
        else return false;
    }else if(a.s<b.s) return true;
    else return false;
}

int getbills(int d0, int d2, int hour0, int hour2, int min0, int min2){
    int sum = 0;
    if(d0==d2&&hour0==hour2) {
        alltime = min2 - min0;
        return hourbill[hour0] * (min2 - min0);
    }
    else if(d0==d2&&hour0 < hour2){
        alltime += 60 - min0 + min2;
        sum += hourbill[hour0] * (60 - min0);
        for(int i = hour0 + 1; i < hour2; i++) {
            sum += hourbill[i] * 60;
            alltime += 60;
        }
        sum += hourbill[hour2] * min2;
    }else if(d0!=d2){
        alltime += 60 - min0 + min2;
        sum += hourbill[hour0] * (60 - min0);
        for(int i = hour0 + 1; i < 24; i++) {
            sum += hourbill[i] * 60;
            alltime += 60;
        }
        for(int i = 0; i < hour2; i++) {
            sum += hourbill[i] * 60;
            alltime += 60;
        }
        sum += hourbill[hour2] * min2;
        for(int i = d0+1; i < d2; i++) {
            sum += daysum;
            alltime += 60 * 24;
        }
    }
    return sum;
}

int main(){
    int i, j, a, b, d, e, f;
    vector<cus> v, v3;
    for(i = 0; i < 24; i++){
        cin>>a;
        hourbill.push_back(a);
        daysum += a * 60;
    }
    cin>>a;
    cus c;
    for(i = 0; i < a; i++){
        cin>>c.s>>c.timestamp>>c.onoffl;
        v.push_back(c);
    }
    sort(v.begin(), v.end(), compare);
    a = 0;
    char zt, af;
    string s, s0, s3, s6, ps, s9, s11, t0, t2;
    int hour0, min0, hour2, min2, d0, d2;
    d = 666;
    for(i = 0; i < v.size(); i++){
        s = v[i].onoffl;
        s3 = v[i].s;
        t0 = v[i].timestamp;
        zt = s[s.size() - 7];
        if((i+1)<v.size()){
            s0 = v[i+1].onoffl;
            s6 = v[i+1].s;
            t2 = v[i+1].timestamp;
            af = s0[s0.size() - 7];
        }
        if(zt=='o'&&(i+1)<v.size()&&af=='f'&&s3==s6){
            if(ps!=s3) {
                if(d<0)
                    printf("Total amount: $%.2f\n", (float)a/100.0);
                cout<<s3<<" "<<t0[0]<<t2[1]<<endl;
                a = 0;
            }

            s9 = t0.substr(3, 8);
            s11 = t2.substr(3, 8);
            cout<<s9<<" "<<s11<<" ";
            d0 = stoi(t0.substr(3, 2));
            d2 = stoi(t2.substr(3, 2));
            hour0 = stoi(t0.substr(6, 2));
            hour2 = stoi(t2.substr(6, 2));
            min0 = stoi(t0.substr(9, 2));
            min2 = stoi(t2.substr(9, 2));
            // printf("%d %d %d,       %d %d %d\n", d0, hour0, min0, d2, hour2, min2);
            f = getbills(d0, d2, hour0, hour2, min0, min2);
            a += f;
            printf("%d $%.2f\n", alltime, (float)f/100.0);
            alltime = 0;
            ps = s3;
            d = -666;
        }
    }
    printf("Total amount: $%.2f\n", (float)a/100.0);
    return 0;
}
