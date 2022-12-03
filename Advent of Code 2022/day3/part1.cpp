#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream file;
    file.open("./input.txt");
    string line, c1, c2;
    ll total = 0, priority[53];
    bool calculated[53];
    while(getline(file, line)){
        ll halflen = line.length() / 2;
        c1 = line.substr(0, halflen);
        c2 = line.substr(halflen, halflen);
        for(ll i=0; i<53; i++){
            priority[i] = 0;
            calculated[i] = false;
        }
        for(ll i=0; i<halflen; i++){
            if(islower(c1[i])) priority[c1[i] - 'a' + 1]++;
            else priority[26 + c1[i] - 'A' + 1]++;
        }
        for(ll i=0; i<halflen; i++){
            ll index;
            if(islower(c2[i])) index = c2[i] - 'a' + 1;
            else index = 26 + c2[i] - 'A' + 1;
            if(priority[index] > 0 && !calculated[index]){
                total += index;
                calculated[index] = true;
            }
        }
    }
    cout << total << "\n";
    file.close();
    return 0;
}
