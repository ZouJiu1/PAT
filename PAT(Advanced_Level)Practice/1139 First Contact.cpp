
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <string>
#include <bits/stdc++.h>

using namespace std;

struct nod {
    int C;
    int D;
};

bool compare(struct nod &a, struct nod &c) {
    return a.C!=c.C? a.C < c.C:a.D<c.D;
}

int main(void)
{
    long long i, j, k, m, n;
    cin >> m >> n;
    unordered_map<string, int> map_num;
    unordered_map<string, vector<string>> mp;
    string A, B;
    int cnt = 1;
    for (i = 0; i < n; i++) {
        cin >> A >> B;
        map_num[A+B] = map_num[B+A] = 9;
        if (A.length() == B.length()) {
            mp[A].push_back(B);
            mp[B].push_back(A);
        }
    }
    cin >> n;
    vector<string> query;
    for (i = 0; i < n; i++) {
        cin >> A >> B;
        query.push_back(A);
        query.push_back(B);
    }
    int j1, j2;
    string C, D, fin;
    vector<struct nod> res;
    for (i = 0; i < n; i++) {
        A = query[i * 2];
        B = query[i * 2 + 1];
        struct nod nd;
        for (j = 0; j < mp[A].size(); j++) {
            C = mp[A][j];
            if (C == B) continue;
            for (j1 = 0; j1 < mp[B].size(); j1++) {
                D = mp[B][j1];
                if (map_num[D+C] > 0 && D != A && D != B)
                {
                    nd.C = abs(stoi(C));
                    nd.D = abs(stoi(D));
                    res.push_back(nd);
                }
            }
        }
        sort(res.begin(), res.end(), compare);
        cout << res.size() << endl;
        for (j = 0; j < res.size(); j++) {
            printf("%04d %04d\n", res[j].C, res[j].D);
        }
        res.clear();
    }
    return 0;
}
