#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int n, num, tmp;
    string s0, st, sw;
    string s2[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", 
    "jly", "aug", "sep", "oct", "nov", "dec"};
    string s6[12] = {"tam", "hel", "maa", "huh", "tou", "kes", 
    "hei", "elo", "syy", "lok", "mer", "jou"};
    vector<string> vec;
    cin>>n;
    cin.get();
    for(int i=0; i<n; i++){
        getline(cin, s0);
        vec.push_back(s0);
    }

    for(int i=0; i<n; i++){
        s0 = vec[i];
        if(s0[0]<='9'&&s0[0]>='0'){
            num = atoi(s0.c_str());
            tmp = num/13;
            if(tmp!=0){
                cout<<s6[tmp-1];
                tmp = num%13;
                if(tmp==0){
                    cout<<endl;
                    continue;
                }
                else
                    cout<<" "<<s2[tmp]<<endl;
            }else{
                tmp = num%13;
                cout<<s2[tmp]<<endl;
            }
        }else{
            tmp = s0.find(" ");
            if(s0.find(" ")==string::npos){
                st = s0;
                tmp = 0;
                for(int j=0; j<13; j++){
                    if(s2[j]==st){
                        cout<<j<<endl;
                        break;
                    }
                }
                for(int j=0; j<12; j++){
                    if(s6[j]==st){
                        cout<<(j+1)*13<<endl;
                        break;
                    }
                }
            }else{
                st = s0.substr(0, tmp);
                sw = s0.substr(tmp+1, s0.size() - tmp);
                
                tmp = 0;
                for(int j=0; j<12; j++){
                    if(s6[j]==st){
                        tmp += (j+1)*13;
                        break;   
                    }
                }
                for(int j=0; j<13; j++){
                    if(s2[j]==sw){
                        tmp += j;
                        break;
                    }
                }
                cout<<tmp<<endl;
            }
        }
    }
    return 0;
}
