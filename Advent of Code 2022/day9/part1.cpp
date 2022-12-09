#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream file;
    file.open("./input.txt");
    string line;
    char direction;
    ll steps, hx=0, hy=0, tx=0, ty=0;
    set< pair<ll, ll> > s;
    while(getline(file, line)){
        istringstream strm(line);
        strm >> direction >> steps;
        for(ll i=0; i<steps; i++){
            if(direction == 'L'){
                hx--;
                if(!(abs(hx-tx) <= 1 && abs(hy-ty) <= 1)){
                    tx--;
                    if(ty > hy) ty--;
                    else if(ty < hy) ty++;
                }
            } else if(direction == 'R'){
                hx++;
                if(!(abs(hx-tx) <= 1 && abs(hy-ty) <= 1)){
                    tx++;
                    if(ty > hy) ty--;
                    else if(ty < hy) ty++;
                }
            } else if(direction == 'U'){
                hy--;
                if(!(abs(hx-tx) <= 1 && abs(hy-ty) <= 1)){
                    ty--;
                    if(tx > hx) tx--;
                    else if(tx < hx) tx++;
                }
            } else if(direction == 'D'){
                hy++;
                if(!(abs(hx-tx) <= 1 && abs(hy-ty) <= 1)){
                    ty++;
                    if(tx > hx) tx--;
                    else if(tx < hx) tx++;
                }
            }
            s.insert(make_pair(tx, ty));
        }
    }
    cout << s.size() << "\n";
    file.close();

    
    return 0;
}
