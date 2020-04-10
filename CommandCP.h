#ifndef _CCP_
#define _CCP_
#include "Commandbase.h"
#include "algori.h"
class CommandCP:public CommandBase{
    public:
        int run(string st);//V1.0 overwrite V1.1 overwrite check
        string help();
};
#endif