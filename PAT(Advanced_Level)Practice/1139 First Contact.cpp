
#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<string>
#include<bits/stdc++.h>

using namespace std;

struct nod {
    string C;
    string D;
};

bool compare(struct nod &a, struct nod &c) {
    if(stoi(a.C) < stoi(c.C)) return true;
    else if(stoi(a.C)==stoi(c.C)) return stoi(a.D) < stoi(c.D);
    else return false;
}

int main(void) {
    long long i, j, k, m, n;
    cin>>m>>n;
    map<string, vector<string>> mp;
    map<string, int> map_num;
    string A, B;
    int cnt = 1;
    int matrix[m+1][m+1];
    for(i = 0; i < m+1; i++) {
        for(j = 0; j < m+1; j++) {
            matrix[i][j] = 0;
        }
    }
    for(i = 0; i < n; i++) {
        cin>>A>>B;
        if(map_num[A]+0 == 0) map_num[A] = cnt++;
        if(map_num[B]+0 == 0) map_num[B] = cnt++;
        matrix[map_num[A]][map_num[B]] = matrix[map_num[B]][map_num[A]] = 9;
        mp[A].push_back(B);
        mp[B].push_back(A);
    }
    cin>>n;
    vector<string> query;
    for(i = 0; i < n; i++) {
        cin>>A>>B;
        query.push_back(A);
        query.push_back(B);
    }
    int j1, j2;
    string C, D, fin;
    vector<struct nod> res;
    for(i = 0; i < n; i++) {
        A = query[i*2];
        B = query[i*2 + 1];
        struct nod nd;
        for(j = 0; j < mp[A].size(); j++) {
            C = mp[A][j];
            if(stoi(C) * stoi(A) < 0) continue;
            if((A[0]!='-'&& C[0] != '-' && C!=B) || (A[0]=='-' && C[0]=='-' && C!=B)) {
                for(j1 = 0; j1 < mp[C].size(); j1++) {
                    D = mp[C][j1];
                    if(matrix[map_num[D]][map_num[B]] == 0 || stoi(D) * stoi(B) < 0) continue;
                    if(matrix[map_num[D]][map_num[B]] > 0 &&
                        (D[0]!='-'&& B[0] != '-' && D!=A && D!=B) ||
                        (D[0]=='-' && B[0]=='-' && D!=A && D!=B)){
                        nd.C = C[0]=='-'? C.substr(1, 3+1):C;
                        nd.D = D[0]=='-'? D.substr(1, 3+1):D;
                        res.push_back(nd);
                    }
                }
            }
        }
        sort(res.begin(), res.end(), compare);
        cout<<res.size()<<endl;
        for(j = 0; j < res.size(); j++) {
            cout<<res[j].C<<" "<<res[j].D<<endl;
        }
        res.clear();
    }
    return 0;
}

#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<string>
#include<bits/stdc++.h>

using namespace std;

struct nod {
    string C;
    string D;
};

bool compare(struct nod &a, struct nod &c) {
    if(stoi(a.C) < stoi(c.C)) return true;
    else if(stoi(a.C)==stoi(c.C)) return stoi(a.D) < stoi(c.D);
    else return false;
}

int main(void) {
    long long i, j, k, m, n;
    cin>>m>>n;
    map<string, vector<vector<string>>> mp;
    map<string, int> map_num;
    string A, B;
    int cnt = 1;
    int matrix[m+1][m+1];
    for(i = 0; i < m+1; i++) {
        for(j = 0; j < m+1; j++) {
            matrix[i][j] = 0;
        }
    }
    for(i = 0; i < n; i++) {
        cin>>A>>B;
        if(map_num[A]+0 == 0) map_num[A] = cnt++;
        if(map_num[B]+0 == 0) map_num[B] = cnt++;
        matrix[map_num[A]][map_num[B]] = matrix[map_num[B]][map_num[A]] = 9;
        if(mp[A].size()==0) mp[A].resize(2); //male female
        if(mp[B].size()==0) mp[B].resize(2); //male female
        if(B[0]=='-') mp[A][1].push_back(B);
        else mp[A][0].push_back(B);
        if(A[0]=='-') mp[B][1].push_back(A);
        else mp[B][0].push_back(A);
    }
    cin>>n;
    vector<string> query;
    for(i = 0; i < n; i++) {
        cin>>A>>B;
        query.push_back(A);
        query.push_back(B);
    }
    int j1, j2;
    string C, D, fin;
    vector<struct nod> res;
    vector<string> vt1, vt2;
    for(i = 0; i < n; i++) {
        A = query[i*2];
        B = query[i*2 + 1];
        struct nod nd;
        if(mp[A].size()==2) {
            if(A[0]=='-') vt1 = mp[A][1];
            else vt1 = mp[A][0];
        }
        for(j = 0; j < vt1.size(); j++) {
            C = vt1[j];
            if(stoi(C) * stoi(A) < 0) continue;
            if((A[0]!='-'&& C[0] != '-' && C!=B) || (A[0]=='-' && C[0]=='-' && C!=B)) {
                if(mp[C].size()==2) {
                    if(B[0]=='-') vt2 = mp[C][1];
                    else vt2 = mp[C][0];
                }
                for(j1 = 0; j1 < vt2.size(); j1++) {
                    D = vt2[j1];
                    if(matrix[map_num[D]][map_num[B]] == 0 ||D==A
                        ||D==B || stoi(D) * stoi(B) < 0) continue;
                    if(matrix[map_num[D]][map_num[B]] > 0 &&
                        (D[0]!='-'&& B[0] != '-') ||
                        (D[0]=='-' && B[0]=='-')){
                        nd.C = C[0]=='-'? C.substr(1, 3+1):C;
                        nd.D = D[0]=='-'? D.substr(1, 3+1):D;
                        res.push_back(nd);
                    }
                }
            }
        }
        sort(res.begin(), res.end(), compare);
        cout<<res.size()<<endl;
        for(j = 0; j < res.size(); j++) {
            cout<<res[j].C<<" "<<res[j].D<<endl;
        }
        res.clear();
        vt1.clear();
        vt2.clear();
    }
    return 0;
}

