#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

int main(void){
    int i, j, m, n, k, w, q;
    string s;
    cin>>s;
    if(s=="0") {
        cout<<"ling";
        return 0;
    }
    map<char, string> mp{{'1', "yi"},{'2', "er"},{'3', "san"},
                        {'4', "si"},{'5', "wu"},{'6', "liu"},
                        {'7', "qi"},{'8', "ba"},{'9', "jiu"}};
    if(s[0]=='-') {
        cout<<"Fu ";
        s.erase(s.begin(), s.begin() + 1);
    }
    k = 0;
    q = s.length();
    w = 999;
    char c;
    vector<string> vec;
    for(i = s.length(); i>0; i--){
        c = s[s.length() - i];
        if(s[s.length()-i+1]!='0'&&c=='0'&&i!=1){
            vec.push_back("ling");
        }
        else if((s[s.length()-i+1]=='0'&&c=='0')||
                 (i==1)&&s[s.length()-1]==0){
        }
        else if(i%4==0&&c!='0'){
            vec.push_back(mp[c]);
            vec.push_back("Qian");
        }
        else if(i%4==3&&c!='0'){
            vec.push_back(mp[c]);
            vec.push_back("Bai");
        }
        else if(i%4==2&&c!='0'){
            vec.push_back(mp[c]);
            vec.push_back("Shi");
        }
        else if(i%4==1&&c!='0'){
            vec.push_back(mp[c]);
        }
        if(i==9) vec.push_back("Yi");
        if(i==5) vec.push_back("Wan");
    }
    for(i = 0; i < vec.size(); i++){
        cout<<vec[i];
        if(i!=vec.size()-1) cout<<" ";
    }
    return 0;
}
