#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

struct score{
    string num;
    int s1;
    int s2;
};

bool compare(const score &a, const score &b){
    if((b.s1+b.s2)==(a.s1+a.s2)&&a.s1==b.s1)
        return a.num < b.num;
    else if((b.s1+b.s2)==(a.s1+a.s2))
        return a.s1 > b.s1;
    return (a.s1+a.s2) > (b.s1+b.s2);
}

int main(void){
    int N, L, H, i, n2, n3;
    string n1;
    cin>>N>>L>>H;
    vector<score> vec0;
    vector<score> vec1;
    vector<score> vec2;
    vector<score> vec3;
    for(int i=0; i<N; i++){
        cin>>n1>>n2>>n3;
        score sco;
        sco.num = n1;
        sco.s1 = n2;
        sco.s2 = n3;
        if(n2>=H&&n3>=H){
            vec0.push_back(sco);
        }
        else if(n2>=H&&n3<H&&n2>=L&&n3>=L){
            vec1.push_back(sco);
        }
        else if(n2<H&&n3<H&&n2>=n3&&n2>=L&&n3>=L){
            vec2.push_back(sco);
        }
        else if(n2>=L&&n3>=L){
            vec3.push_back(sco);
        }
    }
    int all = vec0.size() + vec1.size() + vec2.size() + vec3.size();
    cout<<all<<endl;
    if(!all)
        return 0;
    if(vec0.size()){
        sort(vec0.begin(), vec0.end(), compare);
        for(i = 0; i < vec0.size(); i++){
            cout<<vec0[i].num<<" "<<vec0[i].s1<<" "<<vec0[i].s2<<endl;
        }
    }
    if(vec1.size()){
        sort(vec1.begin(), vec1.end(), compare);
        for(i = 0; i < vec1.size(); i++){
            cout<<vec1[i].num<<" "<<vec1[i].s1<<" "<<vec1[i].s2<<endl;
        }
    }
    if(vec2.size()){
        sort(vec2.begin(), vec2.end(), compare);
        for(i = 0; i < vec2.size(); i++){
            cout<<vec2[i].num<<" "<<vec2[i].s1<<" "<<vec2[i].s2<<endl;
        }
    }
    if(vec3.size()){
        sort(vec3.begin(), vec3.end(), compare);
        for(i = 0; i < vec3.size(); i++){
            cout<<vec3[i].num<<" "<<vec3[i].s1<<" "<<vec3[i].s2;
            if(i!=vec3.size()-1) cout<<endl;
        }
    }
    return 0;
}
