#ifndef _CCD
#define _CCD
#include "Commandbase.h"
#include "algori.h"
class CommandCD:public CommandBase{
public:
    virtual int run(string st);
};
#endif