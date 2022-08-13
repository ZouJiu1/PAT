#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

struct nod{
    int l;
    int r;
    nod *nexted;
};
vector<int> v0;
void findroot(vector<int> v, int n, int cnt){
    vector<vector<int>> v00;
    int maxval;
    v00.push_back(v);
    while(v00.size()!=0){
        v = v00[0];
        n = v.size();
        v00.erase(v00.begin());
        if(n==2) {
            maxval = max(v[0], v[1]);
            v0.push_back(maxval);
            vector<int> ll;
            ll.push_back(min(v[0], v[1]));
            v00.push_back(ll);
            continue;
        }
        int layerceil, layerfloor;
        if(log2((float)n+1.0) - (int)log2((float)n+1.0)!=0.0){
            layerceil  = ceil(log2((float)n+1.0));
            layerfloor = floor(log2((float)n+1.0));
        }
        else{
            layerceil  = log2((float)n+1.0);
            layerfloor = log2((float)n+1.0);
        }
        int numceil = (int)pow(2, layerceil) - 1;
        int numfloor = (int)pow(2, layerfloor) - 1;
        int lastl = (int)pow(2, layerceil - 1);
        int ind;
        if(layerceil!=layerfloor){
            if(n - numfloor > lastl/2){
                ind = (numfloor-1)/2 + lastl/2;
            }else{
                ind = (numfloor-1)/2 + n - numfloor;
            }
        }else{
            ind = (numfloor-1)/2;
        }
        vector<int> l, r;
        l = v; 
        r = v;
        l.erase(l.begin() + ind, l.end());
        r.erase(r.begin(), r.begin() + ind + 1);
        v0.push_back(v[ind]);
        if(l.size()!=0)
            v00.push_back(l);
        if(r.size()!=0)
            v00.push_back(r);
    }
    for(int i = 0; i< v0.size(); i++){
        printf("%d", v0[i]);
        if(i!=v0.size() - 1) cout<<" ";
    }
}

int main(void){
    int i, j, m, n, x, y, k, w;
    cin>>n;
    vector<int> v;
    for(i = 0; i < n; i++){
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    findroot(v, n, 0);
    return 0;
}
