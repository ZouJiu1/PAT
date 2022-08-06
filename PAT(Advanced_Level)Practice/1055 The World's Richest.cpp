/*由于每个询问的个数不多于100个，所以给到每个年龄对应的个数应该小于10个左右 */
#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;

typedef struct {
    string nam;
    int age;
    int mon;
}worthy;

bool compare(const worthy& a, const worthy& c){
    if(a.age==c.age and a.mon==c.mon){
        if(a.nam < c.nam) return true;
        else return false;
    }else if(a.mon==c.mon){
        if(a.age < c.age) return true;
        else return false;
    }else{
        if(a.mon > c.mon) return true;
        else return false;
    }
}

int main(void){
    int i, j, k, m, n, h, mm, nn, age, mar, cnt;
    int x, y;
    cin>>m>>n;
    vector<worthy> v[201], v0;
    worthy wy;
    for(i = 0; i < m; i++){
        cin>>wy.nam>>wy.age>>wy.mon;
        v[wy.age].push_back(wy);
    }
    for(i = 0; i < 201; i++){
        if(v[i].size() > 10){
            sort(v[i].begin(), v[i].end(), compare);
            v[i].erase(v[i].begin()+10, v[i].end());
        }
    }
    for(i = 0; i < n; i++){
        cin>>h>>mm>>nn;
        cout<<"Case #"<<i+1<<":"<<endl;
        mar = 999;
        cnt = 0;
        vector<worthy> v0;
        for(j = mm; j <=nn; j++){
            for(x = 0; x < v[j].size(); x++)
                v0.push_back(v[j][x]);
        }
        if(v0.size() == 0){
            cout<<"None"<<endl;
            continue;
        }
        sort(v0.begin(), v0.end(), compare);
        cnt = min(h, (int)(v0.size()));
        for(j = 0; j < cnt; j++){
            cout<<v0[j].nam<<" "<<v0[j].age<<" "<<v0[j].mon<<endl;
        }
    }
    return 0;
}

// #include<iostream>
// #include<vector>
// #include<string>
// #include<map>
// #include<bits/stdc++.h>

// using namespace std;

// typedef struct {
//     string nam;
//     int age;
//     int mon;
// }worthy;

// bool compare(const worthy& a, const worthy& c){
//     if(a.age==c.age and a.mon==c.mon){
//         if(a.nam < c.nam) return true;
//         else return false;
//     }else if(a.mon==c.mon){
//         if(a.age < c.age) return true;
//         else return false;
//     }else{
//         if(a.mon > c.mon) return true;
//         else return false;
//     }
// }

// int main(void){
//     int i, j, k, m, n, h, mm, nn, age, mar, cnt;
//     cin>>m>>n;
//     vector<worthy> v, v0;
//     worthy wy;
//     map<int, int> agerank;
//     for(i = 0; i < m; i++){
//         cin>>wy.nam>>wy.age>>wy.mon;
//         v.push_back(wy);
//     }
//     sort(v.begin(), v.end(), compare);
//     for(i = 0; i < m; i++){
//         age = v[i].age;
//         if(agerank[age]<=10){
//             v0.push_back(v[i]);
//             agerank[age] += 1;
//         }
//     }
//     v = v0;
//     for(i = 0; i < n; i++){
//         cin>>h>>mm>>nn;
//         cout<<"Case #"<<i+1<<":"<<endl;
//         mar = 999;
//         cnt = 0;
//         for(j = 0; j < m; j++){
//             age = v[j].age;
//             if(age >= mm && age <= nn){
//                 cnt++;
//                 if(cnt>h) break;
//                 cout<<v[j].nam<<" "<<v[j].age<<" "<<v[j].mon<<endl;
//                 mar = -999;
//             }
//         }
//         if(mar>0){
//             cout<<"None"<<endl;
//         }
//     }
//     return 0;
// }
