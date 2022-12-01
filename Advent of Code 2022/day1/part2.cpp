#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream file;
    file.open("./input.txt");
    string line;
    ll total = 0, ans = 0;
    vector<ll> v;
    while(getline(file, line)){
        if(!line.empty()){
            total += stoll(line);
        } else{
            v.push_back(total);
            total = 0;
        }
    }
    v.push_back(total);
    sort(v.rbegin(), v.rend());
    cout << v[0] + v[1] + v[2] << "\n";
    file.close();
    return 0;
}
