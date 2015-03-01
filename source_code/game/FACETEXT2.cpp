#include <fstream>
#include <string>
using namespace std;
char tt[]="20120219";
char* Turn(int* Ty)
{
    void* Tem=static_cast<void*>(Ty); 
    char* Tem2=static_cast<char*>(Tem);
    return Tem2;
}
char* Turn(float* Ty)
{
    void* Tem=static_cast<void*>(Ty); 
    char* Tem2=static_cast<char*>(Tem);
    return Tem2;
}
int main()
{
    int Face=1;
    int SizeofFace=(sizeof(int)*2*11+sizeof(float)*11*3*3);
    int Line=11;
    int Mode=1;
    int SizeofLine=sizeof(float)*Line*6;
    void* TY=operator new[](SizeofLine);
    float* Light=static_cast<float*> (TY);
    fstream ty;
    ty.open("TextForFace.bib",ios::out|ios::binary);
    void* Tem;
    char* Tem2;
    ty.write(tt,9);
    
    ty.write(Turn(&Face),sizeof(int));
    //ty.write(Turn(&SizeofFace),sizeof(int));
    
    ty.write(Turn(&Mode),sizeof(int));
    ty.write(Turn(&Line),sizeof(int));
    ty.close();
    for(int i=0;i<Line;++i)
    {
        ty.open("TextForFace.bib",ios::out|ios::binary|ios::app);
        ty.write(Turn(&SizeofLine),sizeof(int));
        ty.write(Turn(&SizeofLine),sizeof(int));
        for(int k=0;k<11;++k)
        {
            *(Light+k*6)=1.0;
            *(Light+k*6+1)=1.0;
            *(Light+k*6+2)=1.0;
            *(Light+k*6+3)=(k-5)*2.0;
            *(Light+k*6+4)=0.0;
            *(Light+k*6+5)=(i-5)*2.0;
        }
        ty.write(Turn(Light),SizeofLine);
        ty.close();
    }
    ty.close();
}
