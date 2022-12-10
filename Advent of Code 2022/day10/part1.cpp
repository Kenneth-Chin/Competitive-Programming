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
    ll total = 0, cur = 20;
    for(ll i=0; i<6; i++){
        total += cur * v[cur-1];
        cur += 40;
    }
    cout << total << "\n";
    file.close();

    return 0;
}
