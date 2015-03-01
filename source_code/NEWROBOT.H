#ifndef DIY_NROBOT_H
#define DIY_NROBOT_H
#include <vector>
#include "baseclass.h"
#define RHuman 12
inline void PT(const float* tte,int Tem=1)
{
    glVertex3f(*(tte+(Tem-1)*3),*(tte+(Tem-1)*3+1),*(tte+(Tem-1)*3+2));
}
inline void PT(XYZF Tem)
{
    glVertex3f(Tem.X,Tem.Y,Tem.Z);
}
inline void Leg(const float* tte, float size=0.05, float R=1.0, float G=1.0, float B=1.0)
{
    glColor3f(R,G,B);
    XYZF PP1(*tte,*tte+1,*tte+2);
    XYZF PP2(*(tte+6),*(tte+7),*(tte+8));
    XYZF T1(PP2-PP1);
    XYZF T2(*(tte+3),*(tte+4),*(tte+5));
    XYZF T3(T2^T1);
    T1.Uint(0.02);
    T2.Uint(size);
    T3.Uint(size);
    XYZF P1(PP1+T1+T2+T3);
    XYZF P2(PP1+T1+T2-T3);
    XYZF P3(PP2-T1+T2-T3);
    XYZF P4(PP2-T1+T2+T3);
    
    XYZF P5(PP2-T1+T3-T2);
    XYZF P6(PP1+T1+T3-T2);
    XYZF P7(PP1+T1-T3-T2);
    XYZF P8(PP2-T1-T3-T2);
    glBegin(GL_QUADS);
    PT(P1);
    PT(P2);
    PT(P3);
    PT(P4);
    
    PT(P7);
    PT(P6);
    PT(P5);
    PT(P8);
    
    PT(P2);
    PT(P7);
    PT(P8);
    PT(P3);
    
    PT(P6);
    PT(P1);
    PT(P4);
    PT(P5);
    
    PT(P7);
    PT(P2);
    PT(P1);
    PT(P6);
    
    PT(P3);
    PT(P4);
    PT(P5);
    PT(P8);
    glEnd();
}
class Robot
{
    void* Memory;
    float* Body;
    float Hand[2][8*3];
    float Food[2][3*3];
    public:
        int x(int k)
        {
            return (k-1)*3;
        }
        int y(int k)
        {
            return (k-1)*3+1;
        }
        int z(int k)
        {
            return (k-1)*3+2;
        }
        void Creat(int Mode,float Up,float Down)
        {
            if(Body==NULL)
            {
                if(Mode==RHuman)
                {
                    float Subtract=(Up-Down)/7;
                    Memory=operator new[](sizeof(float)*27*3);
                    Body=static_cast<float*>(Memory);
                    for(int k=0;k>=0&&k<=26;k+=1)
                    {
                        *(Body+k*3)=0.0;
                        //*(Body+k*3+1)=0.0;
                        *(Body+k*3+2)=-1.0;
                    }
                    Body[y(1)]=Up;
                    Body[y(3)]=Up-Subtract;
                    Body[y(5)]=Up-Subtract*3;
                    Body[y(7)]=Up-Subtract*3.5;
                    
                    Body[y(8)]=Up-Subtract*4;
                    Body[x(8)]=-Subtract*0.5;
                    Body[x(10)]=-Subtract*0.5;
                    Body[y(10)]=Up-Subtract*5.4;
                    Body[x(12)]=-Subtract*0.5;
                    Body[y(12)]=Down;
                    
                    Body[y(13)]=Up-Subtract*4;
                    Body[x(13)]=+Subtract*0.5;
                    Body[x(15)]=+Subtract*0.5;
                    Body[y(15)]=Up-Subtract*5.4;
                    Body[x(17)]=+Subtract*0.5;
                    Body[y(17)]=Down;
                    
                    Body[x(18)]=-Subtract;
                    Body[y(18)]=Up-Subtract*1.5;
                    Body[x(20)]=-Subtract*1.1;
                    Body[y(20)]=Up-Subtract*2.5;
                    Body[x(22)]=-Subtract;
                    Body[y(22)]=Up-Subtract*3.5;
                    
                    Body[x(23)]=Subtract;
                    Body[y(23)]=Up-Subtract*1.5;
                    Body[x(25)]=Subtract*1.1;
                    Body[y(25)]=Up-Subtract*2.5;
                    Body[x(27)]=Subtract;
                    Body[y(27)]=Up-Subtract*3.5;
                }
                
            }
        }
        void Show()
        {
            if(Body!=NULL)
            {
                float* PX=Body;
                glPushMatrix();
                Leg(PX);
                Leg(PX+17*3);
                Leg(PX+19*3);
                Leg(PX+22*3);
                Leg(PX+24*3);
                Leg(PX+7*3);
                Leg(PX+9*3);
                Leg(PX+12*3);
                Leg(PX+14*3);
                glPopMatrix();
            }
        }
        Robot(float* Point, int size)
        {}
        Robot()
        {}
        ~Robot()
        {
            if(Body!=NULL)
            {
                operator delete[](Memory);
                Body=NULL;
            }
        }
};
#endif
