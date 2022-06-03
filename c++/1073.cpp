#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int N, M;
    char n0, n1, n2;
    cin>>N>>M;
    string s0;
    vector<char> vec0[1001], res[1001];
    vector<string> vec3;
    set<char> st[1001];
    int errors[101][6]={0};
    int question[101];
    for(int i=0; i<M; i++){
        cin>>n0>>n1>>n2;
        vec0[i].push_back(n0);
        vec0[i].push_back(n1);
        vec0[i].push_back(n2);
        for(int j=0; j<(n2 - '0'); j++){
            cin>>n0;
            vec0[i].push_back(n0);
            res[i].push_back(n0);
            st[i].insert(n0);
        }
    }
    cin.get();
    for(int i=0; i<N; i++){
        getline(cin, s0);
        vec3.push_back(s0);
    }
    int pre, counts, mar=0, maxnum;
    float sum=0;
    for(int i=0; i<N; i++){
        s0 = vec3[i];
        pre = -666;
        counts = 0;
        sum = 0;
        vector<char> vec6[101];
        set<char> predict[1001];
        for(int ij=3; ij<s0.size(); ij++){
            if(s0[ij-3]=='('){
                pre = 666;
                vec6[counts].push_back(s0[ij]);
                predict[counts].insert(s0[ij]);
                continue;
            }
            if(s0[ij]==')') {
                pre = -666; 
                counts++;
            }
            if(pre>0&&s0[ij]!=' ') { 
                vec6[counts].push_back(s0[ij]); 
                predict[counts].insert(s0[ij]);
            }
        }
        for(int j=0; j<M; j++){
            if(vec6[j]==res[j]){
                sum += vec0[j][0] - '0';
                continue;
            }
            pre = -666;
            for(int ww=0; ww<vec6[j].size(); ww++){
                set<char>::iterator it = st[j].find(vec6[j][ww]);
                if(it==st[j].end()){
                    pre = 666;
                    mar++;
                    errors[j][vec6[j][ww]-'a']++;
                }
            }
            for(int ww=0; ww<res[j].size(); ww++){
                set<char>::iterator it = predict[j].find(res[j][ww]);
                if(it==predict[j].end()){
                    mar++;
                    errors[j][res[j][ww]-'a']++;
                }
            }
            if(pre<0){
                sum += (float)(vec0[j][0] - '0')/(float)2.0;
            }
        }
        printf("%.1f\n", sum);
    }
    int m, n;
    maxnum = -666666;
    for(int i = 0; i < M; i++){
        for(int j=0; j<6; j++){
            if(errors[i][j]>maxnum) maxnum = errors[i][j];
        }
    }
    if(maxnum==0){
        cout<<"Too simple";
        return 0;
    }
    int kk;
    for(int i = 0; i < M; i++){
        kk = -666;
        for(int j=0; j<6; j++){
            if(errors[i][j]==maxnum){
                cout<<maxnum<<" "<<(i+1)<<"-"<<char(j+'a')<<endl;;
            }
        }
    }
    return 0;
}
