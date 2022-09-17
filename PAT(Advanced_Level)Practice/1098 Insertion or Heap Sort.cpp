#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;
vector<int> s6;

void printvec(vector<int> a){
    for(int i=0; i<a.size();i++){
        cout<<a[i];
        if(i!=(a.size()-1))
            cout<<" ";
    }
    cout<<endl;
}

void max_heapify(int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while(son <= end) {
        if(son + 1 < end && s6[son] < s6[son + 1])
            son++;
        if(s6[dad] > s6[son]) {
            return;
        }
        else {
            swap(s6[son], s6[dad]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
    return;
}

int main(void){
    vector<int> s0, s1, s2;
    int n, num;
    bool res;
    cin>>n;
    int input[n];
    s6.resize(n);
    for(int i=0; i<n; i++){
        cin>>num;
        s0.push_back(num);
        s6[i] = num;
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
    marked = -3;
    int len = s0.size();
    for(int i = len/2 - 1; i >= 0; i--)   //create heap struct
        max_heapify(i, len - 1);
    for(int i = len - 1; i > 0; i--) { //move the largest to end and recreate heap struct
        if(marked>0){
            cout<<"Heap Sort"<<endl;
            printvec(s6);
            return 0;
        }
        if(s6==s1)
            marked = 3;
        swap(s6[0], s6[i]);
        max_heapify(0, i - 1);
        
    }
    if(marked>0){
        cout<<"Heap Sort"<<endl;
        printvec(s6);
    }
    return 0;
}
