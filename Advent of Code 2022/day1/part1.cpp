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
    while(getline(file, line)){
        if(!line.empty()){
            total += stoll(line);
        } else{
            ans = max(ans, total);
            total = 0;
        }
    }
    ans = max(ans, total);
    cout << ans << "\n";
    file.close();
    return 0;
}
