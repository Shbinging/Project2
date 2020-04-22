#ifndef _CCAT
#define _CCAT
#include "Commandbase.h"
#include "algori.h"
class CommandCAT:public CommandBase{
public:
    CommandCAT(Dir& tmp):CommandBase(tmp){}
    virtual int run(string st);
};
#endif