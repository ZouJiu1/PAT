#include<iostream>
#include<vector>
#include<algorithm>

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
    vector<int> s0;
    int n, num;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num;
        s0.push_back(num);
    }
    for(int i=0; i<n-1; i++){
        if(s0[i+1]<s0[i]){
            for(int j=0; j<=i; j++){
                if(s0[j]>=s0[i+1]){
                    s0.insert(s0.begin()+j, s0[i+1]);
                    s0.erase(s0.begin()+i+2);
                }
            }
        }
    }
    printvec(s0);
    return 0;
}
