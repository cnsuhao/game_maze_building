#ifndef DIY_PHYSICS_H
#define DIY_PHYSICS_H
#include "baseclass.h"
#include "Occupy.h"
#define PHYCHECK 4578
#define PHYINSIDE 7899
#define PHYOUTSIDE 78944
#define PHYADDMAP 47899
#define PHYADDDEAD 785499
class PhysicsControl : public Plugin_Base
{
    OccupyControl OC;
    public:
        void Analyze(void* Data);
        PhysicsControl():Plugin_Base("PHYSICAL"){}
};

#include "physics.cpp"
#endif
