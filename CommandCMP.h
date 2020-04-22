#ifndef _CCMP_
#define _CCMP_
#include"Commandbase.h"
#include "algori.h"
class CommandCMP:public CommandBase{
public:
    CommandCMP(Dir& tmp):CommandBase(tmp){}
    virtual int run(string st);
};
#endif