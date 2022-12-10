#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream file;
    file.open("./input.txt");
    string line, instruction;
    ll x=1, n;
    vector<ll> v;
    while(getline(file, line)){
        istringstream strm(line);
        strm >> instruction;
        if(instruction == "addx"){
            strm >> n;
            v.push_back(x);
            v.push_back(x);
            x += n;
        } else if(instruction == "noop"){
            v.push_back(x);
        }
    }
    for(ll i=0; i<6; i++){
        for(ll j=i*40; j<i*40+40; j++){
            if(j - i*40 >= v[j]-1 && j - i*40 <= v[j]+1) cout << "#";
            else cout << "."; 
        }
        cout << "\n";
    }
    file.close();

    return 0;
}
