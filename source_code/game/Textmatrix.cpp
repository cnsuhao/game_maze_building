#include <fstream>
using namespace std;
fstream tt("qqqqqqqqqqqqqqqqqq.txt",ios::out);
#include "detaminate.h"
#include "matrix.h"

int main()
{
    double ty[]={1,3,65,  2,78,2,  3,0,1,0,  0,6,0,1};
    //Detaminate GG(4,ty);
    //tt<<GG.Value()<<endl;
    Matrix Tu(3,3,ty);
    tt<<"原方程"<<endl;
    Tu.Check(); 
    (Tu*(!Tu)).Check();
    /*Matrix Tk(3,3,ty);
    if(Tu.Det()==(~Tu).Det())
    tt<<"对了！！！"<<endl;
    Tk.Call(1,1)=8;
    Tu.Check();
    Tk.Check();
    Matrix Tr(Tk.Adj());
    Tr.Check();
    Tr=(Tk*2+Tu);
    Tr.Check();*/
    //Matrix Te(0,0);
    //Te=((!Tu)+Tu);
    //Matrix Tr((Tu*Te));
    //Tr.Check();
    //Tu.Check();
    //(~Tu).Check();
    //tt.open("qqqqqqqqqqqqqqqqqq.txt",ios::out);
    return 0;
}
