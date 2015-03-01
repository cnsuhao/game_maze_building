#ifndef DIY_VIEW_H
#define DIY_VIEW_H
#include "Plugin_Base.h"
#define VIEWLOCATION 125
#define VIEWANGLE 458
#define VIEWUP 789
class View:public Plugin_Base
{
    XYZF Location;
    XYZF Face;
    XYZF Up;
    float AngleUp;
    float AngleRight;
    public:
        void Show(ControlCenter* Data)
        {
            //Z+=0.01;
            glLoadIdentity();
            gluLookAt(Location.X,Location.Y,Location.Z,Face.X+Location.X,Face.Y+Location.Y,Face.Z+Location.Z,Up.X,Up.Y,Up.Z);
        }
        View():Plugin_Base("View"),Location(0,0,0),Face(0,0,-1),Up(0,1,0){}
        void Analyze(ControlCenter* Data)
        {
            while(!Library.empty())
            {
                Information Tem=GetInformation();
                bool Reflesh=false;
                if(Tem.Target==RegeditID)
                {
                    switch(Tem.Category1)
                    {
                        case VIEWLOCATION:
                            Location.X=Tem.Data1.f;
                            Location.Y=Tem.Data2.f;
                            Location.Z=Tem.Data3.f;
                            Reflesh=true;
                            break;
                        case VIEWANGLE:
                            AngleUp=Tem.Data1;
                            AngleRight=Tem.Data2;
                            Face.Set(cos(AngleUp)*sin(AngleRight),sin(AngleUp),-cos(AngleUp)*cos(AngleRight));
                            Up.Set(-sin(AngleUp)*sin(AngleRight),cos(AngleUp),sin(AngleUp)*cos(AngleRight));
                            Reflesh=true;
                            break;

                    }
                    if(Reflesh)
                    {
                        Information Tr=Tem;
                        Tr.Target=Tem.Resource;
                        Tr.Resource=Tem.Target;
                        Out(Tr);
                    }
                }
            }
        }
        const XYZF* LocationPoint() const {  return &Location;  }
        const float* AngleRightPoint() const {  return &AngleRightPoint();  }
        const float* AngleUpPoint() const { return &AngleUpPoint(); }
};
#endif
