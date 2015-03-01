#ifndef DIY_HARDCONTROL_H
#define DIY_HARDCONTROL_H
#include <fstream>
#include "math.h"
#include <map>
#include "information.h"
#include "Plugin_Base.h"
class HardControl:public Plugin_Base
{
    XYZF Location1;
    XYZF Location2;
    XYZF Face1;
    XYZF Face2;
    XYZF Up1;
    XYZF Up2;
    XYZF* LocPoi;
    XYZF* FacPoi;
    XYZF* UpPoi;
    XYZF MouseLocation;
    int X;
    int Y;
    float AngleUp;
    float AngleRight;
    float XMove;
    float YMove;
    float Death;
    bool MouseMotion;
    bool Mouse;
    bool Set;
    std::map<unsigned int , bool> KeyBool;
    public:
        void Show(ControlCenter* CC)
        {
            glColor3f(1.0,0.0,1.0);
                Set=false;
                Information Te;
                if(KeyBool['r'])
                {
                    (*LocPoi)=(*LocPoi)+(*FacPoi)*0.05;
                    Set=true;
                }
                if(KeyBool['f'])
                {
                    (*LocPoi)=(*LocPoi)-(*FacPoi)*0.05;
                    Set=true;
                }
                if(KeyBool['a'])
                {
                    (*LocPoi)=(*LocPoi)+((*UpPoi)&(*FacPoi))*0.05;
                    Set=true;
                }
                if(KeyBool['d'])
                {
                    (*LocPoi)=(*LocPoi)-((*UpPoi)&(*FacPoi))*0.05;
                    Set=true;
                }
                if(KeyBool['q'])
                {
                    LocPoi=&Location1;
                    FacPoi=&Face1;
                    UpPoi=&Up1;
                    Set=true;
                }
                if(KeyBool['e'])
                {
                    UpPoi=&Up2;
                    LocPoi=&Location2;
                    FacPoi=&Face2;
                    Set=true;
                }
                if(KeyBool['w'])
                {
                    *LocPoi=(*LocPoi)+(*UpPoi)*0.05;
                    Set=true;
                }
                if(KeyBool['s'])
                {
                    *LocPoi=(*LocPoi)-(*UpPoi)*0.05;
                    Set=true;
                }
                if(Mouse)
                {
                    float Temporary2;
                    glReadBuffer(GL_FRONT);
                    glReadPixels(X,CC->WindowY()-Y,1,1,GL_DEPTH_COMPONENT,GL_FLOAT,&Temporary2);
                    kk<<Temporary2<<endl;
                }
                if(MouseMotion)
                {
                    AngleRight+=XMove;
                    AngleUp+=YMove;
                    FacPoi->Set(cos(AngleUp)*sin(AngleRight),sin(AngleUp),-cos(AngleUp)*cos(AngleRight));
                    UpPoi->Set(-sin(AngleUp)*sin(AngleRight),cos(AngleUp),sin(AngleUp)*cos(AngleRight));
                    MouseMotion=false;
                    Set=true;
                }
                if(Set)
                {
                    Te=NewInformation(Call("View"),VIEWLOCATION);
                    Te.Data1.f=LocPoi->X;
                    Te.Data2.f=LocPoi->Y;
                    Te.Data3.f=LocPoi->Z;
                    OutLibrary.push_back(Te);
                    Te=NewInformation(Call("View"),VIEWFACE);
                    Te.Data1.f=FacPoi->X;
                    Te.Data2.f=FacPoi->Y;
                    Te.Data3.f=FacPoi->Z;
                    OutLibrary.push_back(Te);
                    Te=NewInformation(Call("View"),VIEWUP);
                    Te.Data1.f=UpPoi->X;
                    Te.Data2.f=UpPoi->Y;
                    Te.Data3.f=UpPoi->Z;
                    OutLibrary.push_back(Te);
                    MouseMotion=false;
                }
                glColor3f(1.0,0.0,0.0);
                glBegin(GL_POINTS);
                //glVertex(Face1+Location1);
                glEnd();
        }
        void Init(ControlCenter* CC)
        {
            KeyBool.insert(std::make_pair('w',false));
            KeyBool.insert(std::make_pair('W',false));
            KeyBool.insert(std::make_pair('s',false));
            KeyBool.insert(std::make_pair('S',false));
            KeyBool.insert(std::make_pair('a',false));
            KeyBool.insert(std::make_pair('A',false));
            KeyBool.insert(std::make_pair('d',false));
            KeyBool.insert(std::make_pair('D',false));
            KeyBool.insert(std::make_pair('q',false));
            KeyBool.insert(std::make_pair('Q',false));
            KeyBool.insert(std::make_pair('e',false));
            KeyBool.insert(std::make_pair('E',false));
            KeyBool.insert(std::make_pair('r',false));
            KeyBool.insert(std::make_pair('R',false));
            KeyBool.insert(std::make_pair('f',false));
            KeyBool.insert(std::make_pair('F',false));
        }
        void Analyze(ControlCenter* CC)
        {
            Information Te=GetInformation();
            if(Te.Target==RegeditID||Te.Target==INFALL)
            {
                if(Te.Category1==INFEVENT)
                {
                    switch(Te.Category2)
                    {
                        case INFKEY:
                            if(Te.Category3==INFKEYUP)
                            {
                                if(KeyBool.count(Te.Data1.ui)!=0)
                                {
                                    KeyBool[Te.Data1.ui]=false;
                                    if(Te.Data1.ui<='z'&&Te.Data1.ui>='a')
                                        KeyBool[Te.Data1.ui-32]=false;
                                    else if(Te.Data1.ui<='Z'&&Te.Data1.ui>='A')
                                        KeyBool[Te.Data1.ui+32]=false;
                                }
                            }else if(Te.Category3==INFKEYDOWN)
                            {
                                if(KeyBool.count(Te.Data1.ui)!=0)
                                {
                                    KeyBool[Te.Data1.ui]=true;
                                    if(Te.Data1.ui<='z'&&Te.Data1.ui>='a')
                                        KeyBool[Te.Data1.ui-32]=true;
                                    else if(Te.Data1.ui<='Z'&&Te.Data1.ui>='A')
                                        KeyBool[Te.Data1.ui+32]=true;
                                }
                            }
                            break;
                        case INFMOUSE:
                            if(Te.Category3==MOUSEMOTION)
                            {
                                if(Mouse)
                                {
                                    XMove=(float)Te.Data6.i/CC->WindowX();
                                    YMove=-(float)Te.Data7.i/CC->WindowY();
                                    MouseMotion=true;
                                }
                            }else if(Te.Category3==MOUSEBUTTONDOWN)
                            {
                                float Temporary2=100000; 
                                Death=Te.Data3.f;
                                MouseLocation.Set(Te.Data1.f,Te.Data2.f,Te.Data3.f);
                                X=Te.Data4.i;
                                Y=Te.Data5.i;
                                //kk<<Temporary2<<endl;
                                Mouse=true;
                            }else if(Te.Category3==MOUSEBUTTONUP)
                            {
                                MouseLocation.Set(Te.Data1.f,Te.Data2.f,Te.Data3.f);
                                Mouse=false;
                            }
                            break;
                    }
                }
            }
            
        }
        HardControl():Plugin_Base("Hard"),Location1(0,0,0),Location2(0,0,0),Face1(0,0,-1),Face2(0,0,-1),Up1(0,1.0,0),Up2(0,1.0,0)
        {
            AngleRight=0;
            AngleUp=0;
            LocPoi=&Location1;
            FacPoi=&Face1;
            UpPoi=&Up1;
        }
};
#endif
