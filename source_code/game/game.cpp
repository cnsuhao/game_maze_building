#include "ControlCenter.h"
#include "Welcomeaspect.cpp"
#include "sgprint.h"
ControlCenter ty;
WelAsp WA;
int main(int argc, _TCHAR* argv[])
{
    ty.Regedit(&WA);
    ty.Ready();
    ty.Init(3);
    //A3D Te;
    //A3D Tr;
    //Te.Add("P.Oϵͳ");
    //Tr.Add("ϵͳ");
    while(ty.Running)
    {
        ty.Run();
        //Te.Show(XYZF(0.0,0.0,-0.2),XYZF(0.0,-1.0,0.0),XYZF(0.0,0.0,1.0));
        //Tr.Show(XYZF(0.0,-0.02,-0.2),XYZF(0.0,-1.0,0.0),XYZF(0.0,0.0,1.0));
        ty.Finish();
    }
}
