#include "UI.h"
#include "algori.h"
int UI::running(string st){
    vector<string> a = st_split(st);
    if (a.size() == 2 && a[1] == "--help"){
        dir.setOri();
        string path = "help/" + a[0] + "Help.txt";
        if (!dir.ispathExsist(path)){dir.setHome(); return 1;}
        CommandBase c;
        c.help(path);
        dir.setHome();
        return 14;
    }
    CommandBase * f = NULL;
    if (a[0] == "cat") f = new CommandCAT;
    if (a[0] == "cd") f = new CommandCD;
    if (a[0] == "cmp") f= new CommandCMP;
    if (a[0] == "cp") f = new CommandCP;
    if (a[0] == "ls") f = new CommandLS;
    if (a[0] == "man") f= new CommandMAN;
    if (a[0] == "wc") f = new CommandWC;
    if (f == NULL) return 1;
    else return f->run(st);
}

void UI::run(){
    string path = dir.getPath();
    vector<string> wrongCode = dir.getfileContent("wrongCode.txt");
    For(i, 0, int(wrongCode.size()) - 1){
        vector<string> c= st_split(wrongCode[i],':');
        if (c.size() > 1)
            wrongCode[i] = c[1];
        else wrongCode[i] = "";
    }
    while (1){
        path = dir.getPath();
        cout << path << "$ ";
        string st;
        getline(cin, st);
        if (st == "exit") return;
        int rt = running(st);
        cout << wrongCode[rt] <<endl;
        dir.setHome();
    }
}