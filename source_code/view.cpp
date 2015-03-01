#ifndef DIY_VIEW_H
#define DIY_VIEW_H
#include "Plugin_Base.h"
#define VIEWLOCATION 125
#define VIEWFACE 458
#define VIEWUP 789
class View:public Plugin_Base
{
    XYZF Location;
    XYZF Face;
    XYZF Up;
    float X;
    float Y;
    float Z;
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
                if(Tem.Target==RegeditID)
                {
                    switch(Tem.Category1)
                    {
                        case VIEWLOCATION:
                            Location.X=Tem.Data1.f;
                            Location.Y=Tem.Data2.f;
                            Location.Z=Tem.Data3.f;
                            break;
                        case VIEWFACE:
                            Face.X=Tem.Data1.f;
                            Face.Y=Tem.Data2.f;
                            Face.Z=Tem.Data3.f;
                            break;
                        case VIEWUP:
                            Up.X=Tem.Data1.f;
                            Up.Y=Tem.Data2.f;
                            Up.Z=Tem.Data3.f;
                            break;
                    }
                }
            }
        }
};
#endif
