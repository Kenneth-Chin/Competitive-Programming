#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream file;
    file.open("./input.txt");
    string line;
    char opponent, response;
    ll total = 0, score;
    while(getline(file, line)){
        istringstream strm(line);
        strm >> opponent;
        strm >> response;
        score = 0;
        if(response == 'X'){
            score++;
            if(opponent == 'A') score += 3;
            else if(opponent == 'C') score += 6;
        } else if(response == 'Y'){
            score += 2;
            if(opponent == 'A') score += 6;
            else if(opponent == 'B') score += 3;
        } else if(response == 'Z'){
            score += 3;
            if(opponent == 'B') score += 6;
            else if(opponent == 'C') score += 3;
        }
        total += score;
    }
    cout << total << "\n";
    file.close();
    return 0;
}
