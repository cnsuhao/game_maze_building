#include <fstream>
using namespace std;
fstream error("JustaTry.txt",ios::out);
#include "ControlCenter.h"
#include "crashData.h"
ControlCenter CC;
int main(int argc, _TCHAR* argv[])
{
    glPointSize(15.0);
    float Tr[]={2.0,2.0,
             1.5,-2.0,
            -1.5,-2.0,
             -1.5,2.0,
              -0.5,0.0,
              0.5,0.0,
              2.0,2.0};
   CrashData Ty(Dead);
   XYF Tx(0.0,0.2);
   CC.Ready();
   CC.Init(1,600,600);
   float Te={1.0,1.0,0.0,
             -1.0,1.0,0.0,
             -1.0,-1.0,0.0,
             1.0,-1.0,0.0}
   while(CC.Running)
   {
        CC.Run();
        Ty.Set(Tr,7,Ty.ValueData,Ty.ValueDataE);
        if(Ty.Check(Tx,Ty.ValueData,Ty.ValueDataE))  error<<"在内部"<<endl;
        else error<<"不再内部"<<endl;
        CC.Finish();
   }
}
