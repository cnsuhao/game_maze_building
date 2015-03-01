//先完成BUTTON头文件的完成。注意传递给BUTTON函数的INFORMATION格式 

#ifndef DIY_ASPECT_H
#define DIY_ASPECT_H
#include <math.h>
#include "Information.h"
#include "sgprint.h"
#include "ControlCenter.h"
#include "Robot.h"
#include "map.h"
#include "wall.h"
#include "sgprint.h" 
#include "picture.h" 
//#include "button.h"
//#include "partylycontrol.h"
class zheng
{
    float x;
    float y;
    float z;
    float size;
    public:
        void Local(float X,float Y,float Z)
        {
            x=X;
            y=Y;
            z=Z;
        }
        void Size(float x)
        {
            size=x;
        }
        void Show(float cc=0, float kk=0 , float tt=0)
        {
            //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            //glEnable(GL_BLEND);

            glBegin(GL_QUADS);
            glColor3f(1.0,0.0,0.2);
            glVertex3f(x+size-cc,y+size-kk,z+size-tt);
            glColor3f(0.8,0.0,0.2);
            glVertex3f(x-size-cc,y+size-kk,z+size-tt);
            glColor3f(0.6,0.0,0.2);
            glVertex3f(x-size-cc,y-size-kk,z+size-tt);
            glColor3f(0.4,0.0,0.2);
            glVertex3f(x+size-cc,y-size-kk,z+size-tt);
            
            glColor3f(0.2,0.0,0.2);
            glVertex3f(x-size-cc,y+size-kk,z-size-tt);
            glColor3f(0.0,0.0,0.2);
            glVertex3f(x+size-cc,y+size-kk,z-size-tt);
            glColor3f(0.0,0.2,0.2);
            glVertex3f(x+size-cc,y-size-kk,z-size-tt);
            glColor3f(0.0,0.4,0.2);
            glVertex3f(x-size-cc,y-size-kk,z-size-tt);
            
            glColor3f(0.8,0.0,0.2);
            glVertex3f(x-size-cc,y+size-kk,z+size-tt);
            glColor3f(0.2,0.0,0.2);
            glVertex3f(x-size-cc,y+size-kk,z-size-tt);
            glColor3f(0.0,0.4,0.2);
            glVertex3f(x-size-cc,y-size-kk,z-size-tt);
            glColor3f(0.6,0.0,0.2);
            glVertex3f(x-size-cc,y-size-kk,z+size-tt);
            
            glColor3f(0.0,0.0,0.2);
            glVertex3f(x+size-cc,y+size-kk,z-size-tt);
            glColor3f(1.0,0.0,0.2);
            glVertex3f(x+size-cc,y+size-kk,z+size-tt);
            glColor3f(0.4,0.0,0.2);
            glVertex3f(x+size-cc,y-size-kk,z+size-tt);
            glColor3f(0.0,0.2,0.2);
            glVertex3f(x+size-cc,y-size-kk,z-size-tt);
            
            glColor3f(0.0,0.0,0.2);
            glVertex3f(x+size-cc,y+size-kk,z-size-tt);
            glColor3f(0.2,0.0,0.2);
            glVertex3f(x-size-cc,y+size-kk,z-size-tt);
            glColor3f(0.8,0.0,0.2);
            glVertex3f(x-size-cc,y+size-kk,z+size-tt);
            glColor3f(1.0,0.0,0.2);
            glVertex3f(x+size-cc,y+size-kk,z+size-tt);
            
            glColor3f(0.4,0.0,0.2);
            glVertex3f(x+size-cc,y-size-kk,z+size-tt);
            glColor3f(0.6,0.0,0.2);
            glVertex3f(x-size-cc,y-size-kk,z+size-tt);
            glColor3f(0.0,0.4,0.2);
            glVertex3f(x-size-cc,y-size-kk,z-size-tt);
            glColor3f(0.0,0.2,0.2);
            glVertex3f(x+size-cc,y-size-kk,z-size-tt);
            
            glEnd();
        }
    zheng(float X,float Y,float Z):x(X),y(Y),z(Z),size(0.1){}
};
class AspectFor3D: public Plugin_Base
{
    int Choice;
    float Angle;
    float Lx;
    float Ly;
    float Lz;
    Robot rrr;
    A T1;
    A T2;
    A T3;
    //Picture PP;
    Map yy;
    zheng tt;
    public:
    A3D P;
    void Show(void* Data);
    void Analyze(void* Data);
    void ExitAspect(ControlCenter* C,unsigned int& Block,unsigned int& Cul);
    void WelcomeAspect(ControlCenter* C,unsigned int& Block,unsigned int& Cul);
    void StartAspect(ControlCenter* C,unsigned int& Block,unsigned int& Cul);
    //void ToAspect(unsigned int Te);
    void MainAspect(ControlCenter* C,unsigned int& Block,unsigned int& Cul);
    AspectFor3D():Plugin_Base("Aspect"),tt(0.0,0.0,-4.0)//,P(),PP()
    {
        Angle=0.0;
        Lx=0.0;
        Ly=0.0;
        Lz=0.0;
        Choice=0;
        //PP.Load("tt.jpg");
    }
};
void AspectFor3D::Show(void* Data)
{
    static unsigned int Block=0;
    static unsigned int Cul=0;
    ControlCenter* C=static_cast<ControlCenter*>(Data);
    switch(C->Asp())
    {
        case 1://欢迎 
            //ToAspect(4);
            
            if(Choice==60)
            {
                Block=20;
            }
            WelcomeAspect(C,Block,Cul);
            break;
        case 2://开始菜单 
            StartAspect(C,Block,Cul);
            break;
        case 3://游戏读取 
        Kill();
            //P1.Show(-1.0,1.0,1.0,-1.0);
            break;
        case 4://游戏中 
             MainAspect(C,Block,Cul);
             
            break; 
        case 5://游戏中界面 
            break;
        case 80://游戏结束
            ExitAspect(C,Block,Cul);
            break; 
    }
}
void AspectFor3D::Analyze(void* Data)
{
    ControlCenter* C=static_cast<ControlCenter*>(Data);
    Information Temp;
    float Tx;
    float Ty;
    static float Sa=sin(0.5);
    static float Ca=cos(0.5);
    static float Xxx=0.0;
    static float Zzz=-0.5;
    static float Yyy=-0.8;
    while(!Library.empty())
    {
        Temp=*Library.begin();
        Library.pop_front();
        if(Temp.Target==RegeditID)
        {
            if(Temp.Category1==CHOICE)
               Choice=Temp.Data1.i;
            if(Temp.Category1==LOCAL)
            {
                Lx=Temp.Data1.f;
                Ly=Temp.Data2.f;
                Lz=Temp.Data3.f;
                Angle=Temp.Data4.f;
            }
        }
    }
}

#include "AspectFor3d_welcomeAspect.cpp"
#include "AspectFor3D_startaspect.cpp"
#include "AspectFor3d_ExitAspect.cpp"
#include "AspectFor3d_mainAspect.cpp"
#endif
