#include"CommandCD.h"

int CommandCD::run(string st){
    vector<string> a = st_split(st);
    if (a.size() != 2) return 2;
    string path = a[1];
    if (!dir.ispathExsist(a[1])) return 10;
    if (dir.isFile(a[1])) return 15;
    if (!dir.setpath1(path)) return 18;
    return 14;
}