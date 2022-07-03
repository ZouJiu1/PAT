/*
属于较难的题目，贪心方式要次次遍历，找后续oil station里价格最低的存在，若是不存在相对目前更低的，就是直接加满；若是存在相对更低的，去更低的地方

加满以后可能找到价格更低的地方，要减去oil bank剩的oil用距离表示即可

保证oil tank里的oil价格是最低的
*/
#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

typedef struct _gas{
    float price;
    float dis;
    int items;
}gas;

bool compare(const gas &c, const gas &b){
    if(c.dis < b.dis) return true;
    else return false;
}

int main(int argc, char **argv){
    int m, n, i, j, h, w, e, r, t;
    float mon, z, x, y;
    cin>>x>>y>>z>>m;
    vector<gas> v;
    gas gs;
    for(i = 0; i < m; i++){
        cin>>gs.price>>gs.dis;
        v.push_back(gs);
    }
    sort(v.begin(), v.end(), compare);
    v.erase(v.begin() + i, v.end());
    gs.price = 0;
    gs.dis = y;
    v.push_back(gs);
    for(i = 0; i < v.size(); i++){
        v[i].items = i;
    }
    vector<float> rem, k;
    rem.push_back(0);
    mon = 0;
    k.push_back(0);
    if(v[0].dis > 0) {
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    i = 0;
    float minmin, allprice = 0, lefdis = 0;

    gs = v[0];
    while(gs.dis < y){
        float maxdis = gs.dis + x * z, flags=0;
        if(maxdis < v[gs.items + 1].dis){
            printf("The maximum travel distance = %.2f", maxdis);
            return 0;        
        }
        gas mingss = {999999, 0.0, -1};
        for(i = gs.items + 1; i <= m && v[i].dis <= maxdis; i++){
            if(v[i].dis <= gs.dis) continue;
            if(v[i].price < gs.price){
                allprice += (float)((v[i].dis - gs.dis - lefdis)/(float)z) * gs.price;
                gs = v[i];
                lefdis = 0.0;
                flags = 1;
                break;
            }
            if(v[i].price < mingss.price){
                mingss = v[i];
            }
        }
        if(flags==0){
            allprice += (float)(x - lefdis/z) * gs.price;
            lefdis = maxdis - mingss.dis;
            gs = mingss;
        }
    }
    printf("%.2f", allprice);
    return EXIT_SUCCESS;
}
