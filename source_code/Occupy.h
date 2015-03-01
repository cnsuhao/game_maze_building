#ifndef DIY_OCCUPY_H
#include "baseclass.h"
#include <vector>
#include <list>
#define DIY_OCCUPY_H
#define OCCLINE 1
#define OCCDATABEGIN 9
#define OCCDATAEND 56
#define OCCMAPBEGIN 3
#define OCCMAPEND 4
#define OCCMARK 98

#define OCCPBEGIN 45
#define OCCPMIDDLE 78
#define OCCPEND 1244


class OccData:public XYZF
{
    public:
        int Mode;
        OccData(int M,float x,float y,float z):Mode(M),XYZF(x,y,z){}
        void Get(XYZF Tem,int m)
        {
            Mode=m;
            X=Tem.X;
            Y=Tem.Y;
            Z=Tem.Z;
        }
        void operator=(XYZF Tem)
        {
            X=Tem.X;
            Y=Tem.Y;
            Z=Tem.Z;
        }
};
class OccDeadMap
{
     void* Data;
    int XB;
    int ZB;
    int Aspect;
    public:
        void Add(float* Point, int Size)
        {
            if(Data!=NULL)
            {
                operator delete[] (Data);
            }
            Data=operator new[]((Size+2)*sizeof(OccData));
            OccData* Te=static_cast<OccData*>(Data);
            Te->Mode=OCCMAPBEGIN;
            Te->X=XB;
            Te->Y=ZB;
            Te->Z=Aspect;
            (Te+1+Size)->Mode=OCCMAPEND;
            for(int i=1;i<=Size;++i)
            {
                if(i==1)
                {
                    (Te+1)->Mode=OCCPBEGIN;
                }else if(i==Size)
                {
                    (Te+i)->Mode=OCCPEND;
                }else{
                    (Te+i)->Mode=OCCPMIDDLE;
                }
                (Te+i)->X=*(Point+(i-1)*3);
                (Te+i)->Y=*(Point+(i-1)*3+1);
                (Te+i)->Z=*(Point+(i-1)*3+2);
            }
        }
        void* Push(void)
        {
            return Data;
        }
        OccDeadMap(void):Data(NULL),XB(4),ZB(4),Aspect(1){}
        ~OccDeadMap(void)
        {
            if(Data!=NULL)
            {
                operator delete[] (Data);
            }
        }
};
class OccupyControl
{
    bool Check(float x,float y,float x2,float x3,int x,int z);
    public:
    friend class PhysicsControl;
    int BlockX;
    int BlockZ;
    int Aspect;
    std::vector< float > X;
    std::vector< float > Z;
    std::vector< std::list<OccData>::iterator > XZEnsample;
    std::list< OccData > XZLimited;
    std::list< OccData > XZDead;
    void ChangeMap(void* Data);
    void Check();
    bool Check(float x,float y,float z,float dis);
    bool DeadCheck(float x,float y,float z,float dis);
    bool LimitedCheck(float x,float y,float z,float dis);
    void LimitedAdd(void* Data);
    void DeadAdd(void* Data);
    OccupyControl(){}
};
#include "Occupynew.cpp"
#endif
