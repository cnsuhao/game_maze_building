#ifndef  DIY_PARTYLYCONTROL_H 
#define  DIY_PARTYLYCONTROL_H 
#include <list>
#include "information.h"
#include "ControlCenter.h"
#include "math.h"
#include "physics.h"
#define SPEED 0.02
#define TURNSPEED 1
#define CHOICE 45
#define LOCAL 478
class KeyControl : public Plugin_Base
{
    int Choice;
    bool U;
    bool D;
    bool R;
    bool L;
    bool TR;
    bool TL;
    float NLX;
    float NLY;
    float NLZ;
    float LX;
    float LY;
    float LZ;
    float WX;
    float WY;
    float WZ;
    float speed;
    float Angle;
    public:
        void Show(void* Data)
        {
            ControlCenter* C=static_cast<ControlCenter*>(Data);
            if(C->Asp()==4)
            {
                glBegin(GL_LINES);
                glVertex3f(WZ,-WX,1.0);
                glVertex3f(0.0,0.0,1.0);
                glEnd();
            }
        }
        void Analyze( void* Data)
        {
            Information Tem;
            Information Temp;
            ControlCenter* C=static_cast<ControlCenter*>(Data);
            while(!Library.empty())
            {
                Tem=(*Library.begin());
                Library.pop_front();
                if(Tem.Category2==INFKEY&&Tem.Category1==INFEVENT)
                {
                    if(Tem.Category3==INFKEYDOWN)
                    {
                        switch(Tem.Data1.ui)
                        {
                            case SDLK_d:
                            case 'D':
                            case SDLK_RIGHT:
                                if(C->Asp()==4)
                                    R=true;
                                break;
                            case SDLK_a:
                            case 'A':
                            case SDLK_LEFT:
                                if(C->Asp()==4)
                                    L=true;
                                break;
                            case 'w':
                            case 'W':
                            case SDLK_UP:                              
                                if(C->Asp()==4)
                                    U=true;
                                else if(C->Asp()==2||C->Asp()==5)
                                {
                                    Choice-=1;
                                    if(Choice<0&&C->Asp()==2)
                                    {
                                        Choice+=3;
                                    }
                                    Temp.Resource=RegeditID;
                                    Temp.Target=Call("Aspect");
                                    Temp.Category1=CHOICE;
                                    Temp.Data1.i=Choice;
                                    OutLibrary.push_back(Temp);
                                }
                                break;
                            case 's':
                            case'S':
                            case SDLK_DOWN:
                                if(C->Asp()==4)
                                    D=true;
                                else if(C->Asp()==2||C->Asp()==5)
                                {
                                    Choice+=1;
                                    if(Choice>2&&Choice<10&&C->Asp()==2)
                                    {
                                        Choice=0;
                                    }
                                    Temp.Resource=RegeditID;
                                    Temp.Target=Call("Aspect");
                                    Temp.Category1=CHOICE;
                                    Temp.Data1.i=Choice;
                                    OutLibrary.push_back(Temp);
                                }
                                break;
                            case 'q':
                            case 'Q':
                                if(C->Asp()==4)
                                    TR=true;
                                break;
                            case 'e':
                            case 'E':
                                if(C->Asp()==4)
                                    TL=true;
                                break;
                            case 13:
                                U=false;
                                D=false;
                                R=false;
                                L=false;
                                TR=false;
                                TL=false;
                                if(C->Asp()==1||C->Asp()==2||C->Asp()==4||C->Asp()==5)
                                {
                                    Temp.Resource=RegeditID;
                                    Temp.Target=Call("Aspect");
                                    Temp.Category1=CHOICE;
                                    switch(C->Asp())
                                    {
                                        case 1:
                                            Choice=60;
                                            break;
                                        case 2:
                                            Choice+=50;
                                            break;
                                        case 4:
                                            Choice=5;
                                            break;
                                        case 5:
                                            Choice+=50;
                                            break;
                                    }
                                    Temp.Data1.i=Choice;
                                    OutLibrary.push_back(Temp);
                                    Choice=0;
                                }
                                             
                                    
                                break;
                            case 27:
                                U=false;
                                D=false;
                                R=false;
                                L=false;
                                TR=false;
                                TL=false;
                                if(C->Asp()==1||C->Asp()==2||C->Asp()==4||C->Asp()==5)
                                {
                                    Temp.Resource=RegeditID;
                                    Temp.Target=Call("Aspect");
                                    Temp.Category1=CHOICE;
                                    switch(C->Asp())
                                    {
                                        case 1:
                                            Choice=60;
                                            break;
                                        case 2:
                                            Choice=52;
                                            break;
                                        case 4:
                                            Choice=5;
                                            break;
                                        case 5:
                                            Choice=52;
                                    }
                                    Temp.Data1.i=Choice;
                                    OutLibrary.push_back(Temp);
                                    Choice=0;
                                }
                                break;
                                
                        }
                        
                    }
                    if(Tem.Category3==INFKEYUP)
                    {
                        if(C->Asp()==4)
                        {
                                                    switch(Tem.Data1.ui)
                        {
                            case SDLK_d:
                            case 'D':
                            case SDLK_RIGHT:
                                    R=false;
                                break;
                            case SDLK_a:
                            case 'A':
                            case SDLK_LEFT:
                                    L=false;
                                break;
                            case 'w':
                            case 'W':
                            case SDLK_UP:                              
                                    U=false;
                                break;
                            case 's':
                            case'S':
                            case SDLK_DOWN:
                                    D=false;
                                    break;
                            case 'q':
                            case 'Q':
                                    TR=false;
                                break;
                            case 'e':
                            case 'E':
                                    TL=false;
                                    break;
                        }
                    }
                    }
                }
                if(Tem.Resource==Call("Physics"))
                {
                    if(Tem.Category1==PHYOUTSIDE)
                    {
                        LX=NLX;
                        LY=NLY;
                        LZ=NLZ;
                    }
                    Temp=NewInformation(Call("Aspect"),LOCAL);
                    Temp.Data1.f=LX;
                    Temp.Data2.f=LY;
                    Temp.Data3.f=LZ;
                    Temp.Data4.f=Angle;
                    OutLibrary.push_back(Temp);
                }
                
            }
            if(C->Asp()==4)
            {
                if(U)
                {
                    NLX=LX+WX*SPEED;
                    //NLY=LY+WY*SPEED;
                    NLZ=LZ+WZ*SPEED;
                }
                if(D)
                {
                    NLX=LX-WX*SPEED;
                    //NLY=LY+WY*SPEED;
                    NLZ=LZ-WZ*SPEED;
                }
                if(R)
                {
                    Angle+=TURNSPEED;
                    WX=sin(Angle*0.017453292);
                    WZ=-cos(Angle*0.017453292);
                }
                if(L)
                {
                    Angle-=TURNSPEED;
                    WX=sin(Angle*0.017453292);
                    WZ=-cos(Angle*0.017453292);
                }
                if(TR)
                {
                    NLX=LX+WZ*SPEED;
                    //NLY=LY+WY*SPEED;
                    NLZ=LZ-WX*SPEED;
                }
                if(TL)
                {
                    NLX=LX-WZ*SPEED;
                    //NLY=LY+WY*SPEED;
                    NLZ=LZ+WX*SPEED;
                }
                Temp.Resource=RegeditID;
                Temp.Target=Call("Physics");
                Temp.Category1=PHYCHECK;
                Temp.Data1.f=NLX;
                Temp.Data2.f=NLY;
                Temp.Data3.f=NLZ;
                Temp.Data4.f=WX;
                Temp.Data5.f=WY;
                Temp.Data6.f=WZ;
                OutLibrary.push_back(Temp);
            }                             
            
        }
        KeyControl():Plugin_Base("Key")
        {
                                            U=false;
                                D=false;
                                R=false;
                                L=false;
                                TR=false;
                                TL=false;
                                WY=0;
                                WX=0;
                                WZ=-1;
        }
};
#endif
