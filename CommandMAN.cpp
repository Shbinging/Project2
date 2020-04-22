#include"CommandMAN.h"

int CommandMAN::run(string st){
    vector<string> a = st_split(st);
    if (a.size() != 2) return 2;
    string path = "help/" + a[1] + "Help.txt";
    dir.setOri();
    vector<string> b = dir.getfileContent(path); 
    dir.setHome();
    if (b.empty()) return 14;
    if (b[0] == "NULL") return 2;
    help(path);
    return 14;
}