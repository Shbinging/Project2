#ifndef _UI
#define _UI
#include"diag.h"
#include"CommandCAT.h"
#include"CommandCD.h"
#include"CommandCMP.h"
#include"CommandCP.h"
#include"CommandLS.h"
#include"CommandMAN.h"
#include"CommandWC.h"
#include"Commandbase.h"

class UI{
    public:
        int running(string st);
        void run();
};
#endif