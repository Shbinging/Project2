#ifndef _CCMP_
#define _CCMP_
#include "Commandbase.h"
#include "algori.h"
class CommandCMP:public CommandBase{
public:
    int run(string st);
    string help();
};
#endif