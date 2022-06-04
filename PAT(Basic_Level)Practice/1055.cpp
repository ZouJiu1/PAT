#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<bits/stdc++.h>

using namespace std;

struct camera{
    string s0;
    int num;
};

bool compare(const camera a, const camera b){
    if(a.num>b.num)
        return true;
    else if(a.num==b.num){
        if(a.s0<b.s0)
            return true;
        else
            return false;
    }else{
        return false;
    }
}

int main(void){
    double dle0, dle1;
    vector<camera> vec;
    string s0;
    int n, k, num, col, remain, mid, midrem;
    cin>>n>>k;
    for(int i=0; i<n; i++){
        camera cam;
        cin>>cam.s0>>cam.num;
        vec.push_back(cam);
    }
    col = floor((double)n/(double)k);
    remain = n - col*k + col;
    sort(vec.begin(), vec.end(), compare);
    mid = floor((double)col/(double)2.0)+1;
    midrem = floor((double)remain/(double)2.0)+1;
    string s3[remain];
    string s6[col];
    int ind, add=0;
    for(int i=0; i<remain; i++){
        if(i%2==1){
            add++;
            ind = midrem - add - 1;
            if(ind<0)
                continue;
        }
        else{
            ind = midrem + add - 1;
            if(ind>=remain)
                continue;
        }
        s3[ind]=vec[0].s0;
        vec.erase(vec.begin());
    }
    for(int i=0; i<remain; i++){
        cout<<s3[i];
        if(i!=(remain-1))
            cout<<" ";
    }
    cout<<endl;
    for(int j=0; j<k-1; j++){
        add = 0;
        for(int i=0; i<col; i++){
            if(i%2==1){
                add++;
                ind = mid - add - 1;
                if(ind<0)
                    continue;
            }
            else{
                ind = mid + add - 1;
                if(ind>=col)
                    continue;
            }
            s6[ind]=vec[0].s0;
            vec.erase(vec.begin());
        }
        for(int i=0; i<col; i++){
            cout<<s6[i];
            if(i!=(col-1))
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
