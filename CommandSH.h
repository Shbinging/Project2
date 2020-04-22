#ifndef _CSH
#define _CSH
#include "Commandbase.h"
#include "algori.h"
class CommandSH:public CommandBase{
public:
    CommandSH(Dir& tmp):CommandBase(tmp){}
    virtual int run(string st);
};
#endif