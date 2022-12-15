#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream file;
    file.open("./input.txt");
    string line, s, c;
    char cave[1000][1000];
    for(ll i=0; i<1000; i++){
        for(ll j=0; j<1000; j++){
            cave[i][j] = '.';
        }
    }
    ll index, curx, cury, newx, newy, maxy=0;
    while(getline(file, line)){
        istringstream strm(line);
        strm >> s;
        index = s.find(',');
        curx = stoll(s.substr(0, index));
        cury = stoll(s.substr(index+1, s.length()-(index+1)));
        maxy = max(maxy, cury);
        while(strm.good()){
            strm >> c >> s;
            index = s.find(',');
            newx = stoll(s.substr(0, index));
            newy = stoll(s.substr(index+1, s.length()-(index+1)));
            if(newy < cury){
                for(ll i=cury; i>=newy; i--) cave[i][curx] = '#';
            } else if(newy > cury){
                for(ll i=cury; i<=newy; i++) cave[i][curx] = '#';
            } else if(newx < curx){
                for(ll i=curx; i>=newx; i--) cave[cury][i] = '#';
            } else if(newx > curx){
                for(ll i=curx; i<=newx; i++) cave[cury][i] = '#';
            }
            curx = newx;
            cury = newy;
            maxy = max(maxy, cury);
        }
    }
    ll sand = 0;
    cury = 0;
    while(cury < maxy){
        curx = 500, cury = 0;
        while(cave[cury+1][curx-1] == '.' ||  cave[cury+1][curx] == '.' || cave[cury+1][curx+1] == '.'){
            if(cave[cury+1][curx] == '.') cury++;
            else if(cave[cury+1][curx-1] == '.'){
                curx--;
                cury++;
            } else if(cave[cury+1][curx+1] == '.'){
                curx++;
                cury++;
            }
            if(cury >= maxy) break;
        }
        cave[cury][curx] = 'o';
        sand++;
    }
    cout << sand-1 << "\n";
    file.close();

    return 0;
}
