#ifndef _CCD
#define _CCD
#include "Commandbase.h"
#include "algori.h"
class CommandCD:public CommandBase{
public:
    CommandCD(Dir& tmp):CommandBase(tmp){}
    virtual int run(string st);
};
#endif