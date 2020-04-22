#ifndef _CWC
#define _CWC
#include "Commandbase.h"
#include "algori.h"
class CommandWC:public CommandBase{
public:
    CommandWC(Dir& tmp):CommandBase(tmp){}
    virtual int run(string st);
    vector<int> calc(fileNode tmp, string path);
};
#endif