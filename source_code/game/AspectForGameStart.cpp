#include "Chestnut.h"
#include "Object.h"
#include "Occupy.h"
#define SPEED 0.05
#define ASPLOCATION 5689
#define ASPANGLE 7854
#define ASPSTATE 45897
class Aspect:public Plugin_Base
{
    Chestnut Tu;
    Object TTr;
    XYZF Location;
    XYZF Location2;
    float AngleUp;
    float AngleRight;
    float Angle2;
    XYZF Face;
    XYZF Face2;
    XYZF Up;
    std::map<unsigned char , bool > Key;
    ChState State;
    bool jumping;
    XYZF Qian;
    public:
        Aspect():Plugin_Base("Aspect")
        {
            AngleRight=0.0;
            Location.Set(0.0,0.0,0.0);
            Key.insert(make_pair('w',false));
            Key.insert(make_pair('s',false));
            Key.insert(make_pair('a',false));
            Key.insert(make_pair('d',false));
            Key.insert(make_pair(27,false));
            Key.insert(make_pair(32,false));
            jumping=false;
        }
        void Show(ControlCenter* Data)
        {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            TTr.Show();
            Tu.Show(State,Location,-(AngleRight)*57.296-180+Angle2);
            Control(Data);
        }
        void Init(ControlCenter* Data)
        {
            Tu.Init(Data);
            TTr.Read("TextForFace.bib");
            Location.Set(0.0,0.0,0.0);
            AngleUp=-0.5;
            AngleRight=0.0;
            Face.Set(sin(AngleRight),0.0,-cos(AngleRight));
            Up.Set(-sin(AngleUp)*sin(AngleRight),cos(AngleUp),sin(AngleUp)*cos(AngleRight));
            Face2.Set(cos(AngleUp)*sin(AngleRight),sin(AngleUp),-cos(AngleUp)*cos(AngleRight));
            Information Tem=NewInformation(Call("View"),VIEWLOCATION);
            XYZF TemXYZ;    TemXYZ=Location-Face2*4;    Tem.Data1.f=TemXYZ.X;   Tem.Data2.f=TemXYZ.Y;   Tem.Data3.f=TemXYZ.Z;    Out(Tem);
            Tem=NewInformation(Call("View"),VIEWANGLE);
            Tem.Data2=AngleRight;   Tem.Data1=AngleUp;  Out(Tem);
        }
        void Analyze(ControlCenter* CC)
        {
            while(!Library.empty())
            {
                //error<<"dfjashdlkjahfasdf"<<endl;
                Information Tem=GetInformation();
                if(Tem.Category1==INFEVENT&&Tem.Category2==INFKEY)
                {
                    if(Tem.Category3==INFKEYDOWN)
                    {
                        if(Key.count(Tem.Data1)>0)
                        {
                            Key[Tem.Data1]=true;
                        }
                    }else if(Tem.Category3==INFKEYUP)
                    {
                        if(Key.count(Tem.Data1)>0)
                        {
                            Key[Tem.Data1]=false;
                        }
                    }
                }else if(Tem.Category1==INFEVENT&&Tem.Category2==INFMOUSE)
                {
                    if(Tem.Category3==MOUSEMOTION&&!jumping)
                    {
                        AngleRight-=Tem.Data3.i*0.005;
                        AngleUp+=Tem.Data4.i*0.005;
                        Face.Set(sin(AngleRight),0.0,-cos(AngleRight));
                        Face2.Set(cos(AngleUp)*sin(AngleRight),sin(AngleUp),-cos(AngleUp)*cos(AngleRight));
                        Up.Set(-sin(AngleUp)*sin(AngleRight),cos(AngleUp),sin(AngleUp)*cos(AngleRight));
                        Information Tem=NewInformation(Call("View"),VIEWANGLE);
                        Tem.Data1.f=AngleUp;
                        Tem.Data2.f=AngleRight;
                        Out(Tem);
                        Tem=NewInformation(Call("View"),VIEWLOCATION);
                        XYZF TemXYZ;
                        TemXYZ=Location-Face2*4;
                        Tem.Data1.f=TemXYZ.X;
                        Tem.Data2.f=TemXYZ.Y;
                        Tem.Data3.f=TemXYZ.Z;
                        Out(Tem);
                    }
                }
            }
            if(Key[27])    Exit();
            //if(Key[27])    Exit();
        }
        void Control(ControlCenter* );
        void Time(ControlCenter*);
            
};
void Aspect::Control(ControlCenter* CC)
{
    bool Set=false;
    static XYZF Qian;
    static bool space2=false;
    static bool space3=false;
    static int Timee;
    static int Timee2;
    if(!jumping)
    {
        Qian.Set(0.0,0.0,0.0);
        if(Key['w'])
        {
            Location=Location+Face*SPEED;
            Set=true;
            Qian=Qian+Face;
        }
        if(Key['s'])
        {
            Location=Location-Face*SPEED;
            Set=true;
            Qian=Qian-Face;
        }
        if(Key['a'])
        {
            Location=Location-XYZF(-Face.Z,0.0,Face.X)*SPEED;
            Set=true;
            Qian=Qian-XYZF(-Face.Z,0.0,Face.X);
        }
        if(Key['d'])
        {
            Location=Location+XYZF(-Face.Z,0.0,Face.X)*SPEED;
            Set=true;
            Qian=Qian+XYZF(-Face.Z,0.0,Face.X);
        }
        if(Key['a']||Key['w']||Key['s']||Key['d'])
        {
            State=walk;
        }else{
            State=quiet;
        }
        if(Key['w']&&!Key['s'])
        {
            if(Key['a']&&(!Key['d']))
            {
                Angle2=45;
            }else if((!Key['a'])&&(Key['d']))
            {
                Angle2=-45;
            }else{
                Angle2=0;
            }
        }else if(Key['s']&&!Key['w'])
        {
            if(Key['a']&&(!Key['d']))
            {
                Angle2=135;
            }else if((!Key['a'])&&(Key['d']))
            {
                Angle2=-135;
            }else{
                Angle2=180;
            }
        }else if(Key['a']&&!Key['d'])
        {
            Angle2=90;
        }else if(!Key['a']&&Key['d'])
        {
            Angle2=-90;
        }
    }
    if(!space2)
    {
        if(Key[32])
        {
            space2=true;
            Timee=CC->Time(0);
        }
    }else{
        if(CC->Time(Timee)>=50||Key[32]==false)
        {
            jumping=true;
            Timee2=CC->Time(0);
            space2=false;
            Timee=CC->Time(Timee);
            Key[32]=false;
        }
    }
    if(jumping)
    {
        Set=true;
        if(CC->Time(Timee2,Timee2+Timee*20))
        Location=Location+Qian.Uint()*SPEED+XYZF(0.0,0.02,0.0);
        else if(CC->Time(Timee2+Timee*20,Timee2+Timee*40))
        Location=Location+Qian.Uint()*SPEED+XYZF(0.0,-0.02,0.0);
        else{
            jumping=false;
        }
    }
    if(Set)
    {
        Information Tem=NewInformation(Call("View"),VIEWLOCATION);
        XYZF TemXYZ;
        TemXYZ=Location-Face2*4;
        Tem.Data1.f=TemXYZ.X;
        Tem.Data2.f=TemXYZ.Y;
        Tem.Data3.f=TemXYZ.Z;
        Out(Tem);
    }
}   
void Aspect::Time(ControlCenter* CC)
{

}
