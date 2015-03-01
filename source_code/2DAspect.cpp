#ifndef DIY_2DASPECT_H
#define DIY_2DASPECT_H
#include <cmath>
#include "ControlCenter.h"
class 2DAspect
{
    float SizeY;
    float SizeX;
    float NearSize;
    float FarSize;
    public:
        void Init(ControlCenter* CC)
        {
            NearSize=CC->NearSize+0.001;
            SizeY=NearSize*tan(CC->angle*0.008726);
            SizeX=SizeY*CC->WindowW/CC->WindowH;
            FarSize=CC->FarSize-0.001;
            NearSize=-NearSize;
            FarSize=-FarSize;
        }
}
#endif
