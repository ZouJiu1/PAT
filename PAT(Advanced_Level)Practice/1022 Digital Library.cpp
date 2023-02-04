update202302
#include<iostream>
#include<string>
#include<set>
#include<unordered_map>
#include<vector>
using namespace std;
int main(void) {
    int i, j, k, m, n, N, M, y, z;
    cin>>N;
    string id, _title_, _author_, _pub_, _yea_, t0, t1;
    set<string> tr;
    unordered_map<string, set<string>> title, author, key, pub, yea;
    for(i = 0; i < N; i++) {
        cin>>id;
        getchar(); //cin.get();
        getline(cin, _title_);
        getline(cin, _author_);
        getline(cin, t0);
        auto it = t0.find(" ");
        while(it!=string::npos){
            t1 = t0.substr(0, it);
            t0 = t0.substr(it+1);
            it = t0.find(" ");
            key[t1].insert(id);
        }
        if(t0.size() > 0) key[t0].insert(id);
        getline(cin, _pub_);
        cin>>_yea_;
        title[_title_].insert(id);
        author[_author_].insert(id);
        pub[_pub_].insert(id);
        yea[_yea_].insert(id);
    }
    cin>>M;
    getchar();
    for(i = 0; i < M; i++) {
        scanf("%d: ", &k);
        getline(cin, t0);
        if(k==1) tr = title[t0];
        else if(k==2) tr = author[t0];
        else if(k==3) tr = key[t0];
        else if(k==4) tr = pub[t0];
        else if(k==5) tr = yea[t0];
        cout<<k<<": "<<t0<<endl;
        if(tr.size() > 0) {
            for(auto it: tr) cout<<it<<endl;
        }else printf("Not Found\n");
    }
    return 0;
}


old before
/*
要注意使用map dictionary，使用vector保存完整数据，使用map 创立索引目录保证速度符合要求
*/
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bits/stdc++.h>


using namespace std;


struct collect{
    string ID;
    string title;
    string author;
    string keywords;
    string publisher;
    string yearpublish;
};

int main(void){
    int m, n, a, b, c, d, e, f, i, j;
    vector<collect> v0, vw;
    cin>>n;
    cin.get();
    collect col;
    string st, sl;
    map<string, vector<int>> m1, m2, m3, m4, m5, m6;
    for(i = 0; i < n; i++){
        getline(cin, col.ID);
        getline(cin, col.title);
        getline(cin, col.author);
        getline(cin, col.keywords);
        getline(cin, col.publisher);
        getline(cin, col.yearpublish);
        vw.push_back(col);
        m1[col.title].push_back(i);
        m2[col.author].push_back(i);
        m4[col.publisher].push_back(i);
        m5[col.yearpublish].push_back(i);
    }
    for(i = 0; i < n; i++){
        st = vw[i].keywords;
        f = 999999;
        while(f > 0){
            e = f;
            f = st.find(' ');
            sl = st.substr(0, f);
            st.erase(st.begin(), st.begin() + f + 1);
            m3[sl].push_back(i);
        }
    }

    cin>>m;
    cin.get();
    vector<string> vtr;
    vector<int> v;
    string s0, s2;
    for(i = 0; i < m; i++){
        getline(cin, s0);
        vtr.push_back(s0);
    }
    for(i = 0; i < m; i++){
        s0 = vtr[i];
        s2 = s0;
        cout<<s2<<endl;
        c = s0[0] - '0';
        s0 = s0.substr(3, s0.length() - 3);
        vector<string> vk;
        if(c==1) v = m1[s0];
        else if(c==2) v = m2[s0];
        else if(c==3) v = m3[s0];
        else if(c==4) v = m4[s0];
        else if(c==5) v = m5[s0];
        for(j = 0; j < v.size(); j++) vk.push_back(vw[v[j]].ID);
        sort(vk.begin(), vk.end());
        if(vk.size()==0) printf("Not Found\n");
        else{
            for(j = 0; j < vk.size(); j++) cout<<vk[j]<<endl;
        }
    }
    return 0;
}
