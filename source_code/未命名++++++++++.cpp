#include <fstream>
using namespace std;
fstream ty("Check.txt",std::fstream::out);
#include "OccupyNew2.h"
int main()
{
    OccupyDead tt;
    float pe[]={0,0,
                4,0,
                4,4,
                2,3,
                2,4,
                4,5,
                0,5,
                0,0};
    tt.Add(pe,16);
    tt.Print();
    return 1;
}
