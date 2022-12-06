#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector< stack<char> > v;
    char stack_arr[9][8] = {{'W', 'B', 'D', 'N', 'C', 'F', 'J', '-'}, 
                            {'P', 'Z', 'V', 'Q', 'L', 'S', 'T', '-'},
                            {'P', 'Z', 'B', 'G', 'J', 'T', '-', '-'},
                            {'D', 'T', 'L', 'J', 'Z', 'B', 'H', 'C'},
                            {'G', 'V', 'B', 'J', 'S', '-', '-', '-'},
                            {'P', 'S', 'Q', '-', '-', '-', '-', '-'},
                            {'B', 'V', 'D', 'F', 'L', 'M', 'P', 'N'},
                            {'P', 'S', 'M', 'F', 'B', 'D', 'L', 'R'},
                            {'V', 'D', 'T', 'R', '-', '-', '-', '-'}};
    for(ll i=0; i<9; i++){
        stack<char> s;
        for(ll j=0; j<8; j++){
            if(stack_arr[i][j] != '-') s.push(stack_arr[i][j]);
        }
        v.push_back(s);
    } 

    ifstream file;
    file.open("./input.txt");
    string line, c;
    ll quantity, source, destination;
    while(getline(file, line)){
        istringstream strm(line);
        strm >> c >> quantity >> c >> source >> c >> destination;
        source--;
        destination--;
        for(ll i=0; i<quantity; i++){
            char crate = v[source].top();
            v[destination].push(crate);
            v[source].pop();
        }
    }
    for(ll i=0; i<9; i++){
        cout << v[i].top();
    }
    cout << "\n";
    file.close();
    
    return 0;
}
