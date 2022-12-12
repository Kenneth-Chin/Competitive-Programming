#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream file;
    file.open("./input.txt");
    string line;
    vector<string> v;
    ll curline = 0, startx, starty, endx, endy;
    while(getline(file, line)){
        istringstream strm(line);
        for(ll i=0; i<line.length(); i++){
            if(line[i] == 'S'){
                startx = i;
                starty = curline;
                line[i] = 'a';
            } else if(line[i] == 'E'){
                endx = i;
                endy = curline;
                line[i] = 'z';
            }
        }
        v.push_back(line);
        curline++;
    }
    ll n = v.size(), m = v.front().length(), costs[n][m];
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            costs[i][j] = n*m + 1;
        }
    }
    costs[starty][startx] = 0;
    for(ll t=0; t<200; t++){
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                if(i-1 >= 0 && v[i-1][j]+1 >= v[i][j]){
                    costs[i][j] = min(costs[i][j], costs[i-1][j] + 1);
                }
                if(i+1 < n && v[i+1][j]+1 >= v[i][j]){
                    costs[i][j] = min(costs[i][j], costs[i+1][j] + 1);
                }
                if(j-1 >= 0 && v[i][j-1]+1 >= v[i][j]){
                    costs[i][j] = min(costs[i][j], costs[i][j-1] + 1);
                }
                if(j+1 < m && v[i][j+1]+1 >= v[i][j]){
                    costs[i][j] = min(costs[i][j], costs[i][j+1] + 1);
                }
            }
        }
    }
    cout << costs[endy][endx] << "\n";
    file.close();

    return 0;
}
