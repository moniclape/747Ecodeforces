#include <bits/stdc++.h>
using namespace std;
void gg(int lvl, int cnt, vector <string>& t, int& pos, vector <vector<string>>& levels){
    for (int i = 0; i < cnt && pos < t.size(); i++){
        string comment = t[pos++];
        int cc = stoi(t[pos++]);
        if (levels.size() <= lvl){
            levels.resize(lvl + 1);
        }
        levels[lvl].push_back(comment);
        gg(lvl + 1, cc, t, pos, levels);
    }
}

int main(){
    string s;
    getline(cin, s);
    vector <string> t;
    string ct;
    for (char c : s){
        if (c == ','){
            t.push_back(ct);
            ct.clear();
        }else{
            ct += c;
        }
    }
    if (!ct.empty()){
        t.push_back(ct);
    }
    int pos = 0;
    vector <vector<string>> levels;
    gg(0, 1e9, t, pos, levels);
    cout << levels.size() << endl;
    for (const auto& lvl : levels){
        for (const string& comment : lvl){
            cout << comment << " ";
        }cout << endl;
    }
    return 0;
}
