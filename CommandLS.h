#ifndef _CLS
#define _CLS
#include "Commandbase.h"
#include "algori.h"
class CommandLS:public CommandBase{
public:
    virtual int run(string st);
    
};
#endif