#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream file;
    file.open("./input.txt");
    string line;
    ll total = 0, cnt = 0, priority[53];
    bool calculated[53];
    for(ll i=0; i<53; i++) priority[i] = 0;
    while(getline(file, line)){
        for(ll i=0; i<53; i++) calculated[i] = false;
        for(ll i=0; i<line.length(); i++){
            ll index;
            if(islower(line[i])) index = line[i] - 'a' + 1;
            else index = 26 + line[i] - 'A' + 1;
            if(!calculated[index]){
                priority[index]++;
                calculated[index] = true;
            }
        }
        cnt++;
        if(cnt == 3){
            for(ll i=0; i<53; i++){
                if(priority[i] == 3) total += i;
                priority[i] = 0;
            }
            cnt = 0;
        }
    }
    cout << total << "\n";
    file.close();
    return 0;
}
