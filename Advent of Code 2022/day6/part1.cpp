#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream file;
    file.open("./input.txt");
    string line;
    ll ans;
    while(getline(file, line)){
        for(ll i=0; i<line.length()-3; i++){
            set<char> s;
            for(ll j=i; j<i+4; j++) s.insert(line[j]);
            if(s.size() == 4){
                ans = i+4;
                break;
            }
        }
    }
    cout << ans << "\n";
    file.close();

    
    return 0;
}
