#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;

struct ti{
    int score;
    int choose;
    int num_choices;
    vector<char> choice;
};

int main(void){
    int N, M, num, count = 0, pre=-6, scores=0;
    cin>>N>>M;
    char ch;
    vector<ti> vec;
    vector<char> vec0;
    string s0;
    for(int i=0; i<M; i++){
        ti tti;
        cin>>tti.score>>tti.choose>>tti.num_choices;
        for(int j=0; j<tti.num_choices; j++){
            cin>>ch;
            tti.choice.push_back(ch);
        }
        vec.push_back(tti);
    }
    int all[106];
    memset((void *)all, 0, sizeof(int)*106);
    cin.get();
    vector<string> gnistr;
    for(int i=0; i<N; i++){
        getline(cin, s0);
        gnistr.push_back(s0);
    }
    for(int i=0; i<N; i++){
        s0 = gnistr[i];
        scores=0;
        count = 0;
        for(int j=2; j<s0.size(); j++){
            if(s0[j-2]=='('){
                pre = 6;
            }
            if(s0[j]==')'){
                pre = -6;
                if(vec0==vec[count].choice) scores += vec[count].score;
                else all[count+1]++;
                count++;
                vec0.erase(vec0.begin(), vec0.end());
            }
            if(pre>0){
                if(s0[j]<='z'&&s0[j]>='a'){
                    vec0.push_back(s0[j]);
                }
            }
        }
        cout<<scores<<endl;
    }
    int max = -6666666;
    for(int i=1; i<101; i++){
        if(all[i]>max)
            max = all[i];
    }
    vector<int> number;
    for(int i=1; i<101; i++){
        if(all[i]==max)
            number.push_back(i);
    }
    if(max==0){
        cout<<"Too simple";
        return 0;
    }
    cout<<max<<" ";
    for(int i=0; i<number.size(); i++){
        cout<<number[i];
        if(i!=(number.size()-1)) cout<<" ";
    }
    return 0;
}
