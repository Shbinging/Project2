#ifndef _CBase_
#define _CBase_
#include "diag.h"
#include"DirHelper.h"

class CommandBase{
    public:
    virtual int run(string){}
    void help(string);
};

#endif