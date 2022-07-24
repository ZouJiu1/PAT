#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<bits/stdc++.h>

using namespace std;

vector<int> v, v0;
int m, n, mid, tempsum;

int _binary_search_(int i){
    int left = i;
    int right = m;
    while(left < right){
        mid = (left + right)/2;
        if((v[mid] - v[i - 1]) >= n) right = mid;
        else left = mid + 1;
    }
    mid = right;
    tempsum = v[right] - v[i - 1];
    return tempsum;
}

int main(void){
    int i, j, k, h, sum, minsum;
    cin>>m>>n;
    v.resize(m + 1);
    v[0] = 0;
    for(i = 1; i <= m; i++){
        cin>>k;
        v[i] = (k + v[i - 1]);
    }
    minsum = v[m];
    for(i = 1; i <= m; i++){
        tempsum = _binary_search_(i);
        if(tempsum > minsum) continue;
        if(tempsum >= n){
            if(tempsum < minsum){
                v0.clear();
                minsum = tempsum;
            }
            v0.push_back(i);
            v0.push_back(mid);
        }
    }
    for(i = 0; i < v0.size()/2; i++){
        printf("%d-%d\n", v0[i * 2], v0[i * 2 + 1]);
    }
    return 0;
}

/*
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<bits/stdc++.h>

using namespace std;

typedef struct _record{
    int start;
    int end;
}record;

bool compare(const record& a, const record& b){
    if(a.start < b.start) return true;
    else return false;
}

int main(void){
    int i, j, k, m, n, h, mm, nn, sum, minsum=99999999;
    int start, end;
    cin>>m>>n;
    string s, s0, s00;
    vector<int> v, v0, v00;
    for(i = 0; i < m; i++){
        cin>>k;
        v.push_back(k);
    }
    record rec;
    vector<record> vec, par;
    int mar = 999;
    for(i = 0; i < m; i++){
        sum = v[i];
        if(sum > n && sum > minsum && mar > 0) continue;
        if(sum > n && mar < 0) continue;
        if(sum > n && sum <= minsum && mar > 0){
            rec.start = i + 1;
            rec.end   = i + 1;
            if(par.size()>0 && sum!=minsum)
                par.erase(par.begin(), par.begin()+1);
            par.push_back(rec);
            minsum = sum;
        }
        if(sum==n){
            rec.start = i + 1;
            rec.end   = i + 1;
            vec.push_back(rec);
            mar = -999;
            continue;
        }
        for(j = i + 1; j < m; j++){
            sum += v[j];
            if(sum > n && sum > minsum && mar > 0) break;
            if(sum > n && mar < 0) break;
            if(sum > n && sum <= minsum && mar > 0){
                rec.start = i + 1;
                rec.end   = j + 1;
                if(par.size()>0 && sum!=minsum) 
                    par.erase(par.begin(), par.begin()+1);
                par.push_back(rec);
                minsum = sum;
            }
            if(sum==n){
                rec.start = i + 1;
                rec.end   = j + 1;
                vec.push_back(rec);
                mar = -999;
                break;
            }
        }
    }
    if(mar > 0){ 
        vec = par;
    }
    sort(vec.begin(), vec.end(), compare);
    for(i = 0; i < vec.size(); i++){
        printf("%d-%d\n", vec[i].start, vec[i].end);
    }
    return 0;
}
*/
