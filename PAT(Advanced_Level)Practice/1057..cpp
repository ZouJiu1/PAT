#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    string s, s0;
    string key[2] = {"Pop", "PeekMedian"};
    stack<int> sk;
    int i, j, m, n, t, counts, x, y, cnt=0;
    cin>>m;
    cin.get();
    vector<int> v, v0;
    for(i=0; i<m; i++){
        getline(cin, s);
        if(s==key[0]){
            if(sk.size()==0){
                cout<<"Invalid"<<endl;
                continue;
            }else{
                cout<<sk.top()<<endl;
                sk.pop();
                v.pop_back();
            }
        }else if(s==key[1]){
            if(sk.size()==0) cout<<"Invalid"<<endl;
            else{
                v0 = v;
                sort(v0.begin(), v0.end());
                if(v0.size()%2!=0){
                    cout<<v0[(v0.size()+1)/2 - 1]<<endl;
                }else{
                    cout<<v0[v0.size()/2 - 1]<<endl;
                }
            }
        }
        else{


            s0 = s.substr(5, s.length() - 5);
            y = stoi(s0);
            sk.push(y);
            v.push_back(y);
        }
    }
    return 0;
}
