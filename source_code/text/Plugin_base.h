#ifndef DIY_PLUGIN_BASE_H
#define DIY_PLUGIN_BASE_H
#include <string>
#include <list>
#include <map>
#include <vector>
#include <set>
#include "Information.h"
class Plugin_Base;
std::map<std::string , int > NaTarSI;
std::map<int , Plugin_Base* > NaTarIP;
std::map<int , std::string > NaTarIS;
inline int Call(std::string Tem)
{
    if(NaTarSI.count(Tem))
        return NaTarSI[Tem];
    else
        return INFNOTAR;
}
inline Plugin_Base* Call(int Tem)
{
    if(NaTarIP.count(Tem))
        return NaTarIP[Tem];
    else
        return NULL;
}
int Thread_1_Function(void* Data);
class Plugin_Base //²å¼þ»ùÀà 
{
    protected:
    friend class ControlCenter;
    friend int Thread_1_Function(void* Data);
    int RegeditID;
    const std::string Name;
    std::list< Information > OutLibrary;
    std::list< Information > Library;
    bool FunSho;
    void virtual Destory(ControlCenter* Data);
    void virtual Show(ControlCenter* Data);
    bool FunAna;
    void virtual Analyze(ControlCenter* Data);
    void virtual Init(ControlCenter* Data);
    bool RefuseINFALL;
    bool FunDel;
    public: 
        bool ShootLib(Information& Temp);
        Information Deliver(Information& Tem);
        Plugin_Base(std::string name);
        Plugin_Base(std::string name,bool choice);
        void Useless(void);
        void GetLib(Information& Temp);
        void ToAspect(unsigned int Te);
        void Orthogonality(void);
        void Perspective(void);
        void UnableExit(void);
        void Kill(void);
        void Out(Information& Tem);
        Information NewInformation(int Target,int Category1,int Category2,int Category3,int Category4);
        Information GetInformation(void);
}; 


#include "Plugin_base.cpp"
#endif
