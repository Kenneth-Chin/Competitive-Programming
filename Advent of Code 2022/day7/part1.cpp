#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Dir{
    public:
    string name;
    Dir* parentdir;
    vector<Dir*> subdir;
    vector<ll> files;
};

ll find_total_file_size(Dir* dir, ll total){
    for(ll x:dir->files){
        total += x;
    }
    for(Dir* x:dir->subdir){
        total += find_total_file_size(x, 0);
    }
    return total;
}

void find_sum_of_total_sizes(Dir* dir, ll &total){
    ll dirsize = find_total_file_size(dir, 0);
    if(dirsize <= 100000) total += dirsize;
    for(Dir* x:dir->subdir){
        find_sum_of_total_sizes(x, total);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream file;
    file.open("./input.txt");
    string line;
    string c1, c2, dir;
    Dir* outermostdir = new Dir();
    outermostdir->name = "/";
    Dir* currdir;
    ll total = 0;
    while(getline(file, line)){
        if(line[0] == '$'){
            istringstream strm(line);
            strm >> c1 >> c2;
            if(c2 == "cd"){
                strm >> dir;
                if(dir == ".."){
                    currdir = currdir->parentdir;
                } else if(dir == "/"){
                    currdir = outermostdir;
                } else{
                    for(Dir* x:currdir->subdir){
                        if(x->name == dir){
                            currdir = x;
                        }
                    }
                }
            }
        } else{
            istringstream strm(line);
            strm >> c1 >> c2;
            if(c1 == "dir"){
                Dir* newDir = new Dir();
                newDir->name = c2;
                newDir->parentdir = currdir;
                currdir->subdir.push_back(newDir);
            } else{
                currdir->files.push_back(stoll(c1));
            }
        }
    }
    find_sum_of_total_sizes(outermostdir, total);
    cout << total << "\n";
    file.close();
    
    return 0;
}
