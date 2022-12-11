#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll starting_items[8][8] = {{66, 79, 0, 0, 0, 0, 0, 0},
                               {84, 94, 94, 81, 98, 75, 0, 0},
                               {85, 79, 59, 64, 79, 95, 67 ,0},
                               {70, 0, 0, 0, 0, 0, 0, 0},
                               {57, 69, 78, 78, 0, 0, 0, 0},
                               {65, 92, 60, 74, 72, 0, 0, 0},
                               {77, 91, 91, 0, 0, 0, 0, 0},
                               {76, 58, 57, 55, 67, 77, 54, 99}};
    ll operations[8][2] = {{1, 11},
                           {1, 17},
                           {0, 8},
                           {0, 3},
                           {0, 4},
                           {0, 7},
                           {2, 0},
                           {0, 6}};
    ll tests[8][3] = {{7, 6, 7},
                      {13, 5, 2},
                      {5, 4, 5},
                      {19, 6, 0},
                      {2, 0, 3},
                      {11, 3, 4},
                      {17, 1, 7},
                      {3, 2, 1}};
    vector< vector<ll> > items;
    for(ll i=0; i<8; i++){
        vector<ll> q;
        for(ll j=0; j<8; j++){
            if(starting_items[i][j] != 0) q.push_back(starting_items[i][j]);
            else break;
        }
        items.push_back(q);
    }
    ll inspections[8] = { 0 };
    for(ll i=0; i<20; i++){
        for(ll j=0; j<8; j++){
            ll n = items[j].size();
            for(ll k=0; k<n; k++){
                ll x = items[j].front();
                items[j].erase(items[j].begin());
                if(operations[j][0] == 0){
                    x += operations[j][1];
                } else if(operations[j][0] == 1){
                    x *= operations[j][1];
                } else if(operations[j][0] == 2){
                    x *= x;
                }
                x /= 3;
                if(x % tests[j][0] == 0) items[tests[j][1]].push_back(x);
                else items[tests[j][2]].push_back(x);
                inspections[j]++;
            }
        }
    }
    sort(inspections, inspections+8);
    cout << inspections[7] * inspections[6] << "\n";
    return 0;
}
