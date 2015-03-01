/*���ߣ����ִ� 
 *����޸��ڣ� 2012��4��12�� 
 *�����÷������Ķ�λ��ĩβ����ϸ˵���顣
 */ 
/*   2012��4��20��
     �޸���ˢ�¼��ʱ��������ж�
     ������ʱ����Ӧ������ 
*/
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
    friend int Oclock(void *param);
    SDL_Event Event;
    SDL_Thread* Thread1;
    SDL_Thread* Thread2;
    SDL_Surface* Screen;
    std::list< Information > MainLibrary;   std::list< Information > DeliverLibrary;   std::list< Plugin_Base* > FunctionLibrary;  std::vector< Information > FastShoot;
    int ViewMode;//1Ϊ2D��2Ϊ3D������3Ϊ3D͸�� 
    unsigned int Aspect;
    bool RegeditReady;
    int TimeForShow,TimeForAnalyze;
    int DelayForShow,DelayForAnalyze;
    int RegeditID;
    int WindowW,WindowH;
    int Calculate;
    int StarTime;
    bool FunctionInUse;
    bool FunctionInUse2;
    bool HaveToChange;
    bool ThreadReady;
    bool ExitImi;
    bool TimeReadyToExit;
    bool AnalyzeReadyToExit;
    public:
        bool Running;
        float FarSize,Angle,NearSize;
        float Far,Near,FX,FY,NX,NY;
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
        bool Time(int X1,int X2);
        bool Init(int Mode,int W,int H);
        void GetReady(void (*Temporary)(ControlCenter& This));
        int CheckInf(Information& Temp);
        void Finish(void);
        void Run(int number);
        void Regedit(Plugin_Base* Temporary);
        ControlCenter();
        void Ready();
        void AimAt(std::string Name , int Category1  , int Category2 , int Category3 );
        int Time(int Number);
};
int Thread_1_Function(void* Data); //�����ݵķ��� 
Uint32 Oclock(Uint32 interval, void *param);
#include "controlcenter.cpp"
#endif
