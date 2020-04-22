#include"CommandCAT.h"
int CommandCAT::run(string st){
    vector<string> a = st_split(st);
    if (a.size() != 2) return 2;
    string path = a[1];
    if (!dir.ispathExsist(path)) return 10;
    vector<string>& b = dir.getfileContent(path);
    if (b[0] == "NULL") return 16;
    else{
        For(i, 0, int(b.size()) - 1){
            cout << b[i];
        }
        return 14;
    }
}
