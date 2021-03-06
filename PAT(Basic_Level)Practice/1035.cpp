#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

void printvec(vector<int> a){
    for(int i=0; i<a.size();i++){
        cout<<a[i];
        if(i!=(a.size()-1))
            cout<<" ";
    }
    cout<<endl;
}

int main(void){
    vector<int> s0, s1, s2;
    int n, num;
    bool res;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>num;
        s0.push_back(num);
    }
    for(int i=0; i<n; i++){
        cin>>num;
        s1.push_back(num);
    }
    if(n==1)
    {
        cout<<"Insertion Sort"<<endl;
        cout<<s0[0];
        return 0;
    }
    s2 = s0;
    int marked = -3;
    for(int i=0; i<n-1; i++){
        if(s0[i+1]<s0[i]){
            for(int j=0; j<=i; j++){
                if(s0[j]>=s0[i+1]){
                    res = s0==s1;
                    if(marked>0){
                        cout<<"Insertion Sort"<<endl;
                        printvec(s0);
                        return 0;
                    }
                    if(res)
                        marked = 3;
                    s0.insert(s0.begin()+j, s0[i+1]);
                    s0.erase(s0.begin()+i+2);
                }
            }
        }
    }
    if(marked>0){
        cout<<"Insertion Sort"<<endl;
        printvec(s0);
        return 0;
    }
    s0=s2;
    s2.erase(s2.begin(), s2.end());

    int seg = 1, left, right, length, count = 0;
    for(int i = 0; i < n; i++){
        if(seg>n)
            break;
        for(int j = 0; j < n; j = j + seg * 2){
            left = (n-j)>=seg? seg:(n-j);
            right = (n-j-seg)>=seg? seg:(n-j-seg);
            right = (right>=0)? right:0;
            length = (left>right)? left*2:right*2;
            int countl = 0, countr = 0;
            while(length--){
                if(s0[j+countl]>s0[j+countr+seg]&&right>0){
                    s2.push_back(s0[j+countr+seg]);
                    right--;
                    countr++;
                }else if(s0[j+countl]<s0[j+countr+seg]&&left>0){
                    s2.push_back(s0[j+countl]);
                    countl++;
                    left--;
                }
            }
            while(left--){
                s2.push_back(s0[j+countl]);
                countl++;
            }
            while(right--){
                s2.push_back(s0[j+countr+seg]);
                countr++;
            }
        }
        s0 = s2;
        res = s0==s1;
        if(marked>0){
            cout<<"Merge Sort"<<endl;
            printvec(s0);
            return 0;
        }
        if(res)
            marked = 3;
        s2.erase(s2.begin(),s2.end());
        seg = seg * 2;
    }
    return 0;
}
