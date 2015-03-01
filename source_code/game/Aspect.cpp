#include "Chestnut.h"
#include "Object.h"
#define SPEED 0.001
class Aspect:public Plugin_Base
{
    XYZF Location;
    XYZF Face;
    XYZF Face2;
    XYZF Up;
    float AngleUp;
    float AngleRight;
    Chestnut Tu;
    Object TTr;
    std::map<unsigned char , bool > Key;
    int State;
    public:
        Aspect():Plugin_Base("Aspect11")
        {
            AngleUp=-0.1084;
            AngleRight=0.0;
            Face.Set(sin(AngleRight),0.0,-cos(AngleRight));
            Face2.Set(cos(AngleUp)*sin(AngleRight),sin(AngleUp),-cos(AngleUp)*cos(AngleRight));
            Up.Set(-sin(AngleUp)*sin(AngleRight),cos(AngleUp),sin(AngleUp)*cos(AngleRight));
            Location.Set(0.0,0.5,0.0);
        }
        void Show(ControlCenter* Data)
        {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            TTr.Show();
            
            
           /*glColor3f(1.0,1.0,1.0);
            glBegin(GL_QUADS);
            
            glEnd();
            glColor3f(1.0,1.0,1.0);
            glBegin(GL_LINE_LOOP);
            glVertex3f(-1.0*640/480,1.0,0.0);
            glVertex3f(1.0*640/480,1.0,0.0);
            glVertex3f(1.0*640/480,-1.0,0.0);
            glVertex3f(-1.0*640/480,-1.0,0.0);
            glEnd();*/
            Tu.Show(walk,Location,AngleRight);
        }
        void Init(ControlCenter* Data)
        {
            Tu.Init(Data);
            TTr.Read("TextForFace.bib");
            Key.insert(make_pair('w',false));
            Key.insert(make_pair('s',false));
            Key.insert(make_pair('a',false));
            Key.insert(make_pair('d',false));
            Key.insert(make_pair(27,false));
            Key.insert(make_pair(32,false));
        }
        void Analyze(ControlCenter* CC)
        {
            while(!Library.empty())
            {
                error<<"dfjashdlkjahfasdf"<<endl;
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
                }
            }
            if(Key[27])    Exit();
        }
        void Time(ControlCenter* CC)
        {
            bool Set=false;
            if(Key['w'])
            {
                Location=Location+Face*SPEED;
                Set=true;
            }
            if(Key['s'])
            {
                Location=Location-Face*SPEED;
                Set=true;
            }
            if(Key['a'])
            {
                Location=Location-XYZF(-Face.Z,0.0,Face.X)*SPEED;
                Set=true;
            }
            if(Key['d'])
            {
                Location=Location+XYZF(-Face.Z,0.0,Face.X)*SPEED;
                Set=true;
            }
            if(Set)
            {
                Information Tem=NewInformation(Call("View"),VIEWLOCATION);
                Tem.Data1.f=Location.X;
                Tem.Data2.f=Location.Y;
                Tem.Data3.f=Location.Z;
                Out(Tem);
            }
        }
            
};
