#ifndef DIY_ERROR_H
#define DIY_ERROR_H
#include <fstream>
#include <string>
#include "Information.h"
#include "Plugin_base.h"
#define ERRRUNTIME 0
class Error: public Plugin_Base
{
    bool Use;
    bool Run;
    std::fstream File;
    std::list< Information > RefuseList;
    std::string Adress;
    public:
        void Analyze(void*);
        Error(bool use);
        Error(char* file);
        void Check(Information Tem);
                
};



#include "Error.cpp"
#endif
