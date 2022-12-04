#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream file;
    file.open("./input.txt");
    string line;
    ll total = 0, l1, l2, r1, r2;
    char c;
    while(getline(file, line)){
        istringstream strm(line);
        strm >> l1 >> c >> r1 >> c >> l2 >> c >> r2;
        if((l1 >= l2 && r1 <= r2) || (l2 >= l1 && r2 <= r1)) total++;
    }
    cout << total << "\n";
    file.close();

    
    return 0;
}
