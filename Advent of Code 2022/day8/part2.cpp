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
    ll max_score = 0, n, m;
    while(getline(file, line)){
        trees.push_back(line);
    }
    n = trees.size();
    m = trees.front().length();
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            ll left=0, right=0, top=0, bottom=0;
            for(ll x=j-1; x>=0; x--){
                left++;
                if(trees[i][x] >= trees[i][j]) break;
            }
            for(ll x=j+1; x<m; x++){
                right++;
                if(trees[i][x] >= trees[i][j]) break;
            }
            for(ll x=i-1; x>=0; x--){
                top++;
                if(trees[x][j] >= trees[i][j]) break;
            }
            for(ll x=i+1; x<n; x++){
                bottom++;
                if(trees[x][j] >= trees[i][j]) break;
            }
            max_score = max(max_score, left*right*top*bottom);
        }
    }
    cout << max_score << "\n";
    file.close();

    return 0;
}
