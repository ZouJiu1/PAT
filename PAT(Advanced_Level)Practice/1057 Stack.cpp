/*block，计数的时候使用块计算总和，不要单个相加 */
#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<map>
#include<bits/stdc++.h>

using namespace std;
int position[100001];
int partion[100001/316+1];
int part = 316;

int peekmedian(int h){
    int i=0, j=0;
    int sum = 0;
    while(sum < h) 
        sum += partion[i++];
    sum -= partion[i-1];
    j = (i-1) * part;
    while(sum < h)
        sum +=position[j++];
    return j;
}

int main(void){
    string s, s0;
    stack<int> sk;
    int i, j, m, n, t, counts, x, y, cnt=0, sum;
    cin>>m;
    memset((void *)position, 0, sizeof(int) * 100001);
    memset((void *)partion,  0, sizeof(int) * 100001/316+1);
    for(i=0; i<m; i++){
        cin>>s;
        if(s[1]=='o'){
            if(sk.size()==0){
                cout<<"Invalid"<<endl;
                continue;
            }else{
                y = sk.top();
                cout<<y<<endl;
                position[y] -= 1;
                partion[y/part] -= 1;
                sk.pop();
            }
        }else if(s[1]=='e'){
            if(sk.size()==0) cout<<"Invalid"<<endl;
            else{
                if(sk.size()%2!=0)
                    sum = peekmedian((sk.size()+1)/2);
                else
                    sum = peekmedian(sk.size()/2);
                cout<<sum-1<<endl;
            }
        }
        else{
            scanf("%d", &y);
            position[y] += 1;
            partion[y/part] += 1;
            sk.push(y);
        }
    }
    return 0;
}
