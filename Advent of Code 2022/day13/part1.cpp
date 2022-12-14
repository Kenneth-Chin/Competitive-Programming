#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int compare_inner_list(string left, string right){
    string left_cur_value = "", right_cur_value = "";
    ll brackets = 0;

    if(left == "[]" && right == "[]") return 2;
    else if(left == "[]" && right != "[]") return 1;
    else if(left != "[]" && right == "[]") return 0;
    
    for(ll i=1; i<left.length()-1; i++){
        if(left[i] == ',' && brackets == 0) break;
        else if(left[i] == '[') brackets++;
        else if(left[i] == ']') brackets--;
        left_cur_value += left[i];
    }
    for(ll i=1; i<right.length()-1; i++){
        if(right[i] == ',' && brackets == 0) break;
        else if(right[i] == '[') brackets++;
        else if(right[i] == ']') brackets--;
        right_cur_value += right[i];
    }

    string left_remaining = "", right_remaining = "";
    if(left_cur_value.length()+2 < left.length()) left_remaining += left.substr(left_cur_value.length()+2, left.length() - (left_cur_value.length()+3));
    if(right_cur_value.length()+2 < right.length()) right_remaining += right.substr(right_cur_value.length()+2, right.length() - (right_cur_value.length()+3));

    if(isdigit(left_cur_value[0]) && isdigit(right_cur_value[0])){
        if(stoll(left_cur_value) < stoll(right_cur_value)) return 1;
        else if(stoll(left_cur_value) > stoll(right_cur_value)) return 0;
        else return compare_inner_list("[" + left_remaining + "]", "[" + right_remaining + "]");
    } else if(left_cur_value[0] == '[' && right_cur_value[0] == '['){
        int x = compare_inner_list(left_cur_value, right_cur_value);
        if(x == 2) return compare_inner_list("[" + left_remaining + "]", "[" + right_remaining + "]");
        else return x;
    } else{
        if(isdigit(left_cur_value[0])){
            int x = compare_inner_list("[" + left_cur_value + "]", right_cur_value);
            if(x == 2) return compare_inner_list("[" + left_remaining + "]", "[" + right_remaining + "]");
            else return x;
        } else if(isdigit(right_cur_value[0])){
            int x = compare_inner_list(left_cur_value, "[" + right_cur_value + "]");
            if(x == 2) return compare_inner_list("[" + left_remaining + "]", "[" + right_remaining + "]");
            else return x;
        }
    }
}

bool compare_list(string left, string right){
    string left_cur_value = "", right_cur_value = "";
    ll brackets = 0;

    if(left == "[]" && right == "[]") return true;
    else if(left == "[]" && right != "[]") return true;
    else if(left != "[]" && right == "[]") return false;
    
    for(ll i=1; i<left.length()-1; i++){
        if(left[i] == ',' && brackets == 0) break;
        else if(left[i] == '[') brackets++;
        else if(left[i] == ']') brackets--;
        left_cur_value += left[i];
    }
    for(ll i=1; i<right.length()-1; i++){
        if(right[i] == ',' && brackets == 0) break;
        else if(right[i] == '[') brackets++;
        else if(right[i] == ']') brackets--;
        right_cur_value += right[i];
    }

    string left_remaining = "", right_remaining = "";
    if(left_cur_value.length()+2 < left.length()) left_remaining += left.substr(left_cur_value.length()+2, left.length() - (left_cur_value.length()+3));
    if(right_cur_value.length()+2 < right.length()) right_remaining += right.substr(right_cur_value.length()+2, right.length() - (right_cur_value.length()+3));

    if(isdigit(left_cur_value[0]) && isdigit(right_cur_value[0])){
        if(stoll(left_cur_value) < stoll(right_cur_value)) return true;
        else if(stoll(left_cur_value) > stoll(right_cur_value)) return false;
        else return compare_list("[" + left_remaining + "]", "[" + right_remaining + "]");
    } else if(left_cur_value[0] == '[' && right_cur_value[0] == '['){
        int x = compare_inner_list(left_cur_value, right_cur_value);
        if(x == 0) return false;
        else if(x == 1) return true;
        else if(x == 2) return compare_list("[" + left_remaining + "]", "[" + right_remaining + "]");
    } else{
        if(isdigit(left_cur_value[0])){
            int x = compare_inner_list("[" + left_cur_value + "]", right_cur_value);
            if(x == 0) return false;
            else if(x == 1) return true;
            else if(x == 2) return compare_list("[" + left_remaining + "]", "[" + right_remaining + "]");
        } else if(isdigit(right_cur_value[0])){
            int x = compare_inner_list(left_cur_value, "[" + right_cur_value + "]");
            if(x == 0) return false;
            else if(x == 1) return true;
            else if(x == 2) return compare_list("[" + left_remaining + "]", "[" + right_remaining + "]");
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream file;
    file.open("./input.txt");
    string line;
    ll total=0;
    vector< pair<string, string> > v;
    while(getline(file, line)){
        if(!line.empty()){
            if(v.empty() || v.back().second != "") v.push_back(make_pair(line, ""));
            else v.back().second = line;
        }
    }
    for(ll i=0; i<v.size(); i++){
        if(compare_list(v[i].first, v[i].second)) total += i + 1;
    }
    cout << total << "\n";
    file.close();

    
    return 0;
}
