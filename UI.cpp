#include "UI.h"
#include "algori.h"
#include"CommandCAT.h"
#include"CommandCD.h"
#include"CommandCMP.h"
#include"CommandCP.h"
#include"CommandLS.h"
#include"CommandMAN.h"
#include"CommandWC.h"
#include"Commandbase.h"
#include"CommandSH.h"

int UI::running(string st){
    dir.setHome();
    vector<string> a = st_split(st);
    if (a.size() == 2 && a[1] == "--help"){
        dir.setOri();
        string path = "help/" + a[0] + "Help.txt";
        if (!dir.ispathExsist(path)){dir.setHome(); return 1;}
        CommandBase c(dir);
        c.help(path);
        dir.setHome();
        return 14;
    }
    CommandBase * f = NULL;
    if (a[0] == "cat") f = new CommandCAT(dir);
    if (a[0] == "cd") f = new CommandCD(dir);
    if (a[0] == "cmp") f= new CommandCMP(dir);
    if (a[0] == "cp") f = new CommandCP(dir);
    if (a[0] == "ls") f = new CommandLS(dir);
    if (a[0] == "man") f= new CommandMAN(dir);
    if (a[0] == "wc") f = new CommandWC(dir);
    if (a[0] == "sh") f= new CommandSH(dir);
    if (f == NULL) return 1;
    else return f->run(st);
}

void UI::setwrongCode(string path){
    wrongCode = dir.getfileContent(path + "/wrongCode.txt");
    For(i, 0, int(wrongCode.size()) - 1){
        vector<string> c= st_split(wrongCode[i],':');
        if (c.size() > 1)
            wrongCode[i] = c[1];
        else wrongCode[i] = "";
    }
}


void UI::run(){
    while (1){
        string path = dir.getPath();
        cout << path << "$ ";
        string st;
        getline(cin, st);
        if (st == "exit") return;
        int rt = running(st);
        if (rt != 14) cout << wrongCode[rt] <<endl;
        dir.setHome();
    }
}