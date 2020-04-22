#ifndef _UI
#define _UI
#include"diag.h"
#include"DirHelper.h"

class UI{
    public:
        UI(string path):dir(path){
            setwrongCode(dir.oriPath);
        }
        int running(string st);
        void run();
        vector<string> wrongCode;
        void setwrongCode(string);
        Dir dir;
};
#endif