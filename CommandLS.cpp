#include"CommandLS.h"

int CommandLS::run(string st){
    vector<string> a = st_split(st);
    if (a.size() != 1) return 2;
    string path = dir.getPath();
    vector<fileNode>& b = dir.getfileTree(path, 1);
    For(i, 0, int(b.size()) - 1){
        cout << b[i].name << " ";
    }
    cout << endl;
    return 14;
}