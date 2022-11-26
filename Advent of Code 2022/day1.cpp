#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        for(ll i=n; i>=1; i--){
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}