#ifndef  DIY_CONTROLCENTER_H 
#define  DIY_CONTROLCENTER_H 
#include <vector> 
#include <list>
#include <map>
#include <string>
#include "information.h"
#include "Plugin_base.h"
class ControlCenter
{
    friend int Thread_1_Function(void* Data);
    SDL_Event Event;
    SDL_Thread* Thread1;
    SDL_Thread* Thread2;
    SDL_Thread* Thread3;
    SDL_Surface* Screen; 
    std::list< Information > MainLibrary;
    std::list< Information > DeliverLibrary;
    std::vector< Plugin_Base* > FunctionLibrary;
    std::vector< Information > FastShoot;
    int ViewMode;//1为2D，2为3D正交，3为3D透视 
    int WindowW;
    int WindowH;
    float NearSize;
    float FarSize;
    float Angle;
    unsigned int Aspect;
    bool RegeditReady;
    public:
    int CalculateBlock;
    int Delay;
    int RegeditID;
    unsigned int Calculate;
    bool FunctionInUse;
    bool HaveToChange;
    bool ThreadReady;
    bool Running;
    bool ExitImi;
    bool SetView(int Mode); 
    unsigned int Asp(void);
        int WindowX()
        {
            return WindowW;
        }
        int WindowY()
        {
            return WindowH;
        } 
        bool Init(int Mode);
        void GetReady(void (*Temporary)(ControlCenter& This));
        int CheckInf(Information& Temp);
        void Finish(void);
        void Run(int number);
        void Regedit(Plugin_Base* Temporary);
        ControlCenter();
        void Ready();
        void AimAt(std::string Name , int Category1  , int Category2 , int Category3 );
        unsigned int Cal(unsigned int Number);
};
int Thread_1_Function(void* Data); //对数据的分析 
#include "controlcenter.cpp"
#endif
