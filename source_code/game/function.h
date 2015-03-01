#ifndef DIY_FUNCTION_H
#define DIY_FUNCTION_H

#include "baseclass.h"
#define NOUSE 0
#define XYFT 1
#define XYZFT 4
union FunctionPoint
{
    XYF (*XYFunTime)(int Time, Function& Te);
    XYZF (*XYZFunTime)(int Time, Function& Te);
};
class Function
{
    int Begin;
    int End;
    int StarTime;
    int Mode;
    FunctionPoint Fun;
    public:
    void Set(XYF (*Funcc)(int Time,Function& Te),int begin,int end)
    {
        Mode=XYFT;
        Fun.XYFunTime=Funcc;
        Begin=begin;
        End=end;
    }
    void Set(XYZF (*Funcc)(int Time,Function& Te),int begin,int end )
    {
        Mode=XYZFT;
        Fun.XYZFunTime=Funcc;
        Begin=begin;
        End=end;
    }
    XYZF Calculate(ControCenter* CC)
    {
        
    }
};


#endif
