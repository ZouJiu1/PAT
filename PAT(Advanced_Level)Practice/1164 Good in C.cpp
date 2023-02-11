update202302
不能存在多的空行，测试案例是--H--EL1LO--，空字符串不放入列表，最后一个字符可能是alpha，要特殊处理，
最后一行要输出\n，\n不是空行是nextline，两个\n\n才是空行的
#include<iostream>
#include<string> 
#include<vector>
using namespace std;
string arr[26][7];
int main(void) {
    int i, j, k, m, n, N, M, K;
    string t0, t1="", t2;
    for(i = 0; i < 26; i++) {
        for(j = 0; j < 7; j++) {
            getline(cin, t0);
            arr[i][j] = t0;
        }
    }
    getline(cin, t0);
    vector<string> v, r;
    for(i = 0; i < t0.length(); i++) {
        if(isalpha(t0[i])&&isupper(t0[i])) {
            t1 += t0[i];
            if(i==t0.length()-1) v.push_back(t1);
        }
        else {
            if(t1.length()!=0) v.push_back(t1);
            t1.clear();
        }
    }
    for(i = 0; i < v.size(); i++) {
        for(k = 0; k < 7; k++) {
            t2.clear();
            for(j = 0; j < v[i].length(); j++) {
                t2 += arr[v[i][j]-'A'][k];
                if(j!=v[i].length()-1) t2 += " ";
            }
            r.push_back(t2);
        }
        if(i!=v.size()-1) r.push_back("plt");
    }
    for(i = 0; i < r.size(); i++) {
        if(r[i]!="plt") cout<<r[i]<<endl;
        if(r[i]=="plt") printf("\n");
    }
    return 0;
}

update202302  双指针方式
#include<iostream>
#include<string>
using namespace std;
char arr[26][7][6], out[7][100];
string t;
int main(void) {
    int i, j, k, m, n, N, M, K, flg=-1;
    for(i = 0; i < 26; i++) {
        for(j = 0; j < 7; j++) { 
            scanf("%s", arr[i][j]);
        }
    }
    getchar();
    getline(cin, t);
    for(i = 0; i < t.length();) {
        j = i;
        while(j < t.length() && t[j] <= 'Z' && t[j] >= 'A') j++;
        if(i==j) {
            i++;
            continue;
        }
        for(k = i; k < j; k++) {
            for(int ij = 0; ij < 7; ij++) {
                for(int kk = 0; kk < 5; kk++) {
                    out[ij][kk + (k - i) * 6] = arr[t[k] - 'A'][ij][kk];
                }
            }
        }
        if(flg > 0) printf("\n");
        for(int ij = 0; ij < 7; ij++) {
            for(k = 0; k < (j-i)*6-1; k++) {
                if(out[ij][k]=='.'||out[ij][k]=='C') printf("%c", out[ij][k]);
                else printf(" ");
            }
            flg = 1;
            printf("\n");
        }
        i = j+1;
    }
    return 0;
}


old before
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
