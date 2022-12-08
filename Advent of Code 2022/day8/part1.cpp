#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream file;
    file.open("./input.txt");
    string line;
    vector<string> trees;
    ll total = 0, n, m;
    while(getline(file, line)){
        trees.push_back(line);
    }
    n = trees.size();
    m = trees.front().length();
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            if(i == 0 || j == 0 || i == n-1 || j == m-1) total++;
            else{
                bool left=true, right=true, top=true, bottom=true;
                for(ll x=j-1; x>=0; x--){
                    if(trees[i][x] >= trees[i][j]){
                        left = false;
                        break;
                    }
                }
                for(ll x=j+1; x<m; x++){
                    if(trees[i][x] >= trees[i][j]){
                        right = false;
                        break;
                    }
                }
                for(ll x=i-1; x>=0; x--){
                    if(trees[x][j] >= trees[i][j]){
                        top = false;
                        break;
                    }
                }
                for(ll x=i+1; x<n; x++){
                    if(trees[x][j] >= trees[i][j]){
                        bottom = false;
                        break;
                    }
                }
                if(left || right || top || bottom) total++;
            }
        }
    }
    cout << total << "\n";
    file.close();

    return 0;
}
