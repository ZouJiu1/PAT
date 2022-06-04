#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

struct people{
    string str;
    int year;
    int month;
    int day;
};

bool compare(const people &a, const people &b){
    if(a.year < b.year){
        return true;
    }else if(a.year == b.year){
        if(a.month < b.month){
            return true;
        }else if(a.month == b.month){
            if(a.day <= b.day)
                return true;
            else
                return false;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

int main(void){
    vector<people> peo;
    string i1, i2, sub;
    int n, i, tmp0, tmp1, tmp2;
    int count=0;
    cin>>n;
    for(i=0; i<n; i++){
        cin>>i1>>i2;

        sub = i2.substr(0, 4);
        tmp0 = atoi(sub.c_str());
        sub = i2.substr(5, 2);
        tmp1 = atoi(sub.c_str());
        sub = i2.substr(8, 2);
        tmp2 = atoi(sub.c_str());

        // if(i2<"1814/09/06"||i2>"2014/09/06")
        //     continue;
        if((tmp0==1814&&tmp1==9&&tmp2<6)||(tmp0==2014&&tmp1==9&&tmp2>6))
            continue;
        else if((tmp0==1814&&tmp1<9)||(tmp0==2014&&tmp1>9))
            continue;
        else if(tmp0<1814||tmp0>2014)
            continue;
            
        people ple;
        ple.year = tmp0;
        ple.month = tmp1;
        ple.day = tmp2;
        ple.str = i1;
        peo.push_back(ple);
        count++;
    }
    if(count==0)
    {
        cout<<0;
        return 0;
    }

    sort(peo.begin(), peo.end(), compare);
    cout<<count<<" "<<peo[0].str<<" "<<peo[count-1].str<<endl;
    return 0;
}
