#ifndef _CLS
#define _CLS
#include "Commandbase.h"
#include "algori.h"
class CommandLS:public CommandBase{
public:
    CommandLS(Dir& tmp):CommandBase(tmp){}
    virtual int run(string st);
    
};
#endif