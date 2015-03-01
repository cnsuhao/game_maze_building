#ifndef DIY_CRASHMAP_CPP
#define DIY_CRASHMAP_CPP
#include "crashmap.h"
void CrashMap::Set(const float* Poi,int number)
{
    float Max=0.0,Mix=0.0,Maz=0.0,Miz=0.0;
    for(int i=0;i<number;++i)
    {
        if(Poi[i]>Max) Max=Poi[i];
        else if(Poi[i]<Mix) Mix=Poi[i];
        if(Poi[i+1]>Maz) Maz=Poi[i+1];
        else if(Poi[i+1]<Miz) Miz=Poi[i+1];
    }
    MaxX=Max;
    MinX=Mix;
    MaxZ=Maz;
    MinZ=Miz;
    CrashData::Set(Poi,number);
}
void CrashMap::SetMapSize(unsigned int x,unsigned int z)
{
    if(x>0&&z>0)
    {
        X=x;
        Z=z;
    }
}
#endif
