#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<ctype.h>
using namespace std;
bool captial_alpha(char a) {return isupper(a)&&isalpha(a);}
int main(void) {
    int i, j, k, m, n, x1, x2;
    unordered_map<char, vector<string>> mp;
    vector<string> v, vtt, tv;
    vector<char> vc;
    string t, tt, ttt;
    for(char a = 'A'; a <= 'Z'; a++) {
        for(i = 0; i <= 6; i++) {
            getline(cin, t);
            mp[a].push_back(t);
        }
    }
    
    getline(cin, t);
    for(i = 0; i < t.length() - 1; i++) {
        if(captial_alpha(t[i]) && !captial_alpha(t[i+1])) tt = tt + t[i] + "-";
        else if(captial_alpha(t[i])) tt += t[i];
    }
    if(captial_alpha(t[i])) tt = tt + t[i];
    t = tt;
    for(i = 0; i < t.length(); i++) {
        if(captial_alpha(t[i])) vc.push_back(t[i]);
        if(!(captial_alpha(t[i])) || i==t.length() - 1){
            v.resize(11);
            for(x1 = 0; x1 < vc.size(); x1++) {
                for(j = 0; j <= 6; j++) {
                    v[j] += mp[vc[x1]][j];
                    if(x1!=vc.size()-1) v[j]+=" ";
                }
            }
            for(j = 0; j < 11; j++) if(v[j].length() > 0) vtt.push_back(v[j]);
            vc.clear();
            v.clear();
            if(!(captial_alpha(t[i])) && i!=t.length() - 1) vtt.push_back("---");
        }
    }
    for(i = 0; i < vtt.size(); i++) {
        if(vtt[i]=="---") cout<<endl;
        else cout<<vtt[i]<<endl;
    }
    return 0;
}
