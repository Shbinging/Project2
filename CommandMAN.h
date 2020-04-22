#ifndef _CMAN
#define _CMAN
#include "Commandbase.h"
#include "algori.h"
class CommandMAN:public CommandBase{
public:
    CommandMAN(Dir& tmp):CommandBase(tmp){}
    virtual int run(string st);
    
};
#endif