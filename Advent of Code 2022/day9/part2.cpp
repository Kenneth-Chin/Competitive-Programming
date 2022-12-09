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
    ll steps;
    vector< pair<ll, ll> > v;
    for(ll i=0; i<10; i++) v.push_back(make_pair(0, 0));
    set< pair<ll, ll> > s;
    while(getline(file, line)){
        istringstream strm(line);
        strm >> direction >> steps;
        for(ll i=0; i<steps; i++){
            for(ll j=0; j<10; j++){
                if(j == 0){
                    if(direction == 'L') v[j].first--;
                    else if(direction == 'R') v[j].first++;
                    else if(direction == 'U') v[j].second--;
                    else if(direction == 'D') v[j].second++;
                } else{
                    ll hx = v[j-1].first, tx = v[j].first, hy = v[j-1].second, ty = v[j].second;
                    if(hx < tx){
                        if(!(abs(hx-tx) <= 1 && abs(hy-ty) <= 1)){
                            tx--;
                            if(ty > hy) ty--;
                            else if(ty < hy) ty++;
                        }
                    } else if(hx > tx){
                        if(!(abs(hx-tx) <= 1 && abs(hy-ty) <= 1)){
                            tx++;
                            if(ty > hy) ty--;
                            else if(ty < hy) ty++;
                        }
                    } else if(hy < ty){
                        if(!(abs(hx-tx) <= 1 && abs(hy-ty) <= 1)){
                            ty--;
                            if(tx > hx) tx--;
                            else if(tx < hx) tx++;
                        }
                    } else if(hy > ty){
                        if(!(abs(hx-tx) <= 1 && abs(hy-ty) <= 1)){
                            ty++;
                            if(tx > hx) tx--;
                            else if(tx < hx) tx++;
                        }
                    }
                    v[j].first = tx;
                    v[j].second = ty;
                }
            }
            s.insert(make_pair(v.back().first, v.back().second));
        }
    }
    cout << s.size() << "\n";
    file.close();

    return 0;
}
