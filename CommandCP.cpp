#include "CommandCP.h"

int CommandCP::run(string st){
    vector<string> a = st_split(st);
    if (a.size() < 3 || a.size() > 4) return 2;
    if (a.size() == 3){
        if (!dir.ispathExsist(a[1])) return 10;
        if (!dir.isFile(a[1])) return 11;
        if (!dir.ispathExsist(a[2]) && !dir.makeDir(a[2])) return 12;
        if (dir.ispathExsist(a[2]) && dir.isFile(a[2])) return 12;
        vector<fileNode> b;
        fileNode c = dir.getfile(a[1]);
        b.push_back(c);
        if (!dir.makeFileTree(b, a[2])) return 13;
        return 14;
    }
    else{
        if (a[1] != "-r") return 17;
        if (!dir.ispathExsist (a[2])) return 10;
        if (dir.isFile(a[2])) return 15;
        if (!dir.ispathExsist(a[3]) && !dir.makeDir(a[3])) return 12;
        vector<fileNode>& b = dir.getfileTree(a[2]);
        if (!dir.makeFileTree(b, a[3])) return 13;
        dir.closeFileTree();
        return 14;
    }
}

