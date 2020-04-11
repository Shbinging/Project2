#ifndef _CWC
#define _CWC
#include "Commandbase.h"
#include "algori.h"
class CommandWC:public CommandBase{
public:
    int run(string st);
    string help();
    vector<int> calc(fileNode tmp);
};
#endif