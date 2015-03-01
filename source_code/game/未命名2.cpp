#include <fstream>
using namespace std;
fstream error("JustaTry.txt",ios::out);
#include "CrashData.h"
#include "Crash.h"
int main()
{
    float Tr[]={2.0,2.0,
             1.5,-2.0,
            -1.5,-2.0,
             -1.5,2.0,
              -0.5,0.0,
              0.5,0.0,
              2.0,2.0};
   CrashData Ty(Dead);
   CrashData Tf(Dead);
   float Te[]={1.0,1.0,0.0,
             -1.0,1.0,0.0,
             -1.0,-1.0,0.0,
             1.0,-1.0,0.0};
    float Tc[]={-1.0,1.0,0.5,
             1.0,1.0,0.5,
             1.0,-1.0,0.5,
             -1.0,-1.0,0.5};
    Ty.FaceAdd(Te,4);
    Tf.FaceAdd(Tc,4);
    Ty.CheckFace();
    Tf.CheckFace();
    XYZF Vec(0.0,0.0,0.4);
    if(Ty.CheckFace(&Tf,Vec)) error<<"¸ã¶¨À²"<<endl;
    else error<<"Ã»¸ã¶¨À²"<<endl;
        

}
