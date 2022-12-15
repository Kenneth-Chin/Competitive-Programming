#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream file;
    file.open("./input.txt");
    string line, c, s1, s2, s3, s4;
    vector< pair<ll, ll> > sensor, beacon;
    while(getline(file, line)){
        istringstream strm(line);
        strm >> c >> c >> s1 >> s2 >> c >> c >> c >> c >> s3 >> s4;
        sensor.push_back(make_pair(stoll(s1.substr(2, s1.length()-3)), stoll(s2.substr(2, s2.length()-3))));
        beacon.push_back(make_pair(stoll(s3.substr(2, s3.length()-3)), stoll(s4.substr(2, s4.length()-2))));
    }
    vector< pair<ll, char> > impossible;
    ll row = 2000000, distance, remaining_x_distance;
    for(ll i=0; i<sensor.size(); i++){
        distance = abs(sensor[i].first - beacon[i].first) + abs(sensor[i].second - beacon[i].second);
        remaining_x_distance = distance - abs(sensor[i].second - row);
        if(remaining_x_distance >= 0){
            impossible.push_back(make_pair(sensor[i].first - remaining_x_distance, 'a'));
            impossible.push_back(make_pair(sensor[i].first + remaining_x_distance, 'b'));
        }
    }
    sort(impossible.begin(), impossible.end());
    ll ans = 0, left = impossible[0].first, cur = 0;
    for(ll i=0; i<impossible.size(); i++){
        if(impossible[i].second == 'a') cur++;
        else if(impossible[i].second == 'b') cur--;
        if(cur == 0) ans += impossible[i].first - left + 1;
    }
    cout << ans - 1 << "\n";
    file.close();

    return 0;
}
