#ifndef DIY_HARDCONTROL_H
#define DIY_HARDCONTROL_H
#include <fstream>
#include "math.h"
#include <map>
#include "information.h"
#include "Plugin_Base.h"
#include "numberout.h"
class HardControl:public Plugin_Base
{
    XYZF Location1;
    XYZF Location2;
    XYZF Face1;
    XYZF Face2;
    XYZF Up1;
    XYZF Up2;
    XYZF Point;
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
    bool Showt;
    bool Shoee;
    bool Sher; 
    int Cul;
    float Size;
    std::map<unsigned char , bool> KeyBool;
    Number Num;
    int Fg[20];
    int Oi[3];
    int Tr;
    void LookAt(const XYZF,float,float);
    public:
        void Time(ControlCenter* CC);
        void Show(ControlCenter* CC)
        {
                    Num.Reflesh(Fg,11);
                    Num.Reflesh(Oi,3);
                    Num.Reflesh(Tr);
            glColor3f(1.0,0.0,1.0);
                glColor3f(0.0,0.0,1.0);
                glBegin(GL_LINES);
                glVertex(Point+XYZF(10.0,0.0,0.0));
                glVertex(Point+XYZF(-10.0,0.0,0.0));
                glVertex(Point+XYZF(0.0,10.0,0.0));
                glVertex(Point+XYZF(0.0,-10.0,0.0));
                glVertex(Point+XYZF(0.0,0.0,10.0));
                glVertex(Point+XYZF(0.0,0.0,-10.0));
                glEnd();
                glBegin(GL_LINE_LOOP);
                glColor3f(1.0,0.0,0.0);
                glVertex3f(-1.0*Size*640/480,1.0*Size,-CC->NearSize-0.01);
                glVertex3f(1.0*Size*640/480,1.0*Size,-CC->NearSize-0.01);
                glVertex3f(1.0*Size*640/480,-1.0*Size,-CC->NearSize-0.01);
                glVertex3f(-1.0*Size*640/480,-1.0*Size,-CC->NearSize-0.01);
                glEnd();
                glPushMatrix();
                glLoadIdentity();
                for(int i=0;i<11;++i)
                {
                    Num.Show(Fg[i],-1.0,1.0-i*0.15);
                } 
                for(int i=0;i<3;++i)
                {
                    Num.Show(Oi[i],0.5,1.0-i*0.15);
                } 
                Num.Show(Tr,0.5f,-0.8f);
                glPopMatrix();
            
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
            KeyBool.insert(std::make_pair('p',false));
            KeyBool.insert(std::make_pair('o',false));
            KeyBool.insert(std::make_pair('y',false));
            KeyBool.insert(std::make_pair('h',false));
            KeyBool.insert(std::make_pair('g',false));
            KeyBool.insert(std::make_pair('j',false));
            KeyBool.insert(std::make_pair('k',false));
            KeyBool.insert(std::make_pair('l',false));
            KeyBool.insert(std::make_pair('z',false));
            Num.Init(CC);
            LookAt(XYZF(0.5143,0.7984,0.6372),-0.5667,-0.9422);
            Fg[0]=Num.Set(&Location1.X,NUM_FLOAT,"位置X坐标");
            Fg[1]=Num.Set(&Location1.Y,NUM_FLOAT,"位置Y坐标");
            Fg[2]=Num.Set(&Location1.Z,NUM_FLOAT,"位置Z坐标");
            
            Fg[3]=Num.Set(&Face1.X,NUM_FLOAT,"面向X坐标");
            Fg[4]=Num.Set(&Face1.Y,NUM_FLOAT,"面向Y坐标");
            Fg[5]=Num.Set(&Face1.Z,NUM_FLOAT,"面向Z坐标");
            
            Fg[6]=Num.Set(&Up1.X,NUM_FLOAT,"向上X坐标");
            Fg[7]=Num.Set(&Up1.Y,NUM_FLOAT,"向上Y坐标");
            Fg[8]=Num.Set(&Up1.Z,NUM_FLOAT,"向上Z坐标");
            
            Fg[9]=Num.Set(&AngleUp,NUM_FLOAT,"AngleUP");
            Fg[10]=Num.Set(&AngleRight,NUM_FLOAT,"AngleRight");
            
            Oi[0]=Num.Set(&Point.X,NUM_FLOAT,"X");
            Oi[1]=Num.Set(&Point.Y,NUM_FLOAT,"Y");
            Oi[2]=Num.Set(&Point.Z,NUM_FLOAT,"Z");
            
            Tr=Num.Set(&Cul,NUM_INT,"时间");
            
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
                                if(KeyBool.count(Te.Data1)!=0)
                                {
                                    KeyBool[Te.Data1.ui]=false;
                                    if(Te.Data1.ui<='z'&&Te.Data1.ui>='a')
                                        KeyBool[Te.Data1.ui-32]=false;
                                    else if(Te.Data1.ui<='Z'&&Te.Data1.ui>='A')
                                        KeyBool[Te.Data1.ui+32]=false;
                                }
                            }else if(Te.Category3==INFKEYDOWN)
                            {
                                if(KeyBool.count(Te.Data1)!=0)
                                {
                                    KeyBool[Te.Data1.ui]=true;
                                    if(Te.Data1.ui<='z'&&Te.Data1.ui>='a')
                                        KeyBool[Te.Data1.ui-32]=true;
                                    else if(Te.Data1.ui<='Z'&&Te.Data1.ui>='A')
                                        KeyBool[Te.Data1.ui+32]=true;
                                }else if(Te.Data1.uc==13)
                                {
                                    error<<"("<<Location1.X<<" "<<Location1.Y<<" "<<Location1.Z<<")"<<endl;
                                    error<<Size<<endl;
                                    error<<tan(45)<<endl;
                                }
                            }
                            break;
                        case INFMOUSE:
                            if(Te.Category3==MOUSEMOTION)
                            {
                                if(Mouse)
                                {
                                    XMove=(float)Te.Data3.i/CC->WindowX();
                                    YMove=-(float)Te.Data4.i/CC->WindowY();
                                    MouseMotion=true;
                                }
                            }else if(Te.Category3==MOUSEBUTTONDOWN)
                            {
                                float Temporary2=100000; 
                                Death=Te.Data3.f;
                                MouseLocation.Set(Te.Data1.f,Te.Data2.f,Te.Data3.f);
                                //X=Te.Data4.i;
                                //Y=Te.Data5.i;
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
        HardControl():Plugin_Base("Hard"),Location1(0,0,0),Location2(0,0,0),Face1(0,0,-1),Face2(0,0,-1),Up1(0,1.0,0),Up2(0,1.0,0),Point(0.0,0.0,0.0)
        {
            Size=0.5;
            AngleRight=0;
            AngleUp=0;
            LocPoi=&Location1;
            FacPoi=&Face1;
            UpPoi=&Up1;
            Shoee=false;
            Sher=false;
            Cul=1000;
        }
};
void HardControl::Time(ControlCenter* CC)
{
    //error<<"试过可以的啊"<<endl;
                    Set=false;
                Information Te;
                if(KeyBool['r'])
                {
                    (*LocPoi)=(*LocPoi)+(*FacPoi)*0.01;
                    Set=true;
                }
                if(KeyBool['f'])
                {
                    (*LocPoi)=(*LocPoi)-(*FacPoi)*0.01;
                    Set=true;
                }
                if(KeyBool['a'])
                {
                    (*LocPoi)=(*LocPoi)+((*UpPoi)&(*FacPoi))*0.01;
                    Set=true;
                }
                if(KeyBool['d'])
                {
                    (*LocPoi)=(*LocPoi)-((*UpPoi)&(*FacPoi))*0.01;
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
                if(KeyBool['y'])
                {
                    Point.Z+=0.01;
                    Set=true;
                }
                if(KeyBool['h'])
                {
                    Point.Z-=0.01;
                    Set=true;
                }
                if(KeyBool['g'])
                {
                    Point.X-=0.01;
                    Set=true;
                }
                if(KeyBool['j'])
                {
                    Point.X+=0.01;
                    Set=true;
                }
                if(KeyBool['k'])
                {
                    Point.Y+=0.01;
                    Set=true;
                }
                if(KeyBool['l'])
                {
                    Point.Y-=0.01;
                    Set=true;
                }
                if(KeyBool['p'])
                {
                    if(Showt)
                    {
                        Num.Off(Fg,11);
                    }else{
                        Num.In(Fg,11);
                    }
                    Showt=!Showt;
                    KeyBool['p']=false;
                    Set=true;
                }
                if(KeyBool['o'])
                {
                    if(Shoee)
                    {
                        Num.Off(Oi,3);
                    }else{
                        Num.In(Oi,3);
                    }
                    Shoee=!Shoee;
                    KeyBool['o']=false;
                    Set=true;
                }
                if(KeyBool['z'])
                {
                    
                    if(Sher)
                    {
                        Num.Off(Tr);
                    }else{
                        Num.In(Tr);
                    }
                    Cul=CC->Time(0);
                    //error<<Cul<<endl;
                    Sher=!Sher;
                    KeyBool['z']=false;
                    Set=true;
                }
                if(Mouse)
                {
                    float Temporary2;
                    glReadBuffer(GL_FRONT);
                    glReadPixels(X,CC->WindowY()-Y,1,1,GL_DEPTH_COMPONENT,GL_FLOAT,&Temporary2);
                    //kk<<Temporary2<<endl;
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
                    Te=NewInformation(Call("View"),VIEWANGLE);
                    Te.Data1.f=AngleUp;
                    Te.Data2.f=AngleRight;
                    OutLibrary.push_back(Te);
                    MouseMotion=false;
                }
} 
void HardControl::LookAt(const XYZF X,float Up,float Right )
{
    AngleUp=Up;
    AngleRight=Right;
    Location1=X;
    Face1.Set(cos(AngleUp)*sin(AngleRight),sin(AngleUp),-cos(AngleUp)*cos(AngleRight));
    Up1.Set(-sin(AngleUp)*sin(AngleRight),cos(AngleUp),sin(AngleUp)*cos(AngleRight));
    
    
}
#endif
